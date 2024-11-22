#include "pch.h"
#include "../PPOISlab3/AlertSystem.h"

TEST(AlertSystemTest, AddAlert) {
    AlertSystem alertSystem;

    alertSystem.addAlert("First Alert");

    // ���������, ��� ����������� ���������
    EXPECT_EQ(alertSystem.getAlertText(0), "First Alert");
}

TEST(AlertSystemTest, DeleteAlert) {
    AlertSystem alertSystem;

    alertSystem.addAlert("First Alert");
    alertSystem.addAlert("Second Alert");
    alertSystem.deleteAlert(0);

    // ���������, ��� ������ ����������� �������, � ������ ��������
    EXPECT_EQ(alertSystem.getAlertText(0), "Second Alert");
}

TEST(AlertSystemTest, ShowInfoOutput) {
    AlertSystem alertSystem;
    alertSystem.addAlert("Alert 1");
    alertSystem.addAlert("Alert 2");

    // �������� ������ showInfo()
    testing::internal::CaptureStdout();
    alertSystem.showInfo();
    std::string output = testing::internal::GetCapturedStdout();

    // ���������, ��� ���������� ��� ���� ������������ ������������
    EXPECT_NE(output.find("1�����������"), std::string::npos);
    EXPECT_NE(output.find("Alert 1"), std::string::npos);
    EXPECT_NE(output.find("2�����������"), std::string::npos);
    EXPECT_NE(output.find("Alert 2"), std::string::npos);
}

TEST(AlertSystemTest, IsComplete) {
    AlertSystem alertSystem;

    alertSystem.addAlert("Complete this");
    alertSystem.addAlert("Or this");

    // ��������� ���������� �����������
    EXPECT_FALSE(alertSystem.isComplite(0, 1));  // �������� ���������� ������ 1
    EXPECT_FALSE(alertSystem.isComplite(1, 2));  // �������� ���������� ������ 2

    // ����� ����������
    alertSystem.deleteAlert(0);  // ���������� ����������
    EXPECT_TRUE(alertSystem.isComplite(0, 0));  // �������� ���������� >= 0
}
