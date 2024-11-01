#include "examSession.h"

ExamSession::ExamSession()
{
}

void ExamSession::addExam(Exam* exam)
{
	this->examSchedule.push_back(exam);
}

void ExamSession::printExams()
{
	for (int i = 0;i < examSchedule.size();++i)
	{
		std::cout << i+1 << " Экзамен: " << std::endl;
		examSchedule[i]->printExam();
	}
}
