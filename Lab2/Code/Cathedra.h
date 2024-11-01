#pragma once
#include <string>
#include "Person.h"
#include "Faculty.h"
#include "Component.h"
class Cathedra : public Component
{
protected:
	Person* cathedraHead;
	Faculty* faculty;
public:
	Cathedra(std::string name, std::string cathedraHeadName = "Не назначен");
	std::string getname();

	void setCathedraHead(std::string name);
	void addComponent(Faculty* faculty);
	void removeFaculty();

	Faculty* getFaculty();
	void print() const override;
};

