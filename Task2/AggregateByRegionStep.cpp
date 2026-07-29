#include "AggregateByRegionStep.h"

AggregateByRegionStep::AggregateByRegionStep(std::string name) : Transformation(name) {

}

Transformation* AggregateByRegionStep::clone() {
    return new AggregateByRegionStep(this->name);
}

std::vector<std::string> AggregateByRegionStep::apply(std::vector<std::string> records) {
    return records;
}
