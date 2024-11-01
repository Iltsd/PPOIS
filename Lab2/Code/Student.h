#pragma once
#include <map>
#include "Person.h"
#include "Performance.h"

class Student : public Person
{
protected:
	Performance* performance;
	std::string surname;
	std::string middleName;
	int ID;
	int grade;
	double scholarchip;
public:
	Student(int ID, int grade, std::string name,std::string surname, std::string middleName);

	void addLessonMark(Lesson* lesson, int mark);

	Performance* getPerformance();

	void changeTheScholarship(double value);

	void printFIO() const;
};

