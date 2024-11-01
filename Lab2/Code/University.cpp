#include "University.h"


University::University(std::string uniName, std::string directorName)
{
	this->name = uniName;
	director = new Person(directorName);
}

void University::addComponent(Cathedra* cathedra)
{
	cathedras.push_back(cathedra);
}

void University::setDirector(std::string name)
{
	this->director->setName(name);
}

void University::removeCathedra(int num)
{
	if (num > cathedras.size() || num < 0) return;
	cathedras.erase(cathedras.begin() + num);
}

std::string University::getName()
{
	return director->getName();
}

std::vector<Cathedra*> University::getCathedra() const
{
	return cathedras;
}

void University::print() const
{
	
	std::cout << "Унивеситет: " << name << std::endl;
	std::cout << "Директор: " << director->getName() << std::endl;
	for (int i = 0;i < cathedras.size();++i)
	{
		std::cout << cathedras[i]->getname() << std::endl;
	}
}