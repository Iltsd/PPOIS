#include "pch.h"
#include "../PPOISlab3/ShiftSchedule.h"
#include <iostream>

TEST(ShiftScheduleTest, RandomShiftAssignment) {
    // Инициализация ShiftSchedule с 7 рабочими днями (полная неделя), начиная с "День 0"
    ShiftSchedule schedule(7, 0);

    // Проверяем, что смены были назначены для всех дней
    bool shiftsAssigned[7] = { false, false, false, false, false, false, false };

    int* week = schedule.getWeekSchedule();
    for (int i = 0; i < 7; ++i) {
        int shiftType = week[i];
        EXPECT_TRUE(shiftType >= 0 && shiftType < 3);  // Проверяем, что тип смены лежит в пределах допустимого
        shiftsAssigned[shiftType] = true;
    }

    // Проверяем, что для каждого типа смены была хотя бы одна встреча
    EXPECT_TRUE(shiftsAssigned[0]);  // Утренние смены
    EXPECT_TRUE(shiftsAssigned[1]);  // Дневные смены
    EXPECT_TRUE(shiftsAssigned[2]);  // Ночные смены
}
