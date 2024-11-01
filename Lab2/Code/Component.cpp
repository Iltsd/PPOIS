#include "Component.h"

Component::Component() {}
Component::Component(std::string name)
{
	this->name = name;
}
std::string Component::getName()
{
	return name;
}


void Component::print() const
{
	std::cout << name << std::endl;
}


