#include "Delivery.h"

Delivery::Delivery(TransportUnit* transport, std::string deliveryTime, Worker* driver)
{
	this->transport = transport;
	this->deliveryTime = deliveryTime;
	this->driver = driver;
}

void Delivery::ShowInfo()
{
	std::cout << "Заказ будет доставлен до%" << deliveryTime << "\n Транспорт: "<< transport->getName() << "\nID Водителя: "<< driver->getWorkerID() << std::endl;
}
