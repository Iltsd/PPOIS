#pragma once
#include <vector>
#include "Lesson.h"
#include "Auditorium.h"
class Schedule
{
protected:
	std::vector<std::pair<Lesson*, Auditorium*>> schedule;
public:
	Schedule();
	void addToSchedule(Lesson* lesson, Auditorium* auditory);
	void printSchedule();
};

