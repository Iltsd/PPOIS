#include "Multiset.h"
#include "User.h"


int main()
{
	setlocale(LC_ALL, "RU");
	std::vector <std::shared_ptr<Multiset>> mas;
	while (true)
	{
		menu();
		switch (_getch())
		{
		case '1':
		{
			std::cout << "Введите множество: ";
			std::string str;
			std::cin >> std::ws;
			getline(std::cin, str);
			//char* str = new char[100];
			//std::cin >> str;
			if (enoughBrackets(str))
			{
				mas.push_back(std::make_shared<Multiset>(str));
				mas.back()->uniqueSubsets();
			}
			else std::cout << "Множество записано некорректно, проверьте достаточность '}'\n";
			break;
		}
		case '2':
		{
			if (!mas.empty())
			{
				for (int i = 0;i < mas.size();i++)
				{
					std::cout << i + 1 << " Множество\n";
					mas[i]->print();
				}
			}
			else std::cout << "Ни одного множества не задано" << "\n";
			break;
		}
		case '3':
		{
			std::cout << "Хотите добавть элемент или полмножество?\n" << "1-Элемент\n" << "2-Подмножество\n";
			switch (_getch())
			{
			case '1':
			{
				int first = 0;
				first = get(mas, first);
				if (first > 0)
				{
					std::string str;
					std::cout << "Введите элемент: ";
					std::cin >> std::ws;
					getline(std::cin, str);
					int count = 1;
					std::cout << "Введите количество повторений: " << std::endl;
					std::cin >> count;
					mas[first - 1]->add(str[0], count);
				}
				break;
			}
			case '2':
			{

				std::string str;
				int first = 0;
				first = get(mas, first);
				std::cout << "Введите новое множество,оно должно начинаться со скобочки: ";
				std::cin >> std::ws;
				getline(std::cin, str);
				if (first > 0 && enoughBrackets(str))
				{
					int count = 1;
					std::cout << "Введите количество повторений: " << std::endl;
					std::cin >> count;
					auto temp = std::make_shared<Multiset>(str);
					mas[first - 1]->add(temp,count);
					mas[first - 1]->uniqueSubsets();
				}
				break;
			}
			}
			break;
		}
		case '4':
		{

			int first = 0;
			first = get(mas, first);
			if (first > 0) mas[first - 1]->isEmpty();
			break;
		}
		case '5':
		{
			int first = 0;
			first = get(mas, first);
			if (first > 0) mas[first - 1]->power();
			break;
		}
		case '6':
		{
			std::cout << "Хотите удалить элемента или подмножество?\n" << "1-Элемент\n" << "2-Подмножество\n";
			switch (_getch())
			{
			case '1':
			{

				int first = 0;
				first = get(mas, first);
				if (first > 0 && mas[first - 1]->getElements().size() > 0)
				{
					std::string str;
					std::cout << "Введите элемент: ";
					std::cin >> std::ws;
					getline(std::cin, str);
					mas[first - 1]->remove(str[0]);
				}
				else std::cout << "Некорректное значение\n" << std::endl;
				break;
			}
			case '2':
			{
				std::string str;
				int first = 0;
				first = get(mas, first);
				std::cout << "Введите подмножество. Подмножества начинаются со скобочки: ";
				std::cin >> std::ws;
				getline(std::cin, str);
				str = "{"+ str + "}";
				if (first > 0 && enoughBrackets(str) && mas[first-1]->getSubsets().size()>0)
				{
					auto temp = std::make_shared<Multiset>(str);
					mas[first - 1]->remove(temp);
				}
				else std::cout << "Некорректное значение\n" << std::endl;
				break;
			}

			}
			break;
		case '7':
		{
			int first = 0, second = 0;
			first = get(mas, first, second);
			if (first > 0)
			{
				mas.push_back(std::make_shared<Multiset>());
				*mas.back() = *(mas[first - 1]) + mas[second - 1];
				std::cout << "Результат выполнения операции был добавлен как " << mas.size() << " множество\n";
			}
			break;
		}
		case '8':
		{
			int first = 0, second = 0;
			first = get(mas, first, second);
			if (first > 0)
			{
				mas.push_back(std::make_shared<Multiset>());
				*mas.back() = *mas[first - 1] * mas[second - 1];
				std::cout << "Результат выполнения операции был добавлен как " << mas.size() << " множество\n";
			}
			break;
		}
		case '9':
		{
			int first = 0, second = 0;
			first = get(mas, first, second);
			if (first > 0)
			{
				mas.push_back(std::make_shared<Multiset>(mas[first - 1]));
				*mas.back() = *mas[first - 1] - mas[second - 1];
				std::cout << "Результат выполнения операции был добавлен как " << mas.size() << " множество\n";
			}
			break;
		}
		case '0':
		{
			mas.clear();
			exit(0);
			break;
		}
		case '-':
		{
			int first = 0;
			first = get(mas, first);
			std::string str;
			if (first > 0)
			{
				std::cout << "Наличие какого элемента вы хотели бы проверить?\n";
				std::cin >> std::ws;
				getline(std::cin, str);
				(*mas[first - 1])[str];
			}
			break;
		}
		case '=':
		{
			int first = 0;
			first = get(mas, first);
			std::vector<Multiset> powerSet;
			if (first > 0) powerSet = mas[first - 1]->boolean();
			showPowerSet(powerSet);
			break;
		}
		}
		}
		system("pause");
		system("cls");
	}

	return 0;
}