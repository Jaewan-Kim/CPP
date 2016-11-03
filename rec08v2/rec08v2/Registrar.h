#ifndef Registrar_h
#define Registrar_h

#include "Student.h"
#include "Course.h"
#include <vector>
#include <string>
#include <iostream>

namespace BrooklynPoly
{
	class Student;
	class Course;
	class Registrar
	{
	private:
		std::vector<Course*> courses;
		std::vector<Student*> students;
		std::string lastaction = "";
		std::string lastparameter = "";
		std::string lastparameter2 = "";
	public:
		int addCourse(std::string coursename);
		int dropStudent(std::string studentname);
		int addStudent(std::string studentname);
		int dropCourse(std::string coursename);
		void changeStudentName(std::string oldname, std::string newname);
		void enrollStudent(std::string studentname, std::string coursename);
		void dropStudentFromCourse(std::string studentname, std::string coursename);
		void printReport();
		void purge();
	};
}

#endif
