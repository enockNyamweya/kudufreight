#include "Connector.h"

Connector::Connector(std::string src) : source(src){

}

std::string Connector::getSource(){
    return source;
}

Connector::~Connector(){

}