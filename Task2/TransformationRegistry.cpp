#include "TransformationRegistry.h"

void TransformationRegistry::registerStep(std::string key, Transformation* prototype) {

}

Transformation* TransformationRegistry::create(std::string key) {
    return nullptr;
}

TransformationRegistry::~TransformationRegistry() {

}
