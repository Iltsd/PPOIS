#pragma once
#include "Performance.h"
#include "Task.h"
#include "ShiftSchedule.h"
#include <vector>
class Worker
{
protected:
	std::string name;
	std::string surname;
	std::string middlename;
	int ID;
	Performance* performance;
	std::vector<Task*> tasks;
	ShiftSchedule* shiftShedule;
	
public:
	Worker(int ID, std::string name, std::string surname, std::string middlename);
	void addTask(std::string taskName);
	void showFinishedTasks();
	void deliteTask(std::string taskName);
	int getWorkerID();
	
};

