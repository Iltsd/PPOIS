#include "Schedule.h"

Schedule::Schedule()
{
}

void Schedule::addToSchedule(Lesson* lesson, Auditorium* auditory)
{
	std::pair <Lesson*, Auditorium*> pair (lesson, auditory);
	schedule.push_back(pair);
}

void Schedule::printSchedule()
{
	for (int i = 0;i < schedule.size();++i)
	{
		std::cout << i << "����:" << schedule[i].first->getName() << "� ���������: "; schedule[i].second->print();
	}
	
}

