#ifndef CSVCONNECTOR_H
#define CSVCONNECTOR_H

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include "Connector.h"

class CsvConnector: public Connector{
    public:
        std::vector<std::string> extract();
};

#endif