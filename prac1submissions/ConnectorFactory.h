#ifndef CONNECTORFACTORY_H
#define CONNECTORFACTORY_H

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include "Connector.h"

class ConnectorFactory {
    public:
        virtual Connector* createConnector() =0;
        virtual ~ConnectorFactory();
};

#endif