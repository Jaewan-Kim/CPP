#include "Course.h"
#include<iostream>
#include<vector>

namespace BrooklynPoly
{
	class Student;

	Course::Course(std::string name) : name(name) {}
	std::string Course::getName() const { return name; }

	void Course::addStudent(Student* student)
	{
		students.push_back(student);
	}
	void Course::dropStudent(Student* student)
	{
		for (int i = 0; i < students.size(); i++)
		{
			if (student->getName() == students[i]->getName())
			{
				students[i] = students[students.size() - 1];
				students.pop_back();
			}

		}
	}

}