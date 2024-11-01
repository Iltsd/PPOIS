#include "pch.h"

#include "pch.h"
#include "../PPOISlab2/Student.h"

TEST(StudentTest, PrintFIOTest) {
    Student* student = new Student(1, 3, "John", "Doe", "Smith");

    student->changeTheScholarship(188.8);
    testing::internal::CaptureStdout();
    student->printFIO();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Doe John Smith\n");

    delete student;
}

TEST(StudentTest, AddLessonMarkTest) {
    Student* student = new Student(1, 3, "John", "Doe", "Smith");
    Lesson* math = new Lesson("Mathematics");

    student->addLessonMark(math, 5);
    Performance* performance = student->getPerformance();

    ASSERT_NE(performance, nullptr);

    std::vector<double> lessonGPA = performance->getLessonGPA();
    ASSERT_EQ(lessonGPA.size(), 1);
    EXPECT_NEAR(lessonGPA[0], 5.0, 0.01);

    delete math;
    delete student;
}

