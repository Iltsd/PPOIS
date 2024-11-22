#include "Delivery.h"

Delivery::Delivery(TransportUnit* transport, std::string deliveryTime, Worker* driver)
{
	this->transport = transport;
	this->deliveryTime = deliveryTime;
	this->driver = driver;
}

void Delivery::ShowInfo()
{
	std::cout << "����� ����� ��������� ��%" << deliveryTime << "\n ���������: "<< transport->getName() << "\nID ��������: "<< driver->getWorkerID() << std::endl;
}
