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
//	std::cout << "Введите значение\n";
//	while (!(std::cin >> value))
//	{
//		std::cin.clear();
//		std::cin.ignore(3127, '\n');
//		std::cerr << "Некоректное значение\n";
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
//	std::cout << "Выберите 1 чтобы редактировать содержимое университета\n";
//	std::cout << "Выберите 2 чтобы редактировать содержимое кафедр\n";
//	std::cout << "Выберите 3 чтобы редактировать содержимое факультетов\n";
//	std::cout << "Выберите 4 чтобы редактировать содержимое специальностей\n";
//	std::cout << "Выберите 5 чтобы редактировать содержимое \n";
//	std::cout << "Выберите 6 чтобы редактировать содержимое\n";
//	std::cout << "Выберите 7 чтобы редактировать содержимое\n";
//	std::cout << "Выберите 8 чтобы редактировать содержимое\n";
//	std::cout << "Выберите 9 чтобы вывести информацию\n";
//	std::cout << "Выберите 0 чтобы выйти\n";
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
//			std::cout << "Выберите 1 чтобы создать университет\n";
//			std::cout << "Выберите 2 чтобы сменить директора\n";
//			switch (_getch())
//			{
//			case '1':
//			{
//				std::cout << "Введите название университета: \n";
//				std::string name = stringValidator();
//				university = new University(name);
//				break;
//			}
//			case '2':
//			{
//				std::cout << "Введите имя директора: \n";
//				university->setDirector(stringValidator());
//				break;
//			}
//			}
//			
//			break;
//		}
//		case'2':
//		{
//			std::cout << "Выберите 1 чтобы добавить кафедру\n";
//			std::cout << "Выберите 2 чтобы сменить главу кафедры\n";
//			std::cout << "Выберите 3 удалить кафедру\n";
//			switch (_getch())
//			{
//
//			case '1':
//			{
//				std::cout << "Введите название кафедры: \n";
//				std::string name = stringValidator();
//				university->addComponent(name);
//				break;
//			}
//			case '2':
//			{
//				std::cout << "Введите имя главы кафедры: \n";
//				std::string name = stringValidator();
//				int num = intValidator();
//				if (num > university->getCathedra().size() || num < 0) break;
//				university->getCathedra()[num-1]->setCathedraHead(name);
//				break;
//			}
//			case '3':
//			{
//				std::cout << "Введите номер кафедры: \n";
//				int num = intValidator();
//				university->removeCathedra(num-1);
//				break;
//			}
//			}
//			break;
//		}
//		case '3':
//		{
//			std::cout << "Выберите 1 чтобы добавить факультет\n";
//			std::cout << "Выберите 2 чтобы сменить декана\n";
//			std::cout << "Выберите 3 удалить факультет\n";
//			printComponent(university->getCathedra());
//			switch (_getch())
//			{
//			case '1':
//			{
//				std::cout << "Выберите номер кафедры\n";
//				int choose = intValidator();
//				std::cout << "Введите название факультета: \n";
//				std::string name = stringValidator();
//				university->getCathedra()[choose - 1]->addComponent(name);
//				break;
//			}
//			case '2':
//			{
//				std::cout << "Выберите номер кафедры\n";
//				int choose = intValidator();
//				std::cout << "Введите имя декана: \n";
//				std::string name = stringValidator();
//				if (choose > university->getCathedra().size() || choose < 0) break;
//				university->getCathedra()[choose - 1]->getFaculty()->setDean(name);
//				break;
//			}
//			case '3':
//			{
//				std::cout << "Выберите номер кафедры\n";
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
//			std::cout << "Выберите 1 чтобы добавить специальность\n";
//			std::cout << "Выберите 2 чтобы удалить специальность\n";
//			printComponent(university->getCathedra());
//			switch (_getch())
//			{
//			case '1':
//			{
//				std::cout << "Выберите номер кафедры\n";
//				int choose = intValidator();
//				std::cout << "Введите название специальности: \n";
//				std::string name = stringValidator();
//				university->getCathedra()[choose - 1]->getFaculty()->addComponent(name);
//				break;
//			}
//			case '2':
//			{
//				std::cout << "Выберите номер кафедры\n";
//				int choose = intValidator();
//				std::cout << "Выберите номер специальности: \n";
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
//				std::cout << "Выберите номер кафедры\n";
//				int choose = intValidator();
//				std::cout << "Выберите номер специальности: \n";
//				int choose2 = intValidator();
//				std::cout << "Выберите номер группы\n";
//				int number = intValidator();
//
//				university->getCathedra()[choose - 1]->getFaculty()->getSpecialities()[choose2 - 1]->addGroup(number);
//				break;
//			}
//			case '2':
//			{
//				std::cout << "Выберите номер кафедры\n";
//				int choose = intValidator();
//				std::cout << "Выберите номер специальности: \n";
//				int choose2 = intValidator();
//				std::cout << "Выберите номер группы из списка\n";
//				int number = intValidator();
//				std::cout << "Введите имя куратора: \n";
//				std::string name = stringValidator();
//				
//				break;
//			}
//			case '3':
//			{
//				std::cout << "Выберите номер кафедры\n";
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