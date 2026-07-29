#include "DeduplicateStep.h"

DeduplicateStep::DeduplicateStep(std::string name) : Transformation(name) {

}

Transformation* DeduplicateStep::clone() {
    return new DeduplicateStep(this->name);
}

std::vector<std::string> DeduplicateStep::apply(std::vector<std::string> records) {
    if (records.empty()) return records;
    std::vector<std::string> result;
    result.push_back(records[0]);
    for (size_t i = 1; i < records.size(); ++i) {
        if (records[i] != records[i-1]) {
            result.push_back(records[i]);
        }
    }
    return result;
}
