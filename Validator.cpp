#include "User.h"


int get(std::vector<std::shared_ptr<Multiset>>& mas, int& first, int& second)
{
	if (mas.size() > 1)
	{
		std::cout << "������� ����� 2 ��������: ";
		while (!(std::cin >> first >> second))
		{
			//std::cin >> first;
			std::cin.clear();
			std::cin.ignore(3127, '\n');
			std::cout << "����������� ��������" << "\n";
		}
		//std::cin >> first >> second;
		if ((first - 1 < mas.size() && second - 1 < mas.size() && first > 0 && second > 0) && first != second) return first;
	}
	else std::cout << "������ ����� ���� ��������" << "\n";
	return -1;
}

int get(std::vector<std::shared_ptr<Multiset>>& mas, int first)
{
	if (mas.size() > 0)
	{
		std::cout << "������� ����� ���������: ";
		while (!(std::cin >> first)) 
		{
			//std::cin >> first;
			std::cin.clear();
			std::cin.ignore(3127, '\n');
			std::cout << "����������� ��������" << "\n";
		}
		if (first - 1 < mas.size() && first > 0) return first;
	}
	else std::cout << "�� ������ ��������� �� ������" << "\n";
	return -1;
}

void menu()
{
	std::cout << "������� 1 ����� �������� ���������\n";
	std::cout << "������� 2 ����� ������� ��� ���������\n";
	std::cout << "������� 3 ����� �������� ������� ���������\n";
	std::cout << "������� 4 ����� ��������� ��������� �� ������� ���������\n";
	std::cout << "������� 5 ����� ����� �������� ���������\n";
	std::cout << "������� 6 ����� ������� ������� ���������\n";
	std::cout << "������� 7 ����� **����� ����������� ��������\n";
	std::cout << "������� 8 ����� **����� ����������� ��������\n";
	std::cout << "������� 9 ����� **����� �������� ��������\n";
	std::cout << "������� 0 ����� ����� �� ���������\n";
	std::cout << "������� - ����� ��������� ������� ����� ���� ��������\n";
	std::cout << "������� = ����� ����� ������ ���������\n";


}