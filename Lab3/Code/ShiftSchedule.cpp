#include "ShiftSchedule.h"

ShiftSchedule::ShiftSchedule(int numberOfWorkingDays, int firstDay)
{
    std::fill(std::begin(weekSchedule), std::end(weekSchedule), -1);  // ������������� �������
    int dayNumber = firstDay;
    for (int i = 0; i < numberOfWorkingDays; ++i)
    {
        dayNumber = firstDay + i;
        if (dayNumber > 6) dayNumber -= 7;
        weekSchedule[dayNumber] = rand() % 3;  // ��������� ��������� �����
    }
}
int* ShiftSchedule::getWeekSchedule()
{
	return weekSchedule;
}


void ShiftSchedule::showWeekSchedule()
{
	for (int i = 0;i < 7;i++)
	{
		std::cout << i << "����: " << shift[i] << "\n";
	}
}
