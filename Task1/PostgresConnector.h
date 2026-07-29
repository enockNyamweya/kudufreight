#ifndef POSTGRESCONNECTOR_H
#define POSTGRESCONNECTOR_H

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include "Connector.h"

class PostgresConnector: public Connector{
    public:
        std::vector<std::string> extract();
};

#endif