#include "pch.h"
#include "../PPOISlab2/Lesson.h"

TEST(LessonTest, getNameAndTeacherTest) {
    Lesson* lesson = new Lesson("Mathematics", "Dr. Smith");

    // �������� ����� ��������
    EXPECT_EQ(lesson->getName(), "Mathematics");

    // �������� ������������ �������
    Teacher* teacher = lesson->getTeacher();
    EXPECT_NE(teacher, nullptr);
    EXPECT_EQ(teacher->getName(), "Dr. Smith");

    // ��������� �������
    lesson->setTeacher("Prof. Johnson");
    EXPECT_EQ(lesson->getTeacher()->getName(), "Prof. Johnson");
}