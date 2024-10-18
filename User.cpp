#include "User.h"
#include "User.h"


int get(std::vector<std::shared_ptr<Multiset>>& mas, int& first, int& second)
{
	if (mas.size() > 1)
	{
		std::cout << "Введите номер 2 множеств: ";
		while (!(std::cin >> first >> second))
		{
			//std::cin >> first;
			std::cin.clear();
			std::cin.ignore(3127, '\n');
			std::cout << "Некорретное значение" << "\n";
		}
		//std::cin >> first >> second;
		if ((first - 1 < mas.size() && second - 1 < mas.size() && first > 0 && second > 0) && first != second) return first;
	}
	else std::cout << "Задано менее двух множеств" << "\n";
	return -1;
}

int get(std::vector<std::shared_ptr<Multiset>>& mas, int first)
{
	if (mas.size() > 0)
	{
		std::cout << "Введите номер множества: ";
		while (!(std::cin >> first)) 
		{
			//std::cin >> first;
			std::cin.clear();
			std::cin.ignore(3127, '\n');
			std::cout << "Некорретное значение" << "\n";
		}
		if (first - 1 < mas.size() && first > 0) return first;
	}
	else std::cout << "Ни одного множества не задано" << "\n";
	return -1;
}

void menu()
{
	std::cout << "Введите 1 чтобы добавить множество\n";
	std::cout << "Введите 2 чтобы вывести все множества\n";
	std::cout << "Введите 3 чтобы добавить элемент множества\n";
	std::cout << "Введите 4 чтобы проверить множество на наличие элементов\n";
	std::cout << "Введите 5 чтобы найти мощность множества\n";
	std::cout << "Введите 6 чтобы удалить элемент множества\n";
	std::cout << "Введите 7 чтобы **найти объединение множеств\n";
	std::cout << "Введите 8 чтобы **найти пересечение множеств\n";
	std::cout << "Введите 9 чтобы **найти разность множеств\n";
	std::cout << "Введите 0 чтобы выйти из программы\n";
	std::cout << "Введите - чтобы проверить наличие каого либо элемента\n";
	std::cout << "Введите = чтобы найти булеан множества\n";


}