#include "pch.h"
#include "../PPOISlab2/Speciality.h"


// ���� �� ���������� ������ � �������������
TEST(SpecialityTest, addGroupTest) {
    Speciality* speciality = new Speciality("Computer Science");
    Group* group = new Group(321702);

    speciality->addGroup(group);

    // ��������, ��� ������ ���������
    EXPECT_EQ(speciality->getGroups().size(), 1);
    EXPECT_EQ(speciality->getGroups()[0]->getGrupID(), 321702);
}

// ���� �� ���������� ����� � �������������
TEST(SpecialityTest, addLessonTest) {
    Speciality* speciality = new Speciality("Computer Science");
    Lesson* lesson = new Lesson("Mathematics");

    speciality->addLesson(lesson);

    // ��������, ��� ���� �������� � ������ ������
    EXPECT_EQ(speciality->getGroups().size(), 0);
}

// ���� �� ��������� ������ �����
TEST(SpecialityTest, getGroupsTest) {
    Speciality* speciality = new Speciality("Computer Science");
    Group* group1 = new Group(321702);
    Group* group2 = new Group(321701);

    speciality->addGroup(group1);
    speciality->addGroup(group2);

    // ��������, ��� ��� ������ ��������� � ���������� ������� getGroups()
    std::vector<Group*> groups = speciality->getGroups();
    EXPECT_EQ(groups.size(), 2);
    EXPECT_EQ(groups.at(0)->getGrupID(), 321702);
    EXPECT_EQ(groups.at(1)->getGrupID(), 321701);
}

// ���� �� ������ ���������� � �������������
TEST(SpecialityTest, printTest) {
    Speciality* speciality = new Speciality("Computer Science");
    Group* group = new Group(321702);
    Lesson* lesson = new Lesson("Mathematics");

    speciality->addGroup(group);
    speciality->addLesson(lesson);

    std::string expected = "�������������: Computer Science\n������:\n321702\n";
    testing::internal::CaptureStdout();
    speciality->print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(expected, output);
}
