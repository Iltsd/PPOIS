#include "pch.h"
#include "../PPOISlab3/Task.h"

TEST(TaskTest, ConstructorAndGetters) {
    Task task("Complete documentation");

    // Проверяем, что задача инициализируется с правильным названием
    EXPECT_EQ(task.getTask(), "Complete documentation");

    // Проверяем, что задача не завершена по умолчанию
    EXPECT_FALSE(task.isComplite());
}

TEST(TaskTest, FinishTask) {
    Task task("Complete documentation");

    // Завершаем задачу
    task.finishTask();

    // Проверяем, что задача завершена
    EXPECT_TRUE(task.isComplite());
}

TEST(TaskTest, IsComplite) {
    Task task("Complete documentation");

    // Задача не завершена изначально
    EXPECT_FALSE(task.isComplite());

    // Завершаем задачу
    task.finishTask();

    // Проверяем, что задача завершена
    EXPECT_TRUE(task.isComplite());
}

