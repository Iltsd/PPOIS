#pragma once
#include "Person.h"

class Teacher : public Person
{
protected:
	std::string surname;
	std::string middleName;
	int workingDays[7] ;
public:
	using Person::Person;

	Teacher(std::string name, std::string surname, std::string middleName);

	void changeWorkingDays(int day, int lessonCounter);

	void showWorkigDays();


};

