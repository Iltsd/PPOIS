#include "User.h"


int get(std::vector<std::shared_ptr<Multiset>>& mas, int& first, int& second)
{
	if (mas.size() > 1)
	{
		std::cout << "Ââåäèòå íîìåð 2 ìíîæåñòâ: ";
		while (!(std::cin >> first >> second))
		{
			//std::cin >> first;
			std::cin.clear();
			std::cin.ignore(3127, '\n');
			std::cout << "Íåêîððåòíîå çíà÷åíèå" << "\n";
		}
		//std::cin >> first >> second;
		if ((first - 1 < mas.size() && second - 1 < mas.size() && first > 0 && second > 0) && first != second) return first;
	}
	else std::cout << "Çàäàíî ìåíåå äâóõ ìíîæåñòâ" << "\n";
	return -1;
}

int get(std::vector<std::shared_ptr<Multiset>>& mas, int first)
{
	if (mas.size() > 0)
	{
		std::cout << "Ââåäèòå íîìåð ìíîæåñòâà: ";
		while (!(std::cin >> first)) 
		{
			//std::cin >> first;
			std::cin.clear();
			std::cin.ignore(3127, '\n');
			std::cout << "Íåêîððåòíîå çíà÷åíèå" << "\n";
		}
		if (first - 1 < mas.size() && first > 0) return first;
	}
	else std::cout << "Íè îäíîãî ìíîæåñòâà íå çàäàíî" << "\n";
	return -1;
}

void menu()
{
	std::cout << "Ââåäèòå 1 ÷òîáû äîáàâèòü ìíîæåñòâî\n";
	std::cout << "Ââåäèòå 2 ÷òîáû âûâåñòè âñå ìíîæåñòâà\n";
	std::cout << "Ââåäèòå 3 ÷òîáû äîáàâèòü ýëåìåíò ìíîæåñòâà\n";
	std::cout << "Ââåäèòå 4 ÷òîáû ïðîâåðèòü ìíîæåñòâî íà íàëè÷èå ýëåìåíòîâ\n";
	std::cout << "Ââåäèòå 5 ÷òîáû íàéòè ìîùíîñòü ìíîæåñòâà\n";
	std::cout << "Ââåäèòå 6 ÷òîáû óäàëèòü ýëåìåíò ìíîæåñòâà\n";
	std::cout << "Ââåäèòå 7 ÷òîáû **íàéòè îáúåäèíåíèå ìíîæåñòâ\n";
	std::cout << "Ââåäèòå 8 ÷òîáû **íàéòè ïåðåñå÷åíèå ìíîæåñòâ\n";
	std::cout << "Ââåäèòå 9 ÷òîáû **íàéòè ðàçíîñòü ìíîæåñòâ\n";
	std::cout << "Ââåäèòå 0 ÷òîáû âûéòè èç ïðîãðàììû\n";
	std::cout << "Ââåäèòå - ÷òîáû ïðîâåðèòü íàëè÷èå êàîãî ëèáî ýëåìåíòà\n";
	std::cout << "Ââåäèòå = ÷òîáû íàéòè áóëåàí ìíîæåñòâà\n";


}
