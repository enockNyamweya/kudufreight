#ifndef CSVCONNECTOR_H
#define CSVCONNECTOR_H

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include "Connector.h"

class CsvConnector: public Connector{
    public:
        CsvConnector() : Connector("csv") {}
        std::vector<std::string> extract() override;
};

#endif