#include "pch.h"

#include "../PPOISlab2/Performance.h"



// ���� �� ���������� ������, ���������� �������� ����� �� ��������� � ������ �������� ����� ��������
TEST(PerformanceTest, GPAComputationTest) {
    Performance* performance = new Performance();

    Lesson* math = new Lesson("Mathematics");
    Lesson* physics = new Lesson("Physics");

    // ���������� ������ ��� ���������
    performance->addMark(math, 5);
    performance->addMark(math, 4);
    performance->addMark(physics, 3);
    performance->addMark(physics, 5);

    // �������� �������� ����� �� ������� ��������
    std::vector<double> lessonGPA = performance->getLessonGPA();
    ASSERT_EQ(lessonGPA.size(), 2);
    EXPECT_EQ(performance->findStudentsGPA(), 4.25); // ������� ���� �� Mathematics


    // �������� ������ �������� ����� ��������
    EXPECT_NEAR(performance->findStudentsGPA(), 4.25, 0.01);
}
