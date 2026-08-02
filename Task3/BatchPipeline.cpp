#include "BatchPipeline.h"
#include "../Task1/ConnectorFactory.h"
#include "../Task1/Connector.h"
#include <iostream>

BatchPipeline::BatchPipeline(ConnectorFactory* factory) : Pipeline(factory) {}

void BatchPipeline::extract() {
    if (factory != nullptr) {
        Connector* conn = factory->createConnector();
        if (conn != nullptr) {
            records = conn->extract();
            delete conn;
        }
    }
    std::cout << "Batch extract: " << records.size() << " records" << std::endl;
    stage = 2;
}

void BatchPipeline::load() {
    std::cout << "Batch load: " << records.size() << " records written" << std::endl;
    stage = 4;
}
