#include "pch.h"
#include "../PPOISlab3/Task.h"

TEST(TaskTest, ConstructorAndGetters) {
    Task task("Complete documentation");

    // ���������, ��� ������ ���������������� � ���������� ���������
    EXPECT_EQ(task.getTask(), "Complete documentation");

    // ���������, ��� ������ �� ��������� �� ���������
    EXPECT_FALSE(task.isComplite());
}

TEST(TaskTest, FinishTask) {
    Task task("Complete documentation");

    // ��������� ������
    task.finishTask();

    // ���������, ��� ������ ���������
    EXPECT_TRUE(task.isComplite());
}

TEST(TaskTest, IsComplite) {
    Task task("Complete documentation");

    // ������ �� ��������� ����������
    EXPECT_FALSE(task.isComplite());

    // ��������� ������
    task.finishTask();

    // ���������, ��� ������ ���������
    EXPECT_TRUE(task.isComplite());
}

