#include "StreamingPipeline.h"
#include "../Task1/ConnectorFactory.h"
#include "../Task1/Connector.h"
#include <iostream>

StreamingPipeline::StreamingPipeline(ConnectorFactory* factory) : Pipeline(factory) {}

void StreamingPipeline::extract() {
    if (factory != nullptr) {
        Connector* conn = factory->createConnector();
        if (conn != nullptr) {
            records = conn->extract();
            delete conn;
        }
    }
    std::cout << "Streaming extract: " << records.size() << " records" << std::endl;
    stage = 2;
}

void StreamingPipeline::load() {
    std::cout << "Streaming load: " << records.size() << " records streamed" << std::endl;
    stage = 4;
}
