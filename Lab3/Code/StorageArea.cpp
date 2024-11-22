#include "StorageArea.h"

StorageArea::StorageArea(int ID, std::string name, int maxNumberOfProducts)
{
	this->name = name;
	this->ID = ID;
	this->maxNumberOfProducts = maxNumberOfProducts;
}

void StorageArea::addPoduct(Product* product)
{
	this->products.push_back(product);
}

void StorageArea::removeProduct(int productID)
{
	for (int i = 0;i < products.size();++i)
	{
		if (products[i]->getID() == productID)
		{
			products.erase(products.begin() + i);
		}
	}
}

bool StorageArea::isAvailable()
{
	if (products.size() < maxNumberOfProducts) return 1;
	else return 0;
}

std::vector<Product*> StorageArea::getProducts()
{
	return products;
}
