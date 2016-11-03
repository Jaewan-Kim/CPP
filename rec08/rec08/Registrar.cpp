#include "Registrar.h"

namespace BrooklynPoly
{
	class Course;
	class Student;

	void Registrar::printReport()
	{
		std::cout << "PrintReport" << std::endl;
		std::cout << lastaction << " " << lastparameter << " " << lastparameter2 << std::endl;

	}
	void Registrar::purge()
	{
		for (Student* student : students)
			delete student;
		students.clear();
		for (Course* course : courses)
			delete course;
		courses.clear();
		lastaction = "Purge";
		lastparameter = "";
		lastparameter2 = "";
	}
	void Registrar::dropStudentFromCourse(std::string studentname, std::string coursename)
	{
		Student* tempst = nullptr;
		Course* tempc = nullptr;
		for (Student* student : students)
		{
			if (student->getName() == studentname)
				tempst = student;
		}
		for (Course* course : courses)
		{
			if (course->getName() == coursename)
				tempc = course;
		}

		if ((tempst) && (tempc))
		{
			tempst->dropCourse(tempc);
			tempc->dropStudent(tempst);

			lastaction = "DropStudentFromCourse";
			lastparameter = studentname;
			lastparameter2 = coursename;
		}
	}

	void Registrar::changeStudentName(std::string oldname, std::string newname)
	{
		for (Student* student : students)
		{
			if (student->getName() == oldname)
			{
				student->setName(newname);
				break;
			}
			
		}
	}
	
	void Registrar::enrollStudent(std::string studentname, std::string coursename)
	{
		Student* tempst = nullptr;
		Course* tempc = nullptr;
		for (Student* student : students)
		{
			if (student->getName() == studentname)
				tempst = student;
		}
		for (Course* course : courses)
		{
			if (course->getName() == coursename)
				tempc = course;
		}

		if (tempst&& tempc)
		{
			tempst->addCourse(tempc);
		}
		lastaction = "EnrollStudentInCourse";
		lastparameter = studentname;
		lastparameter2 = coursename;
	}
	int Registrar::dropCourse(std::string coursename)
	{
		for (int i = 0; i < courses.size(); i++)
		{
			if (courses[i]->getName() == coursename)
			{
				delete courses[i];
				courses[i] = courses[courses.size() - 1];
				courses.pop_back();
				lastaction = "CancelCourse";
				lastparameter = coursename;
				lastparameter2 = "";
				return 0;
			}
		}
		return 0;
	}
	int Registrar::dropStudent(std::string studentname)
	{
		for (int i = 0; i < students.size(); i++)
		{
			if (students[i]->getName() == studentname)
			{
				delete students[i];
				students[i] = students[students.size() - 1];
				students.pop_back();
				lastaction = "DropStudent";
				lastparameter = studentname;
				lastparameter2 = "";
				return 0;
			}
		}
		return 0;
	}

	int Registrar:: addStudent(std::string studentname)
	{
		for (Student* student : students)
			if (student->getName() == studentname)
				return 0;

		Student* student = new Student(studentname);
		students.push_back(student);
		lastaction = "AddStudent";
		lastparameter = studentname;
		lastparameter2 = "";
		return 0;
	}

	int Registrar::addCourse(std::string coursename)
	{
		for (Course* course : courses)
		{
			if (course->getName() == coursename)
			{
				return 0;
			}
		}
		lastaction = "AddCourse";
		lastparameter = coursename;
		lastparameter2 = "";
		Course* course = new Course(coursename);
		courses.push_back(course);
		return 0;
	}
	
}