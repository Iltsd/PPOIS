#pragma once
#include <string>
#include <iostream>
class Auditorium
{
protected:
	std::string number;
	int academicBuilding;
public:
	Auditorium(std::string number, int building);
	void print();
};

