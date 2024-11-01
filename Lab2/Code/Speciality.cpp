#include "Speciality.h"

void Speciality::addGroup(Group* group)
{
	groups.push_back(group);
}

void Speciality::addLesson(Lesson* lesson)
{
	lessonList.insert(lesson);
}

std::vector<Group*> Speciality::getGroups()
{
	return groups;
}

std::set<Lesson*> Speciality::getLessonList()
{
	return lessonList;
}

void Speciality::print() const
{
	std::cout << "�������������: " << name << std::endl;
	std::cout << "������:\n";
	for (auto group : groups)
	{
		std::cout << group->getGrupID() << std::endl;
	}
}
