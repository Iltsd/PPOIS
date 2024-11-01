#pragma once
#include <string>
#include <iostream>
#include <vector>

class Component
{
protected:
	std::string name;

public:
	Component(std::string name);
	Component();

	virtual std::string getName();
	virtual void print() const;
};


