#pragma once
#include <vector>
#include "StorageArea.h"
class InventoryManager
{
protected:
	std::vector<StorageArea*> storages;
	std::vector<Product*> productList;
public:
	InventoryManager();
	void addStorageArea(StorageArea* storageArea);
	void updateProductList();
	void info();

	int getNumberOfStorageAreas();
};

