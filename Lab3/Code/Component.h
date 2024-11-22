#pragma once
#include <iostream>
#include <string>
class Component
{
protected:
	std::string name;
	int ID;
public:
	Component();
	Component(int ID, std::string name="Not Defined");

	virtual std::string getName() const;
	virtual int getID() const;

	virtual void setName(std::string name);
	virtual void changeID(int ID);

};

