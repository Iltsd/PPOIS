#pragma once
#include "Lesson.h"
#include <string>
class Exam
{
protected:
	Lesson* lesson;
	std::string date;
public:
	Exam(Lesson* lesson, std::string date);

	void printExam();

};

