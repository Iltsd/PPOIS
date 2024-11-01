#include "pch.h"
#include "../PPOISlab2/Faculty.h"

TEST(FacultyTest, createTest) {
    Faculty* faculty = new Faculty("Engineering");

    EXPECT_EQ(faculty->getName(), "Engineering");
}


TEST(FacultyTest, addSpecialityTest) {
    Faculty* faculty = new Faculty("Engineering");
    Speciality* speciality = new Speciality("Computer Science");

    faculty->addComponent(speciality);

    EXPECT_EQ(faculty->getSpecialities().size(), 1);
    EXPECT_EQ(faculty->getSpecialities().at(0)->getName(), "Computer Science");
}

TEST(FacultyTest, removeSpecialityTest) {
    Faculty* faculty = new Faculty("Engineering");
    Speciality* speciality1 = new Speciality("Computer Science");
    Speciality* speciality2 = new Speciality("Electrical Engineering");

    faculty->addComponent(speciality1);
    faculty->addComponent(speciality2);

    faculty->removeSpeciality(0);

    EXPECT_EQ(faculty->getSpecialities().size(), 1);
    EXPECT_EQ(faculty->getSpecialities().at(0)->getName(), "Electrical Engineering");
}
TEST(FacultyTest, printTest) {
    Faculty* faculty = new Faculty("Engineering", "John Doe");
    Speciality* speciality = new Speciality("Computer Science");

    faculty->addComponent(speciality);

    std::string expected = "Факультет: Engineering\nДекан факультета: John Doe\nСпециальности: \nComputer Science\n";
    testing::internal::CaptureStdout();
    faculty->print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(expected, output);
}
