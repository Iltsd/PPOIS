#pragma once
#include "Component.h"
#include <vector>
#include "Worker.h"
#include "StorageArea.h"

class Warehouse : public Component
{
protected:
	std::vector<StorageArea*> storageAreas;
	std::vector<Worker*> workers;
public:
	using Component::Component;

	void addStorageArea(StorageArea* storageArea);
	void addWorker(Worker* worker);

	StorageArea* getStorageArea(int storageID);
	Worker* getWorker(int number);

	void showAvailableStorages();
	void warehouseInfo();

	

};

