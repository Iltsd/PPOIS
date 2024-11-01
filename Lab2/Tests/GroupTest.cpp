#include "pch.h"
#include "../PPOISlab2/Group.h"


TEST(GroupTest, addStudentTest) {
    Group* group = new Group(101);
    Student* student = new Student(123, 2,"BOB", "Ivanov", "Ivan");

    group->addStudent(student);

    EXPECT_EQ(group->getGrupID(), 101);
    EXPECT_EQ(group->getStudent("BOB")->getName(), "BOB");
}


TEST(GroupTest, setCuratorTest) {
    Group* group = new Group(101);
    group->setCurator("Dr. Smith");

}

TEST(GroupTest, addToGroupScheduleTest) {
    Group* group = new Group(101);
    Lesson* lesson = new Lesson("Mathematics");
    Auditorium* auditorium = new Auditorium("Room 101",2);

    group->addToGroupSchedule(lesson, auditorium);

}
TEST(GroupTest, getGrupIDTest) {
    Group* group = new Group(101);

    EXPECT_EQ(group->getGrupID(), 101);
}


TEST(GroupTest, printTest) {
    Group* group = new Group(101, "Dr. Smith");
    Student* student = new Student(1, 85,"bob", "Ivanov", "Ivan");

    group->addStudent(student);

    std::string expected = "Группа: 101\nКуратор: Dr. Smith\nСтуденты: \nIvanov bob Ivan\n";
    testing::internal::CaptureStdout();
    group->print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(expected, output);
}
