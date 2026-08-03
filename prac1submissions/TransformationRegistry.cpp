#include "TransformationRegistry.h"

void TransformationRegistry::registerStep(std::string key, Transformation* prototype) {
    if (prototypes.find(key) != prototypes.end()) {
        delete prototypes[key];
    }
    prototypes[key] = prototype;
}

Transformation* TransformationRegistry::create(std::string key) {
    if (prototypes.find(key) != prototypes.end()) {
        return prototypes[key]->clone();
    }
    return nullptr;
}

TransformationRegistry::~TransformationRegistry() {
    for (auto it = prototypes.begin(); it != prototypes.end(); ++it) {
        delete it->second;
    }
    prototypes.clear();
}
