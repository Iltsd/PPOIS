#include "pch.h"
#include "../PPOISlab2/examSession.h"

TEST(ExamSessionTest, printExamsTest) {
    ExamSession* examSession = new ExamSession();

    Lesson* lesson1 = new Lesson("Mathematics");
    Lesson* lesson2 = new Lesson("Physics");
    Exam* exam1 = new Exam(lesson1, "2024-12-15");
    Exam* exam2 = new Exam(lesson2, "2024-12-18");

    examSession->addExam(exam1);
    examSession->addExam(exam2);

    std::string expected = "1 Экзамен: \nПредмет: Mathematics\nПреподователь: Не назначен\nДата проведения экзамена: 2024-12-15\n"
        "2 Экзамен: \nПредмет: Physics\nПреподователь: Не назначен\nДата проведения экзамена: 2024-12-18\n";
    testing::internal::CaptureStdout();
    examSession->printExams();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(expected, output);
}