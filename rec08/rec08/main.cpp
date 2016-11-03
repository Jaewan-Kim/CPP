#include "Registrar.h"
#include <iostream>
#include <string>

using namespace BrooklynPoly;
using namespace std;

int main()
{

	Registrar registrar;

	cout << "No courses or students added yet\n";
	registrar.printReport();

	cout << "AddCourse CS101.001\n";
	registrar.addCourse("CS101.001");
	registrar.printReport();

	cout << "AddStudent FritzTheCat\n";
	registrar.addStudent("FritzTheCat");
	registrar.printReport();

	cout << "AddCourse CS102.001\n";
	registrar.addCourse("CS102.001");
	registrar.printReport();

	cout << "enrollStudent FritzTheCat CS102.001\n";
	registrar.enrollStudent("FritzTheCat", "CS102.001");
	cout << "enrollStudent FritzTheCat CS101.001\n";
	registrar.enrollStudent("FritzTheCat", "CS101.001");
	registrar.printReport();

	cout << "enrollStudent Bullwinkle CS101.001\n";
	cout << "Should fail, i.e. do nothing, since Bullwinkle is not a student.\n";
	registrar.enrollStudent("Bullwinkle", "CS101.001");
	registrar.printReport();

	cout << "CancelCourse CS102.001\n";
	registrar.dropCourse("CS102.001");
	registrar.printReport();


	// [OPTIONAL - do later if time]
	cout << "ChangeStudentName FritzTheCat MightyMouse\n";
	registrar.changeStudentName("FritzTheCat", "MightyMouse");
	registrar.printReport();

	cout << "DropStudentFromCourse MightyMouse CS101.001\n";
	registrar.printReport();

	cout << "RemoveStudent FritzTheCat\n";
	registrar.dropStudent("FritzTheCat");
	registrar.printReport();


	cout << "Purge for start of next semester\n";
	registrar.purge();
	registrar.printReport();
}