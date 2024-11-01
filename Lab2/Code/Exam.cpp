#include "Exam.h"

Exam::Exam(Lesson* lesson, std::string date)
{
	this->lesson = lesson;
	this->date = date;
}

void Exam::printExam()
{
	std::cout <<"�������: "<< lesson->getName() << std::endl;
	std::cout <<"�������������: "<< lesson->getTeacher()->getName() << std::endl;
	std::cout << "���� ���������� ��������: " << date << std::endl;
}
