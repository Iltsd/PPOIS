#pragma once
#include <iostream>
class Performance
{
protected:
	int numberOfFinishedTasks;
	int numberOfDelays;
	float hoursOfOverWorking;
public:
	Performance(int numberOfFinishedTasks = 0, int numberOfDelays=0, float hoursOfOverWorking=0);
	void addFinishedTask();
	void addDelay();
	void addOverWorkHours(float hours);
	void showInfo();
};

