#include "University.h"
#include "Teacher.h"
#include "Student.h"
#include "Speciality.h"
#include "Schedule.h"
#include "Person.h"
#include "Performance.h"
#include "Lesson.h"
#include "Group.h"
#include "Faculty.h"
#include "examSession.h"
#include "Exam.h"
#include "Component.h"
#include "Cathedra.h"
#include "Auditorium.h"
#include <conio.h>

int main()
{
	setlocale(LC_ALL, "RU");
	Auditorium* auditory1 = new Auditorium("310", 4);
	Auditorium* auditory2 = new Auditorium("612.a", 5);

	Lesson* ppois = new Lesson("PPOIS");
	ppois->setTeacher("Teacher");
	Lesson* otis = new Lesson("OTIS");

	Schedule* schedule = new Schedule();
	schedule->addToSchedule(ppois, auditory2);
	schedule->addToSchedule(ppois, auditory1);

	Student* student1 = new Student(32170013, 2, "Raman", "Herhisevich", "Dmitryevich");
	student1->addLessonMark(ppois, 10);
	student1->addLessonMark(otis, 9);
	student1->changeTheScholarship(188.8);
	double GPA = student1->getPerformance()->findStudentsGPA();
	std::cout << "Общий средний балл струдента: " << GPA << std::endl;

	Exam* exam1 = new Exam(ppois, "31.10.2024");


	Group* group = new Group(321702);
	group->addStudent(student1);
	group->setCurator("Curator");
	group->addToGroupSchedule(ppois, auditory1);
	group->addToGroupSchedule(ppois, auditory2);
	group->addToExamSession(exam1);
	
	Speciality* speciality = new Speciality("AI");
	speciality->addGroup(group);
	speciality->addLesson(ppois);

	Faculty* faculty = new Faculty("FITaC");
	faculty->addComponent(speciality);
	faculty->setDean("Dean");
	
	Cathedra* cathedra = new Cathedra("IIT");
	cathedra->addComponent(faculty);
	cathedra->setCathedraHead("CathedraHead");

	University* university = new University("BSUIR");
	university->addComponent(cathedra);
	university->setDirector("Director");
	university->print();
	cathedra->print();
	faculty->print();
	speciality->print();
	group->print();

	group->showExamsSession();

	


	return 0;
}