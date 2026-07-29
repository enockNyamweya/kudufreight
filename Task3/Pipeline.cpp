#include "Pipeline.h"
#include "ConnectorFactory.h"
#include "Transformation.h"
#include "RunCheckpoint.h"

Pipeline::Pipeline(ConnectorFactory* factory) {

}

void Pipeline::run() {

}

void Pipeline::addStep(Transformation* step) {

}

void Pipeline::connect() {

}

void Pipeline::transform() {

}

RunCheckpoint* Pipeline::createCheckpoint() {
    return nullptr;
}

void Pipeline::restore(RunCheckpoint* cp) {

}

Pipeline::~Pipeline() {

}
