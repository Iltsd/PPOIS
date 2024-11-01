#include "pch.h"

#include "../PPOISlab2/Performance.h"



// Тест на добавление оценок, вычисление среднего балла по предметам и общего среднего балла студента
TEST(PerformanceTest, GPAComputationTest) {
    Performance* performance = new Performance();

    Lesson* math = new Lesson("Mathematics");
    Lesson* physics = new Lesson("Physics");

    // Добавление оценок для предметов
    performance->addMark(math, 5);
    performance->addMark(math, 4);
    performance->addMark(physics, 3);
    performance->addMark(physics, 5);

    // Проверка среднего балла по каждому предмету
    std::vector<double> lessonGPA = performance->getLessonGPA();
    ASSERT_EQ(lessonGPA.size(), 2);
    EXPECT_EQ(performance->findStudentsGPA(), 4.25); // Средний балл по Mathematics


    // Проверка общего среднего балла студента
    EXPECT_NEAR(performance->findStudentsGPA(), 4.25, 0.01);
}
