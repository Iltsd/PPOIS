#pragma once
#include <string>
#include <iostream>

class Task
{
protected:
	std::string task;
	bool complite;
public:
	Task(std::string task);
	std::string getTask();
	void finishTask();
	bool isComplite();
};

