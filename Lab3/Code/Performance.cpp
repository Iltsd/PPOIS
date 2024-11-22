#include "Performance.h"


Performance::Performance(int numberOfFinishedTasks, int numberOfDelays, float hoursOfOverWorking)
{
	this->numberOfDelays = numberOfDelays;
	this->hoursOfOverWorking = hoursOfOverWorking;
	this->numberOfFinishedTasks = numberOfFinishedTasks;
}

void Performance::addFinishedTask()
{
	numberOfFinishedTasks++;
}

void Performance::addDelay()
{
	numberOfDelays++;
}

void Performance::addOverWorkHours(float hours)
{
	hoursOfOverWorking += hours;
}

void Performance::showInfo()
{
	std::cout << "���������� ����������� �������: " << numberOfFinishedTasks << std::endl;
	std::cout << "���������� ���������: " << numberOfDelays << std::endl;
	std::cout << "���� �����������: " << hoursOfOverWorking << std::endl;
}
