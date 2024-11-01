//#include "University.h"
//#include "Teacher.h"
//#include "Student.h"
//#include "Speciality.h"
//#include "Schedule.h"
//#include "Person.h"
//#include "Performance.h"
//#include "Lesson.h"
//#include "Group.h"
//#include "Faculty.h"
//#include "examSession.h"
//#include "Exam.h"
//#include "Component.h"
//#include "Cathedra.h"
//#include "Auditorium.h"
//#include <conio.h>
//
//std::string stringValidator()
//{
//	std::string name;
//	std::cin >> std::ws;
//	getline(std::cin, name);
//	return name;
//}
//int intValidator()
//{
//	int value=NULL;
//	std::cout << "������� ��������\n";
//	while (!(std::cin >> value))
//	{
//		std::cin.clear();
//		std::cin.ignore(3127, '\n');
//		std::cerr << "����������� ��������\n";
//	}
//	return value;
//}
//
//void printComponent(std::vector<Cathedra*> component)
//{
//	for (int i = 0;i < component.size();++i)
//	{
//		std::cout << component[i]->getName();
//	}
//}
//
//void menu()
//{
//	std::cout << "�������� 1 ����� ������������� ���������� ������������\n";
//	std::cout << "�������� 2 ����� ������������� ���������� ������\n";
//	std::cout << "�������� 3 ����� ������������� ���������� �����������\n";
//	std::cout << "�������� 4 ����� ������������� ���������� ��������������\n";
//	std::cout << "�������� 5 ����� ������������� ���������� \n";
//	std::cout << "�������� 6 ����� ������������� ����������\n";
//	std::cout << "�������� 7 ����� ������������� ����������\n";
//	std::cout << "�������� 8 ����� ������������� ����������\n";
//	std::cout << "�������� 9 ����� ������� ����������\n";
//	std::cout << "�������� 0 ����� �����\n";
//}
//
//int Main()
//{
//	University* university=nullptr;
//	setlocale(LC_ALL, "RU");
//	while (true)
//	{
//		menu();
//		switch (_getch())
//		{
//		case '1':
//		{
//			std::cout << "�������� 1 ����� ������� �����������\n";
//			std::cout << "�������� 2 ����� ������� ���������\n";
//			switch (_getch())
//			{
//			case '1':
//			{
//				std::cout << "������� �������� ������������: \n";
//				std::string name = stringValidator();
//				university = new University(name);
//				break;
//			}
//			case '2':
//			{
//				std::cout << "������� ��� ���������: \n";
//				university->setDirector(stringValidator());
//				break;
//			}
//			}
//			
//			break;
//		}
//		case'2':
//		{
//			std::cout << "�������� 1 ����� �������� �������\n";
//			std::cout << "�������� 2 ����� ������� ����� �������\n";
//			std::cout << "�������� 3 ������� �������\n";
//			switch (_getch())
//			{
//
//			case '1':
//			{
//				std::cout << "������� �������� �������: \n";
//				std::string name = stringValidator();
//				university->addComponent(name);
//				break;
//			}
//			case '2':
//			{
//				std::cout << "������� ��� ����� �������: \n";
//				std::string name = stringValidator();
//				int num = intValidator();
//				if (num > university->getCathedra().size() || num < 0) break;
//				university->getCathedra()[num-1]->setCathedraHead(name);
//				break;
//			}
//			case '3':
//			{
//				std::cout << "������� ����� �������: \n";
//				int num = intValidator();
//				university->removeCathedra(num-1);
//				break;
//			}
//			}
//			break;
//		}
//		case '3':
//		{
//			std::cout << "�������� 1 ����� �������� ���������\n";
//			std::cout << "�������� 2 ����� ������� ������\n";
//			std::cout << "�������� 3 ������� ���������\n";
//			printComponent(university->getCathedra());
//			switch (_getch())
//			{
//			case '1':
//			{
//				std::cout << "�������� ����� �������\n";
//				int choose = intValidator();
//				std::cout << "������� �������� ����������: \n";
//				std::string name = stringValidator();
//				university->getCathedra()[choose - 1]->addComponent(name);
//				break;
//			}
//			case '2':
//			{
//				std::cout << "�������� ����� �������\n";
//				int choose = intValidator();
//				std::cout << "������� ��� ������: \n";
//				std::string name = stringValidator();
//				if (choose > university->getCathedra().size() || choose < 0) break;
//				university->getCathedra()[choose - 1]->getFaculty()->setDean(name);
//				break;
//			}
//			case '3':
//			{
//				std::cout << "�������� ����� �������\n";
//				int choose = intValidator();
//
//				university->getCathedra()[choose - 1]->removeFaculty();
//				break;
//			}
//			}
//			break;
//		}
//		case '4':
//		{
//			std::cout << "�������� 1 ����� �������� �������������\n";
//			std::cout << "�������� 2 ����� ������� �������������\n";
//			printComponent(university->getCathedra());
//			switch (_getch())
//			{
//			case '1':
//			{
//				std::cout << "�������� ����� �������\n";
//				int choose = intValidator();
//				std::cout << "������� �������� �������������: \n";
//				std::string name = stringValidator();
//				university->getCathedra()[choose - 1]->getFaculty()->addComponent(name);
//				break;
//			}
//			case '2':
//			{
//				std::cout << "�������� ����� �������\n";
//				int choose = intValidator();
//				std::cout << "�������� ����� �������������: \n";
//				int choose2 = intValidator();
//
//				university->getCathedra()[choose - 1]->getFaculty()->removeSpeciality(choose2-1);
//				break;
//			}
//			}
//			break;
//		}
//		case '5':
//		{
//			switch (_getch())
//			{
//			case '1':
//			{
//				std::cout << "�������� ����� �������\n";
//				int choose = intValidator();
//				std::cout << "�������� ����� �������������: \n";
//				int choose2 = intValidator();
//				std::cout << "�������� ����� ������\n";
//				int number = intValidator();
//
//				university->getCathedra()[choose - 1]->getFaculty()->getSpecialities()[choose2 - 1]->addGroup(number);
//				break;
//			}
//			case '2':
//			{
//				std::cout << "�������� ����� �������\n";
//				int choose = intValidator();
//				std::cout << "�������� ����� �������������: \n";
//				int choose2 = intValidator();
//				std::cout << "�������� ����� ������ �� ������\n";
//				int number = intValidator();
//				std::cout << "������� ��� ��������: \n";
//				std::string name = stringValidator();
//				
//				break;
//			}
//			case '3':
//			{
//				std::cout << "�������� ����� �������\n";
//				int choose = intValidator();
//
//				university->getCathedra()[choose - 1]->removeFaculty();
//				break;
//			}
//			}
//			break;
//		}
//		case '9':
//		{
//			university->print();
//			break;
//		}
//		case '0':
//		{
//			exit(0);
//			break;
//		}
//		}
//		system("pause");
//		system("cls");
//	}
//	return 0;
//}