#include "Warehouse.h"

void Warehouse::addStorageArea(StorageArea* storageArea)
{
	this->storageAreas.push_back(storageArea);
}

void Warehouse::addWorker(Worker* worker)
{
	this->workers.push_back(worker);
}

StorageArea* Warehouse::getStorageArea(int storageID)
{
	for (auto storage : storageAreas)
	{
		if (storage->getID() == storageID) return storage;
	}
	std::cout << "Складное помещение с данным ID не найден\n";
	return nullptr;
}

Worker* Warehouse::getWorker(int number)
{
	for (auto worker : workers)
	{
		if (worker->getWorkerID() == number) return worker;
	}
	std::cout << "Работние с данным ID не найден\n";
	return nullptr;
}

void Warehouse::showAvailableStorages()
{
	for (auto storage : storageAreas)
	{
		if (storage->isAvailable()) std::cout << "Складное помещение с ID" << storage->getID() << "Свободно";
		else std::cout << "Складное помещение с ID" << storage->getID() << "Занято";
	}
}

void Warehouse::warehouseInfo()
{
	std::cout << "Склад:" << this->getName() << " содержит: " << this->storageAreas.size() << "складынх помещений и " << this->workers.size() << "сотрудников\n";
	std::cout << "Список всех сотрудников:\n";
	for (auto worker : workers)
	{
		std::cout << worker->getWorkerID() << std::endl;
	}

}
