#include "pch.h"
#include "../PPOISlab2/Speciality.h"


// Тест на добавление группы к специальности
TEST(SpecialityTest, addGroupTest) {
    Speciality* speciality = new Speciality("Computer Science");
    Group* group = new Group(321702);

    speciality->addGroup(group);

    // Проверим, что группа добавлена
    EXPECT_EQ(speciality->getGroups().size(), 1);
    EXPECT_EQ(speciality->getGroups()[0]->getGrupID(), 321702);
}

// Тест на добавление урока к специальности
TEST(SpecialityTest, addLessonTest) {
    Speciality* speciality = new Speciality("Computer Science");
    Lesson* lesson = new Lesson("Mathematics");

    speciality->addLesson(lesson);

    // Проверим, что урок добавлен в список уроков
    EXPECT_EQ(speciality->getGroups().size(), 0);
}

// Тест на получение списка групп
TEST(SpecialityTest, getGroupsTest) {
    Speciality* speciality = new Speciality("Computer Science");
    Group* group1 = new Group(321702);
    Group* group2 = new Group(321701);

    speciality->addGroup(group1);
    speciality->addGroup(group2);

    // Проверим, что обе группы добавлены и возвращены методом getGroups()
    std::vector<Group*> groups = speciality->getGroups();
    EXPECT_EQ(groups.size(), 2);
    EXPECT_EQ(groups.at(0)->getGrupID(), 321702);
    EXPECT_EQ(groups.at(1)->getGrupID(), 321701);
}

// Тест на печать информации о специальности
TEST(SpecialityTest, printTest) {
    Speciality* speciality = new Speciality("Computer Science");
    Group* group = new Group(321702);
    Lesson* lesson = new Lesson("Mathematics");

    speciality->addGroup(group);
    speciality->addLesson(lesson);

    std::string expected = "Специальность: Computer Science\nГруппы:\n321702\n";
    testing::internal::CaptureStdout();
    speciality->print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(expected, output);
}
