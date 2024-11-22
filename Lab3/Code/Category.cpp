#include "Category.h"

std::vector<std::string> Category::categoryNames;

Category::Category()
{
}

void Category::addCategory(std::string newCategoryName)
{
	categoryNames.push_back(newCategoryName);
}

void Category::removeCategory(std::string categoryName)
{
	for (int i = 0;i < categoryNames.size();++i)
	{
		if (categoryNames[i] == categoryName)
		{
			categoryNames.erase(categoryNames.begin() + i);
			break;
		}
	}
}

std::string Category::getProductCategory()
{
	return productCategory;
}

void Category::showAvailableCategories() const
{
	std::cout << "Доступные категории: \n";
	for (int i = 0;i < categoryNames.size();++i)
	{
		std::cout << categoryNames[i] << "\n";
	}
}

void Category::setProductCategory(int number)
{
	if (number >= 0 && number < categoryNames.size())
	{
		productCategory = categoryNames[number];
	}
	else
	{
		std::cerr << "Ошибка: некорректный номер категории.\n";
	}
}
