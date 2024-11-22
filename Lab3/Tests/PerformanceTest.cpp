#include "pch.h"
#include "../PPOISlab3/Performance.h"
#include "../PPOISlab3/Performance.cpp"

TEST(PerformanceTest, ConstructorInitialization) {
    Performance performance(1,1,1);

    // Перехватываем вывод метода showInfo()
    testing::internal::CaptureStdout();
    performance.showInfo();
    std::string output = testing::internal::GetCapturedStdout();

    // Проверяем начальные значения
    EXPECT_NE(output.find("Количество завершённых заданий: 1"), std::string::npos);
    EXPECT_NE(output.find("Количество опозданий: 1"), std::string::npos);
    EXPECT_NE(output.find("Часы переработок: 1"), std::string::npos);
}

TEST(PerformanceTest, AddFinishedTask) {
    Performance performance;

    performance.addFinishedTask();
    performance.addFinishedTask();

    // Перехватываем вывод метода showInfo()
    testing::internal::CaptureStdout();
    performance.showInfo();
    std::string output = testing::internal::GetCapturedStdout();

    // Проверяем количество завершённых заданий
    EXPECT_NE(output.find("Количество завершённых заданий: 2"), std::string::npos);
}

TEST(PerformanceTest, AddDelay) {
    Performance performance;

    performance.addDelay();
    performance.addDelay();
    performance.addDelay();

    // Перехватываем вывод метода showInfo()
    testing::internal::CaptureStdout();
    performance.showInfo();
    std::string output = testing::internal::GetCapturedStdout();

    // Проверяем количество опозданий
    EXPECT_NE(output.find("Количество опозданий: 3"), std::string::npos);
}

TEST(PerformanceTest, AddOverWorkHours) {
    Performance performance;

    performance.addOverWorkHours(2.5);
    performance.addOverWorkHours(1.5);

    // Перехватываем вывод метода showInfo()
    testing::internal::CaptureStdout();
    performance.showInfo();
    std::string output = testing::internal::GetCapturedStdout();

    // Проверяем часы переработок
    EXPECT_NE(output.find("Часы переработок: 4"), std::string::npos);
}
