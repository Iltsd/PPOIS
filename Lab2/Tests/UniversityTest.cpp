#include "pch.h"
#include "../PPOISlab2/University.h"
#include "../PPOISlab2/Teacher.h"
#include "../PPOISlab2/Student.h"
#include "../PPOISlab2/Speciality.h"
#include "../PPOISlab2/Schedule.h"
#include "../PPOISlab2/Person.h"
#include "../PPOISlab2/Performance.h"
#include "../PPOISlab2/Lesson.h"
#include "../PPOISlab2/Group.h"
#include "../PPOISlab2/Faculty.h"
#include "../PPOISlab2/examSession.h"
#include "../PPOISlab2/Exam.h"
#include "../PPOISlab2/Component.h"
#include "../PPOISlab2/Cathedra.h"
#include "../PPOISlab2/Auditorium.h"
#include "../PPOISlab2/University.cpp"
#include "../PPOISlab2/Teacher.cpp"
#include "../PPOISlab2/Student.cpp"
#include "../PPOISlab2/Speciality.cpp"
#include "../PPOISlab2/Schedule.cpp"
#include "../PPOISlab2/Person.cpp"
#include "../PPOISlab2/Performance.cpp"
#include "../PPOISlab2/Lesson.cpp"
#include "../PPOISlab2/Group.cpp"
#include "../PPOISlab2/Faculty.cpp"
#include "../PPOISlab2/examSession.cpp"
#include "../PPOISlab2/Exam.cpp"
#include "../PPOISlab2/Component.cpp"
#include "../PPOISlab2/Cathedra.cpp"
#include "../PPOISlab2/Auditorium.cpp"

TEST(UniversityTest, createTest)
{
	University* university = new University("BSUIR");

	Cathedra* cathedra = new Cathedra("IIT");
	university->addComponent(cathedra);

	EXPECT_EQ(university->getCathedra().size(), 1);

}

TEST(UniversityTest, removeCathedra)
{
	University* university = new University("BSUIR");

	Cathedra* cathedra = new Cathedra("IIT");
	university->addComponent(cathedra);
	university->removeCathedra(0);
	
	EXPECT_EQ(university->getCathedra().size(), 0);
}

TEST(UniversityTest, printTest)
{
	University* university = new University("BSUIR");

	Cathedra* cathedra = new Cathedra("IIT");
	university->addComponent(cathedra);
	university->setDirector("Director");

	std::string expected = "Унивеситет: BSUIR\nДиректор: Director\nIIT\n";
	testing::internal::CaptureStdout();
	university->print();
	std::string output = testing::internal::GetCapturedStdout();

	EXPECT_EQ(expected, output);

}




