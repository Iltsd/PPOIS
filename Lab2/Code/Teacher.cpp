#include "Teacher.h"

Teacher::Teacher(std::string name, std::string surname, std::string middleName)
{
	this->name = name;
	this->surname = surname;
	this->middleName = middleName;
	for (int i = 0;i < 7;++i)
	{
		workingDays[i] = 0;
	}
}

void Teacher::changeWorkingDays(int day, int lessonCounter)
{
	this->workingDays[day-1] = lessonCounter;
}

void Teacher::showWorkigDays()
{
	std::cout << "Количесво рабочих часов " << surname << " " << name << " " << middleName << ":\n";
	for (int i = 0;i < 7;++i)
	{
		std::cout << workingDays[i] * 2 << " ";
	}
	std::cout << "\n";
}
