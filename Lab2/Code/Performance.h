#pragma once
#include "Lesson.h"
#include <map>
#include <vector>
class Performance
{
protected:
	std::map<Lesson*, std::vector<int>> markList;
	int skip;
public:
	Performance();

	void addMark(Lesson* lesson, int mark);

	std::vector<double> getLessonGPA();

	double findStudentsGPA();
};

