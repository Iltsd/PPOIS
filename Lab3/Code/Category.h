#pragma once
#include <iostream>
#include <string>
#include <vector>

class Category
{
protected:
	static std::vector<std::string> categoryNames;
	std::string productCategory;
public:
	Category();
	static void addCategory(std::string newCategoryName);
	static void removeCategory(std::string categoryName);
	std::string getProductCategory();
	void showAvailableCategories() const ;
	void setProductCategory(int number);

	
};

