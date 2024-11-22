#include "Order.h"

Order::Order(Product* product, int numberOfProducts)
{
	this->product = product;
	this->numberOfProducts = numberOfProducts;
}

void Order::showinfo()
{
	std::cout << "���������� � ������:\n";
	std::cout << "�������: " << product->getName() << " x " << numberOfProducts << "\n";
}
