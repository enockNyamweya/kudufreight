#include <iostream>

#include "../Task1/PostgresFactory.h"
#include "../Task1/RestApiFactory.h"
#include "../Task1/CsvFactory.h"
#include "../Task2/TransformationRegistry.h"
#include "../Task2/DeduplicateStep.h"
#include "../Task2/AggregateByRegionStep.h"
#include "../Task3/BatchPipeline.h"
#include "../Task3/StreamingPipeline.h"
#include "../Task4/CheckpointManager.h"
#include "../Task4/RunCheckpoint.h"

int main() {
    // =========================================================
    // Task 5 Required Workflow (Steps 1–6)
    // =========================================================

    // 1. Create a TransformationRegistry and register a DeduplicateStep under "dedup" and an AggregateByRegionStep under "aggregate"
    TransformationRegistry* registry = new TransformationRegistry();
    registry->registerStep("dedup", new DeduplicateStep("dedup"));
    registry->registerStep("aggregate", new AggregateByRegionStep("aggregate"));

    // 2. Create a BatchPipeline with a PostgresFactory
    PostgresFactory* factory = new PostgresFactory();
    BatchPipeline* pipeline = new BatchPipeline(factory);

    // 3. Add a cloned "dedup" step then a cloned "aggregate" step, both from the registry (never constructed directly)
    Transformation* step1 = registry->create("dedup");
    Transformation* step2 = registry->create("aggregate");
    pipeline->addStep(step1);
    pipeline->addStep(step2);

    // 4. Create a CheckpointManager
    CheckpointManager* manager = new CheckpointManager();

    // 5. Call run(), then createCheckpoint() and save() the result
    pipeline->run();
    RunCheckpoint* cp = pipeline->createCheckpoint();
    manager->save(cp);

    // 6. Delete everything you own so the program is leak-free
    delete cp;       // Memento owned by client (Caretaker aggregation)
    delete pipeline; // Pipeline owns and deletes factory, step1, step2
    delete manager;

    // =========================================================
    // FitchFork Automated Test & Coverage Suite (>80% Target)
    // =========================================================

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
