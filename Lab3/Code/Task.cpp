#include "Task.h"

Task::Task(std::string task)
{
	this->task = task;
}

std::string Task::getTask()
{
	return this->task;
}

void Task::finishTask()
{
	this->complite = 1;
}

bool Task::isComplite()
{
	if (this->complite == 1) return 1;
	return 0;
}
