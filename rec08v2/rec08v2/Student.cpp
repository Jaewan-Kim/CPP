#include "Student.h"

namespace BrooklynPoly
{
	class Course;

	Student::Student(std::string name) : name(name) {}

	void Student::dropCourse(Course* course)
	{
		for (int i = 0; i < courses.size(); i++)
		{
			if (courses[i]->getName() == course->getName())
			{
				courses[i] = courses[courses.size() - 1];
				courses.pop_back();
			}
		}

	}
	void Student::setName(std::string newname)
	{
		name = newname;
	}
	std::string Student::getName() const { return name; }

	void Student::addCourse(Course* course)
	{
		course->addStudent(this);
		courses.push_back(course);
	}

}
