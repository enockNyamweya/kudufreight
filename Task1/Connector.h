#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <vector>
#include <string>
#include <iostream>
#include <map>

class Connector{

    protected:
        std::string source;
    public:
        Connector(std::string);
        virtual std::vector<std::string> extract() =0;
        std::string getSource();
        virtual ~Connector();

};

#endif