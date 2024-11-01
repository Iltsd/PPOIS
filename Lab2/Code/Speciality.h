#pragma once
#include "Lesson.h"
#include "Group.h"
#include "Component.h"
#include "Teacher.h"
#include <set>


class Speciality : public Component
{
protected:
	std::set<Lesson*> lessonList;
	std::vector<Group*> groups;
	friend class Teacher;
public:
	using Component::Component;

	void addGroup(Group* group);

	void addLesson(Lesson* lesson);

	std::vector<Group*> getGroups();

	std::set<Lesson*> getLessonList();

	void print() const override;


};

