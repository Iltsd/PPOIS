#pragma once
#include "Product.h"
class Order
{
protected:
	Product* product;
	int numberOfProducts;
public:
	Order(Product* product, int numberOfProducts);
	void showinfo();
};

