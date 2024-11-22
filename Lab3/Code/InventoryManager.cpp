#include "InventoryManager.h"

InventoryManager::InventoryManager()
{
}

void InventoryManager::addStorageArea(StorageArea* storageArea)
{
	storages.push_back(storageArea);
}

void InventoryManager::updateProductList()
{
	productList.clear();
	for (auto storage : storages)
	{
		for (auto product : storage->getProducts())
		{
			productList.push_back(product);
		}
	}
}

void InventoryManager::info()
{
	std::cout << "Список продуктов на складах:\n";
	for (int i = 0;i < productList.size();++i)
	{
		std::cout << productList[i]->getName() << std::endl;
	}
}

int InventoryManager::getNumberOfStorageAreas()
{
	return storages.size();
}
