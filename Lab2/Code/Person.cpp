#include "Person.h"

Person::Person()
{
}

Person::Person(std::string name)
{
	this->name = name;
}

std::string Person::getName()
{
	return name;
}

void Person::setName(std::string name)
{
	this->name = name;
}

