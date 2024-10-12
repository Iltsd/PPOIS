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
			std::cout << "������� ���������: ";
			std::string str;
			std::cin >> std::ws;
			getline(std::cin, str);
			if (enoughBrackets(str))
			{
				mas.push_back(std::make_shared<Multiset>(str));
				mas.back()->uniqueSubsets();
			}
			else std::cout << "��������� �������� �����������, ��������� ������������� '}'\n";
			break;
		}
		case '2':
		{
			if (!mas.empty())
			{
				for (int i = 0;i < mas.size();i++)
				{
					std::cout << i + 1 << " ���������\n";
					mas[i]->print();
				}
			}
			else std::cout << "�� ������ ��������� �� ������" << "\n";
			break;
		}
		case '3':
		{
			std::cout << "������ ������� ������� ��� ������������?\n" << "1-�������\n" << "2-������������\n";
			switch (_getch())
			{
			case '1':
			{
				int first = 0;
				first = get(mas, first);
				if (first > 0)
				{
					std::string str;
					std::cout << "������� �������: ";
					std::cin >> std::ws;
					getline(std::cin, str);
					mas[first - 1]->add(str[0]);
				}
				break;
			}
			case '2':
			{

				std::string str;
				int first = 0;
				first = get(mas, first);
				std::cout << "������� ����� ���������,��� ������ ���������� �� ��������: ";
				std::cin >> std::ws;
				getline(std::cin, str);
				if (first > 0 && enoughBrackets(str))
				{
					auto temp = std::make_shared<Multiset>(str);
					mas[first - 1]->add(temp);
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
			std::cout << "������ ������� �������� ��� ������������?\n" << "1-�������\n" << "2-������������\n";
			switch (_getch())
			{
			case '1':
			{

				int first = 0;
				first = get(mas, first);
				if (first > 0)
				{
					std::string str;
					std::cout << "������� �������: ";
					std::cin >> std::ws;
					getline(std::cin, str);
					mas[first - 1]->remove(str[0]);
				}
				break;
			}
			case '2':
			{
				std::string str;
				int first = 0;
				first = get(mas, first);
				std::cout << "������� ������������. ������������ ���������� �� ��������: ";
				std::cin >> std::ws;
				getline(std::cin, str);
				if (first > 0 && enoughBrackets(str))
				{
					auto temp = std::make_shared<Multiset>(str);
					mas[first - 1]->remove(temp);
				}
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
				std::cout << "��������� ���������� �������� ��� �������� ��� " << mas.size() << " ���������\n";
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
				std::cout << "��������� ���������� �������� ��� �������� ��� " << mas.size() << " ���������\n";
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
				std::cout << "��������� ���������� �������� ��� �������� ��� " << mas.size() << " ���������\n";
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
				std::cout << "������� ������ �������� �� ������ �� ���������?\n";
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