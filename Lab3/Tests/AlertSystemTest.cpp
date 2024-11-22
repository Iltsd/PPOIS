#include "pch.h"
#include "../PPOISlab3/AlertSystem.h"

TEST(AlertSystemTest, AddAlert) {
    AlertSystem alertSystem;

    alertSystem.addAlert("First Alert");

    // Проверяем, что уведомление добавлено
    EXPECT_EQ(alertSystem.getAlertText(0), "First Alert");
}

TEST(AlertSystemTest, DeleteAlert) {
    AlertSystem alertSystem;

    alertSystem.addAlert("First Alert");
    alertSystem.addAlert("Second Alert");
    alertSystem.deleteAlert(0);

    // Проверяем, что первое уведомление удалено, а второе осталось
    EXPECT_EQ(alertSystem.getAlertText(0), "Second Alert");
}

TEST(AlertSystemTest, ShowInfoOutput) {
    AlertSystem alertSystem;
    alertSystem.addAlert("Alert 1");
    alertSystem.addAlert("Alert 2");

    // Перехват вывода showInfo()
    testing::internal::CaptureStdout();
    alertSystem.showInfo();
    std::string output = testing::internal::GetCapturedStdout();

    // Проверяем, что информация обо всех уведомлениях присутствует
    EXPECT_NE(output.find("1Уведомление"), std::string::npos);
    EXPECT_NE(output.find("Alert 1"), std::string::npos);
    EXPECT_NE(output.find("2Уведомление"), std::string::npos);
    EXPECT_NE(output.find("Alert 2"), std::string::npos);
}

TEST(AlertSystemTest, IsComplete) {
    AlertSystem alertSystem;

    alertSystem.addAlert("Complete this");
    alertSystem.addAlert("Or this");

    // Проверяем выполнение уведомлений
    EXPECT_FALSE(alertSystem.isComplite(0, 1));  // Успешных выполнений меньше 1
    EXPECT_FALSE(alertSystem.isComplite(1, 2));  // Успешных выполнений меньше 2

    // После выполнения
    alertSystem.deleteAlert(0);  // Симулируем выполнение
    EXPECT_TRUE(alertSystem.isComplite(0, 0));  // Успешные выполнения >= 0
}
