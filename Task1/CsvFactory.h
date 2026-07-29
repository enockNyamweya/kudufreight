#ifndef CSVFACTORY_H
#define CSVFACTORY_H

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include "ConnectorFactory.h"

class CsvFactory: public ConnectorFactory{
    public:
        Connector* createConnector();
};

#endif