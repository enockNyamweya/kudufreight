#ifndef POSTGRESFACTORY_H
#define POSTGRESFACTORY_H

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include "ConnectorFactory.h"

class PostgresFactory: public ConnectorFactory{
    public:
        Connector* createConnector() override;
};

#endif