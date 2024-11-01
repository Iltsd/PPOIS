#include "Performance.h"

Performance::Performance()
{
	skip = 0;
}

void Performance::addMark(Lesson* lesson, int mark)
{
	markList[lesson];
	markList.find(lesson)->second.push_back(mark);
}

std::vector<double> Performance::getLessonGPA()
{
	std::vector<double> GPA;
	for (auto el : markList)
	{
		std::vector<int> temp = el.second;
		double counter = 0;
		for (int i = 0;i < temp.size();++i)
		{
			counter += temp[i];
		}
		counter /= temp.size();
		GPA.push_back(counter);
	}
	return GPA;
}

double Performance::findStudentsGPA()
{
	std::vector<double> GPA = getLessonGPA();
	double counter = 0;
	for (int i = 0;i < GPA.size();++i)
	{
		counter += GPA[i];
	}
	counter /= GPA.size();
	return counter;
}
