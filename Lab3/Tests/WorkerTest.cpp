#include "pch.h"
#include "../PPOISlab3/Worker.h"

TEST(WorkerTest, ConstructorInitializesFields) {
    Worker worker(1, "John", "Doe", "Smith");

    EXPECT_EQ(worker.getWorkerID(), 1);
    // ���� ����������� �������� �����, ������� � ��������, �������� ������� � �����.
}

TEST(WorkerTest, AddTaskAndShowFinishedTasks) {
    Worker worker(2, "Alice", "Johnson", "Brown");
    worker.addTask("Task1");
    worker.addTask("Task2");
    std::string expected = "�������: Task1 �� ���������\n�������: Task2 �� ���������\n";

    testing::internal::CaptureStdout();
    worker.showFinishedTasks();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(expected, output);
    EXPECT_NE(output.find("Task1"), std::string::npos); 
    EXPECT_NE(output.find("Task2"), std::string::npos); 
}

TEST(WorkerTest, DeleteTask) {
    Worker worker(3, "Mike", "Anderson", "White");
    worker.addTask("Task1");
    worker.addTask("Task2");
    worker.deliteTask("Task1");

    testing::internal::CaptureStdout();
    worker.showFinishedTasks();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output.find("Task1"), std::string::npos); 
    EXPECT_NE(output.find("Task2"), std::string::npos); 
}

TEST(WorkerTest, ShowFinishedTasksEmpty) {
    Worker worker(4, "David", "Wilson", "Gray");

    testing::internal::CaptureStdout();
    worker.showFinishedTasks();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output.empty(), true);  // ���������, ��� ����� ����.
}
