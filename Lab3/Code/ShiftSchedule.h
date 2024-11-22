#pragma once
#include <iostream>
#include <array>
#include <random>
class ShiftSchedule
{
protected:
	const std::array<std::string, 3> shift = { "Morning", "Day", "Night" };
	int weekSchedule[7];
public:
	ShiftSchedule(int numberOfWorkingDays, int firstDay);
	int* getWeekSchedule();
	void showWeekSchedule();
};
