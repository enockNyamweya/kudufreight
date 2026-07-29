#include "DeduplicateStep.h"

DeduplicateStep::DeduplicateStep(std::string name) : Transformation(name) {

}

Transformation* DeduplicateStep::clone() {
    return new DeduplicateStep(this->name);
}

std::vector<std::string> DeduplicateStep::apply(std::vector<std::string> records) {
    return records;
}
