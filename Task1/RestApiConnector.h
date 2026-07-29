#ifndef RESTAPICONNECTOR_H
#define RESTAPICONNECTOR_H

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include "Connector.h"

class RestApiConnector: public Connector{
    public:
        std::vector<std::string> extract();
};

#endif