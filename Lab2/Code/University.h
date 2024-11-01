#pragma once
#include "Cathedra.h"
class University : public Component
{
protected:
	std::vector<Cathedra*> cathedras;
	Person* director;
public:
	University(std::string uniName, std::string directorName = "Не определён");

	void addComponent(Cathedra* cathedra);

	void setDirector(std::string name);

	void removeCathedra(int num);

	std::string getName() override;

	std::vector<Cathedra*> getCathedra() const;

	void print() const override;
};

