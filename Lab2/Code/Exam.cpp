#include "Exam.h"

Exam::Exam(Lesson* lesson, std::string date)
{
	this->lesson = lesson;
	this->date = date;
}

void Exam::printExam()
{
	std::cout <<"Предмет: "<< lesson->getName() << std::endl;
	std::cout <<"Преподователь: "<< lesson->getTeacher()->getName() << std::endl;
	std::cout << "Дата проведения экзамена: " << date << std::endl;
}
