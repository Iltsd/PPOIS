#include "Group.h"

Group::Group(int value,std::string curatorName)
{
	GroupNumber = value;
	curator = new Teacher(curatorName);
	groupSchedule = new Schedule();
	examSession = new ExamSession();

}

void Group::addStudent(Student* student)
{
	students.push_back(student);
}

void Group::setCurator(std::string name)
{
	this->curator->setName(name);
}

void Group::addToGroupSchedule(Lesson* lesson, Auditorium* auditory)
{
	groupSchedule->addToSchedule(lesson, auditory);
}

void Group::addToExamSession(Exam* exam)
{
	examSession->addExam(exam);
}

void Group::showExamsSession()
{
	examSession->printExams();
}

Student* Group::getStudent(std::string name)
{
	for (int i = 0; i < students.size();++i)
	{
		if (students[i]->getName() == name)
		{
			return students[i];
		}
	}
	return nullptr;
}

int Group::getGrupID()
{
	return GroupNumber;
}

void Group::print() const
{
	std::cout << "Группа: " << GroupNumber << std::endl;
	std::cout << "Куратор: " << curator->getName() << std::endl;
	std::cout << "Студенты: " << std::endl;
	for (auto student : students)
	{
		student->printFIO();
	}
}

