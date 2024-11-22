#include "pch.h"
#include "../PPOISlab3/Performance.h"
#include "../PPOISlab3/Performance.cpp"

TEST(PerformanceTest, ConstructorInitialization) {
    Performance performance(1,1,1);

    // ������������� ����� ������ showInfo()
    testing::internal::CaptureStdout();
    performance.showInfo();
    std::string output = testing::internal::GetCapturedStdout();

    // ��������� ��������� ��������
    EXPECT_NE(output.find("���������� ����������� �������: 1"), std::string::npos);
    EXPECT_NE(output.find("���������� ���������: 1"), std::string::npos);
    EXPECT_NE(output.find("���� �����������: 1"), std::string::npos);
}

TEST(PerformanceTest, AddFinishedTask) {
    Performance performance;

    performance.addFinishedTask();
    performance.addFinishedTask();

    // ������������� ����� ������ showInfo()
    testing::internal::CaptureStdout();
    performance.showInfo();
    std::string output = testing::internal::GetCapturedStdout();

    // ��������� ���������� ����������� �������
    EXPECT_NE(output.find("���������� ����������� �������: 2"), std::string::npos);
}

TEST(PerformanceTest, AddDelay) {
    Performance performance;

    performance.addDelay();
    performance.addDelay();
    performance.addDelay();

    // ������������� ����� ������ showInfo()
    testing::internal::CaptureStdout();
    performance.showInfo();
    std::string output = testing::internal::GetCapturedStdout();

    // ��������� ���������� ���������
    EXPECT_NE(output.find("���������� ���������: 3"), std::string::npos);
}

TEST(PerformanceTest, AddOverWorkHours) {
    Performance performance;

    performance.addOverWorkHours(2.5);
    performance.addOverWorkHours(1.5);

    // ������������� ����� ������ showInfo()
    testing::internal::CaptureStdout();
    performance.showInfo();
    std::string output = testing::internal::GetCapturedStdout();

    // ��������� ���� �����������
    EXPECT_NE(output.find("���� �����������: 4"), std::string::npos);
}
