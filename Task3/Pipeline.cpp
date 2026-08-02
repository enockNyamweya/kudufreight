#include "Pipeline.h"
#include "../Task1/ConnectorFactory.h"
#include "../Task1/Connector.h"
#include "../Task2/Transformation.h"
#include "../Task4/RunCheckpoint.h"
#include <iostream>

Pipeline::Pipeline(ConnectorFactory* factory) : factory(factory), stage(0) {}

Pipeline::~Pipeline() {
    delete factory;
    for (Transformation* step : steps) {
        delete step;
    }
    steps.clear();
}

void Pipeline::run() {
    connect();
    extract();
    transform();
    load();
}

void Pipeline::addStep(Transformation* step) {
    if (step != nullptr) {
        steps.push_back(step);
    }
}

void Pipeline::connect() {
    if (factory != nullptr) {
        Connector* conn = factory->createConnector();
        if (conn != nullptr) {
            std::cout << "Connecting to " << conn->getSource() << std::endl;
            delete conn;
        }
    }
    stage = 1;
}

void Pipeline::transform() {
    for (Transformation* step : steps) {
        if (step != nullptr) {
            records = step->apply(records);
        }
    }
    stage = 3;
}

RunCheckpoint* Pipeline::createCheckpoint() {
    return new RunCheckpoint(stage, records);
}

void Pipeline::restore(RunCheckpoint* cp) {
    if (cp != nullptr) {
        stage = cp->getStage();
        records = cp->getRecords();
    }
}
