//Jaewan Kim
// 14750277
// recitation 05

#include <iostream>
#include<string>
#include <vector>

using namespace std;

class Section;
class LabWorker;
class Student
{
	string const name;
	vector<int> grades;

public:
	Student(string name = "") :name(name)
	{
		for (int i = 0; i < 13; i++)
		{
			grades.push_back(-1);
		}
	}
	string getName() const { return name; }
	void addGrade(int grade, int index);
	void display();
};

void Student::display()
{
	cout << "Student: " << name << "; Grades:";
	for (int x : grades)
	{
		cout << " " << x;
	}
	cout << endl;
}

void Student::addGrade(int grade, int index)
{
	grades.at(index) = grade;
}

class TimeSlot
{
	string day;
	int hour;
public:
	TimeSlot(string day = "Monday", int hour = 0) : day(day), hour(hour) {}
	string getDay() const { return day; }
	int getHour() const { return hour; }
};

class Section
{
	string name;
	vector<Student*> students;
	TimeSlot time;
public:
	Section(string name, string day, int hour);
	void addStudent(string name);
	void display();
	void reset();
	void addGrade(string name, int grade,int index);
};

void Section::addGrade(string name, int grade, int index)
{
	for (Student* s : students)
	{
		if (s->getName() == name)
		{
			s->addGrade(grade, index);
		}
	}
}
void Section::reset()
{
	for (Student* s : students)
		delete s;
	students.clear();
}

Section::Section(string name, string day, int hour)
{
	this->name = name;
	TimeSlot ts = TimeSlot(day, hour);
	time = ts;
}

void Section::addStudent(string name)
{
	Student* st = new Student(name);

	students.push_back(st);
}

void Section::display()
{
	int temp = 0;
	if (time.getHour() > 12)
	{
		temp = time.getHour() - 12;
	}
	cout << "Section: " << name << "; " << time.getDay() << temp << endl;

	for (Student* st : students)
	{
		st->display();
	}
	cout << endl;
}

class LabWorker
{
	string const name;
	Section* section;

public:
	LabWorker(string name = "") : name(name) {}
	void addSection(Section& section);
	void displayGrades();
	void addGrade(string name, int grade, int index);
};

void LabWorker::addGrade(string name, int grade, int index)
{ 
	section->addGrade(name, grade, index);
}

void LabWorker::addSection(Section& sec)
{
	section = &sec;
}

void LabWorker::displayGrades()
{
	cout << name << " has ";
	section->display();
}

int main()
{
	LabWorker moe("Moe");
	LabWorker jane("Jane");

	Section secA2("A2", "Tuesday", 16);
	secA2.addStudent("John");
	secA2.addStudent("George");
	secA2.addStudent("Paul");
	secA2.addStudent("Ringo");

	cout << "\ntest A2\n";    
	secA2.display();         
	moe.addSection(secA2);
	moe.displayGrades();       // here the modeler-programmer checks that adding the Section worked

	Section secB3("B3", "Thursday", 11);
	//secB3.loadStudentsFromFile( "B3.txt" );
	secB3.addStudent("Thorin");
	secB3.addStudent("Dwalin");
	secB3.addStudent("Balin");
	secB3.addStudent("Kili");
	secB3.addStudent("Fili");
	secB3.addStudent("Dori");
	secB3.addStudent("Nori");
	secB3.addStudent("Ori");
	secB3.addStudent("Oin");
	secB3.addStudent("Gloin");
	secB3.addStudent("Bifur");
	secB3.addStudent("Bofur");
	secB3.addStudent("Bombur");

	cout << "\ntest B3\n";    // here the modeler-programmer checks that load worked
	secB3.display();          // YOU'll DO THIS LATER AS: cout << secB3 << endl;
	jane.addSection(secB3);
	jane.displayGrades();      // here the modeler-programmer checks that adding Instructor worked


							   // setup is complete, now a real world scenario can be written in the code
							   // [NOTE: the modeler-programmer is only modeling joe's actions for the rest of the program]

							   // week one activities  
	cout << "\nModeling week: 1\n";
	moe.addGrade("John", 7, 1);
	moe.addGrade("Paul", 9, 1);
	moe.addGrade("George", 7, 1);
	moe.addGrade("Ringo", 7, 1);
	cout << "End of week one\n";
	moe.displayGrades();

	// week two activities
	cout << "\nModeling week: 2\n";
	moe.addGrade("John", 5, 2);
	moe.addGrade("Paul", 10, 2);
	moe.addGrade("Ringo", 0, 2);
	cout << "End of week two\n";
	moe.displayGrades();

	//test that reset works  // NOTE: can we check that the heap data was dealt with?
	cout << "\ntesting reset()\n";
	secA2.reset();
	secA2.display();
	moe.displayGrades();
}