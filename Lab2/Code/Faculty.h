#pragma once
#include "Speciality.h"
#include <vector>
class Faculty : Component
{
protected:
	Person* dean;
	std::vector<Speciality*> specialities;
public:
	Faculty(std::string name, std::string deanName = "Не оперделён");
	void setDean(std::string deanName);

	void addComponent(Speciality* speciality);
	void removeSpeciality(int num);

	std::string getName() override;
	std::vector<Speciality*> getSpecialities() const;

	void addComponent(std::string name);
	void print() const override;

};

