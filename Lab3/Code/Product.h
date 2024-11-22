#pragma once
#include "Component.h"
#include "Category.h"
class Product : public Component
{
protected:
	float weight;
	float volume;
	std::string date;
	Category* category;
public:
	using Component::Component;
	Product(std::string name, int ID, float weight);
	float getWeight();
	std::string getDate();
	void setDate(std::string date);
};

