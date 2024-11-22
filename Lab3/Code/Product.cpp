#include "Product.h"

Product::Product(std::string name, int ID, float weight)
{
    this->name = name;
    this->ID = ID;
    this->weight = weight;
}

float Product::getWeight()
{
    return weight;
}

std::string Product::getDate()
{
    return date;
}

void Product::setDate(std::string date)
{
    this->date = date;
}
