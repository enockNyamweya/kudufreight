#ifndef AGGREGATEBYREGIONSTEP_H
#define AGGREGATEBYREGIONSTEP_H

#include "Transformation.h"
#include <string>
#include <vector>

class AggregateByRegionStep : public Transformation {
public:
    AggregateByRegionStep(std::string name);
    Transformation* clone() override;
    std::vector<std::string> apply(std::vector<std::string> records) override;
};

#endif
