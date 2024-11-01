#include "Lesson.h"

Lesson::Lesson(std::string name,std::string teacherName)
{
    this->name = name;
    this->teacher = new Teacher(teacherName);
}

void Lesson::setTeacher(std::string name)
{
    this->teacher->setName(name);
}

Teacher* Lesson::getTeacher()
{
    return teacher;
}

