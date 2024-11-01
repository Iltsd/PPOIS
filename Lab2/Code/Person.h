#pragma once
#include <iostream>
#include <string>
#include <vector>

class Person
{
protected:

	std::string name;
public:
	Person();

	Person(std::string name);

	std::string getName();

	void setName(std::string name);
};

