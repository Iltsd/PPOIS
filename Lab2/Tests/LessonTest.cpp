#include "pch.h"
#include "../PPOISlab2/Lesson.h"

TEST(LessonTest, getNameAndTeacherTest) {
    Lesson* lesson = new Lesson("Mathematics", "Dr. Smith");

    // Проверка имени предмета
    EXPECT_EQ(lesson->getName(), "Mathematics");

    // Проверка назначенного учителя
    Teacher* teacher = lesson->getTeacher();
    EXPECT_NE(teacher, nullptr);
    EXPECT_EQ(teacher->getName(), "Dr. Smith");

    // Изменение учителя
    lesson->setTeacher("Prof. Johnson");
    EXPECT_EQ(lesson->getTeacher()->getName(), "Prof. Johnson");
}