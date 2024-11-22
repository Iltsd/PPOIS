#include "Order.h"

Order::Order(Product* product, int numberOfProducts)
{
	this->product = product;
	this->numberOfProducts = numberOfProducts;
}

void Order::showinfo()
{
	std::cout << "Информация о заказе:\n";
	std::cout << "Продукт: " << product->getName() << " x " << numberOfProducts << "\n";
}
