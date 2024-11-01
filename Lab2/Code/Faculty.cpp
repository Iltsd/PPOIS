#include "Faculty.h"

Faculty::Faculty(std::string name, std::string deanName)
{
	this->name = name;
	this->dean = new Person(deanName);
}

void Faculty::setDean(std::string deanName)
{
	this->dean->setName(deanName);
}

void Faculty::addComponent(Speciality* speciality)
{
	specialities.push_back(speciality);
}

void Faculty::removeSpeciality(int num)
{
	if (num > specialities.size() || num < 0) return;
	specialities.erase(specialities.begin() + num);
}

std::string Faculty::getName()
{
	return name;
}

std::vector<Speciality*> Faculty::getSpecialities() const
{
	return specialities;
}

void Faculty::addComponent(std::string name)
{
	this->specialities.push_back(new Speciality(name));
}

void Faculty::print() const
{
	std::cout << "Факультет: " << name << std::endl;
	std::cout << "Декан факультета: " << dean->getName() << std::endl;
	std::cout << "Специальности: " << std::endl;
	for (auto special : specialities)
	{
		std::cout << special->getName() << std::endl;
	}
}
