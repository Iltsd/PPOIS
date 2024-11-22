#include "TransportUnit.h"

TransportUnit::TransportUnit(std::string mark, int transportID, int numberOfPlaces, float maxPlacementWeight)
{
	this->name = mark;
	this->ID = transportID;
	this->numberOfPlaces = numberOfPlaces;
	this->maxPlacementWeight = maxPlacementWeight;
	this->holdingWeight = 0;
}

void TransportUnit::putProduct(Product* product, int numberOfProducts)
{
	this->holdingProducts[product]+=numberOfProducts;
	holdingWeight += product->getWeight() * numberOfProducts;
}

float TransportUnit::getHoldingWeight()
{
	return holdingWeight;
}
