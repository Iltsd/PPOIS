#include "Cathedra.h"

Cathedra::Cathedra(std::string name, std::string cathedraHeadName)
{
	this->name = name;
	this->faculty = nullptr;
	cathedraHead = new Person(cathedraHeadName);
}

std::string Cathedra::getname()
{
	return this->name;
}

void Cathedra::setCathedraHead(std::string name)
{
	this->cathedraHead->setName(name);
}

void Cathedra::addComponent(Faculty* faculty)
{
	this->faculty = faculty;
}

void Cathedra::removeFaculty()
{
	this->faculty = nullptr;
}

Faculty* Cathedra::getFaculty()
{
	return faculty;
}

void Cathedra::print() const
{
	std::cout << "Кафедра: " << name << std::endl;
	std::cout << "Глава кафедры: " << cathedraHead->getName() << std::endl;
	std::cout << "Факультет: " << faculty->getName() << std::endl;
}

