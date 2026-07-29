#ifndef RESTAPIFACTORY_H
#define RESTAPIFACTORY_H

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include "ConnectorFactory.h"

class RestApiFactory: public ConnectorFactory{
    public:
        Connector* createConnector();
};

#endif