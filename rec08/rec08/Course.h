#ifndef Course_h
#define Course_h
#include <string>
#include <vector>

#include "Student.h"

namespace BrooklynPoly
{
	class Student;

	class Course
	{
	private:
		std::string name;
		std::vector<Student*> students;
	public:
		Course(std::string name);
		void addStudent(Student* student);
		void dropStudent(Student* student);
		std::string getName() const;
	};
}

#endif