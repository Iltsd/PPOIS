#pragma once
#include "Teacher.h"
#include "Component.h"
#include <string>
class Lesson : Component
{
protected:
	Teacher* teacher;
public:
	Lesson(std::string name,std::string teacherName = "�� ��������");

	void setTeacher(std::string name);

	using Component::getName;

	Teacher* getTeacher();
	
};

