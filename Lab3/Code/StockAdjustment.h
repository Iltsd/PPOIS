#pragma once
#include "InventoryManager.h"

#include <ctime>
class StockAdjustment
{
protected:
	std::vector<StorageArea*> storageArea;
public:
	StockAdjustment();
	void addStorageArea(StorageArea* storage);
	void deleteExpiredProducts();
};

std::string dateToString();

