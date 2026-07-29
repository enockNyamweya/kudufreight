#include "AggregateByRegionStep.h"

AggregateByRegionStep::AggregateByRegionStep(std::string name) : Transformation(name) {

}

Transformation* AggregateByRegionStep::clone() {
    return new AggregateByRegionStep(this->name);
}

std::vector<std::string> AggregateByRegionStep::apply(std::vector<std::string> records) {
    std::vector<std::string> result;
    result.push_back("COUNT=" + std::to_string(records.size()));
    return result;
}
