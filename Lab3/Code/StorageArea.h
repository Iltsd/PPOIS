#pragma once
#include "Product.h"
#include "Component.h"
#include <vector>
#include <string>
class StorageArea : public Component
{
protected:
	int maxNumberOfProducts;
	std::vector<Product*> products;

public:
	StorageArea(int ID, std::string name = "Not Defined", int maxNumberOfProducts=50);
	void addPoduct(Product* product);
	void removeProduct(int productID);
	bool isAvailable();
	std::vector<Product*> getProducts();
	

};

