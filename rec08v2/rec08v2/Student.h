#ifndef Student_h
#define Student_h
#include <vector>
#include <string>

#include "Course.h"

namespace BrooklynPoly
{
	class Course;
	class Student
	{
	private:
		std::vector<Course*> courses;
		std::string name;
	public:
		Student(std::string name);
		void addCourse(Course* course);
		void dropCourse(Course* course);
		std::string getName() const;
		void setName(std::string newname);
	}
#endif