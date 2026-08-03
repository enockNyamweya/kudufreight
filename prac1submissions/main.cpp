#include <iostream>

#include "PostgresFactory.h"
#include "RestApiFactory.h"
#include "CsvFactory.h"
#include "TransformationRegistry.h"
#include "DeduplicateStep.h"
#include "AggregateByRegionStep.h"
#include "BatchPipeline.h"
#include "StreamingPipeline.h"
#include "CheckpointManager.h"
#include "RunCheckpoint.h"

int main() {

    // 1. Creating a TransformationRegistry and registering a DeduplicateStep under "dedup" and an AggregateByRegionStep under "aggregate"
    TransformationRegistry* registry = new TransformationRegistry();
    registry->registerStep("dedup", new DeduplicateStep("dedup"));
    registry->registerStep("aggregate", new AggregateByRegionStep("aggregate"));

    // 2. Creating a BatchPipeline with a PostgresFactory
    PostgresFactory* factory = new PostgresFactory();
    BatchPipeline* pipeline = new BatchPipeline(factory);

    // 3. Adding a cloned "dedup" step then a cloned "aggregate" step, both from the registry
    Transformation* step1 = registry->create("dedup");
    Transformation* step2 = registry->create("aggregate");
    pipeline->addStep(step1);
    pipeline->addStep(step2);

    // 4. Creating a CheckpointManager
    CheckpointManager* manager = new CheckpointManager();

    // 5. Calling run(), then createCheckpoint() and save() the result
    pipeline->run();
    RunCheckpoint* cp = pipeline->createCheckpoint();
    manager->save(cp);

    // 6. Delete everything you own so the program is leak-free
    delete cp;       // Memento owned by client (Caretaker aggregation)
    delete pipeline; // Pipeline owns and deletes factory, step1, step2
    delete manager;

    // Test RestApiFactory and StreamingPipeline
    RestApiFactory* restFactory = new RestApiFactory();
    StreamingPipeline* streamPipeline = new StreamingPipeline(restFactory);
    streamPipeline->addStep(registry->create("dedup"));
    streamPipeline->addStep(nullptr);
    streamPipeline->run();

    CheckpointManager* manager2 = new CheckpointManager();
    RunCheckpoint* streamCp = streamPipeline->createCheckpoint();
    manager2->save(streamCp);

    (void)streamCp->getStage();
    (void)streamCp->getRecords();

    RunCheckpoint* poppedCp = manager2->undo();
    if (poppedCp) {
        streamPipeline->restore(poppedCp);
    }
    streamPipeline->restore(nullptr);
    delete streamCp;

    RunCheckpoint* emptyCp = manager2->undo();
    (void)emptyCp;

    delete streamPipeline;
    delete manager2;

    // Test CsvFactory and CsvConnector
    CsvFactory* csvFactory = new CsvFactory();
    BatchPipeline* csvPipeline = new BatchPipeline(csvFactory);
    csvPipeline->run();
    delete csvPipeline;

    // Test TransformationRegistry step overwrite and invalid key lookup
    registry->registerStep("dedup", new DeduplicateStep("dedup"));
    Transformation* missingStep = registry->create("unknown_key");
    (void)missingStep;

    // Test DeduplicateStep empty records edge case
    Transformation* dedupEdge = registry->create("dedup");
    if (dedupEdge) {
        std::vector<std::string> emptyResult = dedupEdge->apply({});
        (void)emptyResult;
        (void)dedupEdge->getName();
        delete dedupEdge;
    }

    delete registry;

    return 0;
}
