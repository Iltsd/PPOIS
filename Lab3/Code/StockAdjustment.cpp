#include "StockAdjustment.h"

StockAdjustment::StockAdjustment()
{
}

void StockAdjustment::addStorageArea(StorageArea* storage)
{
	storageArea.push_back(storage);
}


void StockAdjustment::deleteExpiredProducts()
{
	for (auto storage : storageArea)
	{
		for (auto product : storage->getProducts())
		{
			if (product->getDate() > dateToString())
				storage->removeProduct(product->getID());
			std::cout << "Просроченный продукт удалён\n";
		}
	}
}

std::string dateToString()
{
	std::time_t time = std::time(nullptr);
	std::tm tmStruct;
	if (localtime_s(&tmStruct, &time) != 0) {
		return "Ошибка преобразования времени";
	}


	char* currentTime = new char[50];
	if (std::strftime(currentTime, sizeof(currentTime), "%Y.%m.%d", &tmStruct)) return std::string(currentTime);
	else
	{
		return "Error";
	}

}
