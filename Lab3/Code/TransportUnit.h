#pragma once
#include "Component.h"
#include "Product.h"
#include <map>
class TransportUnit : public Component
{
protected:
	float numberOfPlaces;
	float maxPlacementWeight;
	float holdingWeight;
	bool isFree;
	std::map<Product*, int> holdingProducts;
public:
	TransportUnit(std::string mark, int transportID, int numberOfPlaces, float maxPlacementWeight);
	void putProduct(Product* product, int numberOfProducts);
	float getHoldingWeight();

};

