#include "pch.h"
#include "../PPOISlab2/Cathedra.h"

TEST(CathedraTest, createTest) {
    Cathedra* cathedra = new Cathedra("IIT");

    EXPECT_EQ(cathedra->getname(), "IIT");
}


TEST(CathedraTest, setCathedraHeadTest) {
    Cathedra* cathedra = new Cathedra("IIT");

    cathedra->setCathedraHead("Ivan Ivanov");

    EXPECT_EQ(cathedra->getname(), "IIT");
}

TEST(CathedraTest, addFacultyTest) {
	Cathedra* cathedra = new Cathedra("IIT");

	cathedra->addComponent(new Faculty("Engineering"));

	EXPECT_EQ(cathedra->getFaculty()->getName(), "Engineering");
}

TEST(CathedraTest, removeFacultyTest) {
    Cathedra* cathedra = new Cathedra("IIT");
    Faculty* faculty = new Faculty("Engineering");

    cathedra->addComponent(faculty);
    cathedra->removeFaculty();

    EXPECT_EQ(cathedra->getFaculty(), nullptr);
}

TEST(CathedraTest, printTest) {
    Cathedra* cathedra = new Cathedra("IIT", "Ivan Ivanov");
    Faculty* faculty = new Faculty("Engineering");

    cathedra->addComponent(faculty);

    std::string expected = "Кафедра: IIT\nГлава кафедры: Ivan Ivanov\nФакультет: Engineering\n";
    testing::internal::CaptureStdout();
    cathedra->print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(expected, output);
}
