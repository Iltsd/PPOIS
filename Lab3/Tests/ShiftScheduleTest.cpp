#include "pch.h"
#include "../PPOISlab3/ShiftSchedule.h"
#include <iostream>

TEST(ShiftScheduleTest, RandomShiftAssignment) {
    // ������������� ShiftSchedule � 7 �������� ����� (������ ������), ������� � "���� 0"
    ShiftSchedule schedule(7, 0);

    // ���������, ��� ����� ���� ��������� ��� ���� ����
    bool shiftsAssigned[7] = { false, false, false, false, false, false, false };

    int* week = schedule.getWeekSchedule();
    for (int i = 0; i < 7; ++i) {
        int shiftType = week[i];
        EXPECT_TRUE(shiftType >= 0 && shiftType < 3);  // ���������, ��� ��� ����� ����� � �������� �����������
        shiftsAssigned[shiftType] = true;
    }

    // ���������, ��� ��� ������� ���� ����� ���� ���� �� ���� �������
    EXPECT_TRUE(shiftsAssigned[0]);  // �������� �����
    EXPECT_TRUE(shiftsAssigned[1]);  // ������� �����
    EXPECT_TRUE(shiftsAssigned[2]);  // ������ �����
}
