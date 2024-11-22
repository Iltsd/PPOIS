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
	std::cout << "�������� ��������� � ������ ID �� ������\n";
	return nullptr;
}

Worker* Warehouse::getWorker(int number)
{
	for (auto worker : workers)
	{
		if (worker->getWorkerID() == number) return worker;
	}
	std::cout << "�������� � ������ ID �� ������\n";
	return nullptr;
}

void Warehouse::showAvailableStorages()
{
	for (auto storage : storageAreas)
	{
		if (storage->isAvailable()) std::cout << "�������� ��������� � ID" << storage->getID() << "��������";
		else std::cout << "�������� ��������� � ID" << storage->getID() << "������";
	}
}

void Warehouse::warehouseInfo()
{
	std::cout << "�����:" << this->getName() << " ��������: " << this->storageAreas.size() << "�������� ��������� � " << this->workers.size() << "�����������\n";
	std::cout << "������ ���� �����������:\n";
	for (auto worker : workers)
	{
		std::cout << worker->getWorkerID() << std::endl;
	}

}
