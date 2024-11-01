#pragma once
#include "Student.h"
#include "Schedule.h"
#include <vector>
#include "examSession.h"
class Group
{
protected:
	std::vector<Student*> students;
	int GroupNumber;
	Schedule* groupSchedule;
	Person* curator;
	ExamSession* examSession;
public:
	Group(int value,std::string curatorName = "Не заданно");

	void addStudent(Student* student);
	void setCurator(std::string name);

	void addToGroupSchedule(Lesson* lesson, Auditorium* auditory);
	void addToExamSession(Exam* exam);

	void showExamsSession();
	Student* getStudent(std::string name);

	int getGrupID();
	void print() const;
};

