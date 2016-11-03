#include "Course.h"

namespace BrooklynPoly
{
	class Student;

	Course::Course(std::string name) : name(name) {}

	void Course::addStudent(Student* student)
	{
		students.push_back(student);
	}
	void Course::dropStudent(Student* student)
	{
		for (int i = 0; i < students.size(); i++)
		{
			if (students[i]->getName() == student->getName())
			{
				students[i] = students[students.size() - 1];
				students.pop_back();
				break;
			}

		}
	}
	std::string Course::getName() const 
	{ 
		return name; 
	}


}