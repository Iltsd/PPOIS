#include "Worker.h"

Worker::Worker(int ID, std::string name, std::string surname, std::string middlename)
{
	this->name = name;
	this->surname = surname;
	this->middlename = middlename;
	this->ID = ID;
	performance = nullptr;
}

void Worker::addTask(std::string taskName)
{
	this->tasks.push_back(new Task(taskName));
}

void Worker::showFinishedTasks()
{
	for (auto task : tasks)
	{
		std::cout << "Задание: " << task->getTask();
		if (task->isComplite()) std::cout << " Выполнено\n";
		else  std::cout << " Не выполнено\n";
	}
}

void Worker::deliteTask(std::string taskName)
{
	for (int i = 0;i < tasks.size();++i)
	{
		if (tasks[i]->getTask() == taskName)
		{
			tasks.erase(tasks.begin() + i);
			return;
		}
	}
}

int Worker::getWorkerID()
{
	return ID;
}
