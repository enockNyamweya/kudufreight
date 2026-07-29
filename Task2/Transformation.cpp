#include "Transformation.h"

Transformation::Transformation(std::string name) {
    this->name = name;
}

std::string Transformation::getName() {
    return this->name;
}

Transformation::~Transformation() {

}
