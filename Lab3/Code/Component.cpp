#include "Component.h"
Component::Component() {};

Component::Component(int ID, std::string name)
{
	this->ID = ID;
	this->name = name;
}

std::string Component::getName() const
{
	return name;
}

int Component::getID() const
{
	return ID;
}

void Component::setName(std::string name)
{
	this->name = name;
}

void Component::changeID(int ID)
{
	this->ID = ID;
}
