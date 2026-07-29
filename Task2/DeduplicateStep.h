#ifndef DEDUPLICATESTEP_H
#define DEDUPLICATESTEP_H

#include "Transformation.h"
#include <string>
#include <vector>

class DeduplicateStep : public Transformation {
public:
    DeduplicateStep(std::string name);
    Transformation* clone() override;
    std::vector<std::string> apply(std::vector<std::string> records) override;
};

#endif
