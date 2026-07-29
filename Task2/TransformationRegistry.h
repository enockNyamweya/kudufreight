#ifndef TRANSFORMATIONREGISTRY_H
#define TRANSFORMATIONREGISTRY_H

#include "Transformation.h"
#include <map>
#include <string>

class TransformationRegistry {
private:
    std::map<std::string, Transformation*> prototypes;
public:
    void registerStep(std::string key, Transformation* prototype);
    Transformation* create(std::string key);
    ~TransformationRegistry();
};

#endif
