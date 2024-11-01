#include "Student.h"



Student::Student(int ID, int grade, std::string name,std::string surname,std::string middleName)
{
	this->name = name;
	this->surname = surname;
	this->middleName = middleName;
	this->ID = ID;
	this->grade = grade;
	this->scholarchip = 0.0;
	performance = new Performance();
}

void Student::addLessonMark(Lesson* lesson, int mark)
{
	performance->addMark(lesson, mark);
}

Performance* Student::getPerformance()
{
	return performance;
}

void Student::changeTheScholarship(double value)
{
	this->scholarchip = value;
}

void Student::printFIO() const
{
	std::cout << surname << " " << name << " " << middleName << std::endl;
}
