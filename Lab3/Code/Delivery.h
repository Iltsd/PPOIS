#pragma once
#include "TransportUnit.h"
#include "Worker.h"
class Delivery
{
protected:
	TransportUnit* transport;
	std::string deliveryTime;
	Worker* driver;
public:
	Delivery(TransportUnit* transport, std::string deliveryTime, Worker* driver);
	void ShowInfo();

};

