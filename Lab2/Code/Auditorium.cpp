#include "Auditorium.h"

Auditorium::Auditorium(std::string number, int building)
{
	this->number = number;
	academicBuilding = building;
}

void Auditorium::print()
{
	std::cout << number << "-" << academicBuilding << std::endl;
}
