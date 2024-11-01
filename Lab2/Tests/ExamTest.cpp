#include "pch.h"
#include "../PPOISlab2/Exam.h"

TEST(ExamTest, printExamTest) {
    Lesson* lesson = new Lesson("Mathematics");
    Exam* exam = new Exam(lesson, "2024-12-15");

    std::string expected = "Предмет: Mathematics\nПреподователь: Не назначен\nДата проведения экзамена: 2024-12-15\n";
    testing::internal::CaptureStdout();
    exam->printExam();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(expected, output);
}