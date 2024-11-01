#pragma once
#include "Exam.h"
class ExamSession
{
protected:
	std::vector<Exam*> examSchedule;
public:
	ExamSession();

	void addExam(Exam* exam);

	void printExams();
};

