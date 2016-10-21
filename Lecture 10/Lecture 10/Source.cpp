#include <iostream>
#include <string>

using namespace std;

//continuing from the last lecture




class Pet
{
	string name;
	int age;
protected: // protected variables are private, but accessible through its derivative classes.
	string color;
public:
	Pet() : age(0) {} // constructors are NEVER derived to the inherited classes
	Pet(string newName) : name(newName), age(0) {}
	string etColor() const { return color; }
	string getName() const { return name; }
	int getAge() const { return age; }
	void rename(string newName) { name = newName; }
	void paint(string newcolor) { color = newcolor; }
	void celebrateBirthday() { age++; }
};

class Dog : public Pet // even though the class dog is a derivative of the class pet, you cannot access the private variables from the class dog
{
	string breed;
public :
	Dog(string newname = "") :Pet(newname){} // this creates a new dog class with the age 0 and the name of newname
	void speak() { cout << "Woof Woof." << endl; }
	void setBreed(string newBreed) { breed = newBreed; }
	string getBreerd()const { return breed; }
	void celebrateBirthday(); //OVERRIDE
};

void Dog::celebrateBirthday() 
{
	Pet::celebrateBirthday(); // this accesses the celebrate birthday from the pet class
	if (getAge()>10)
		color = "Grey";
}

class BaseMember
{
public:
	BaseMember() { cout << "BaseMember Default constructor" << endl; }
};

class DerivedMember
{
public:
	DerivedMember() { cout << "DerivedMember Default constructor" << endl; }
};
class Base
{
	BaseMember m;
public:
	Base() { cout << "Base Default Constructor" << endl; }
	Base(int n) { cout << "Base one arguemnt constructor" << endl; }
	void BaseFunc() { cout << "Inside Bases's Basefunc." << endl; }
};

class Derived : public Base
{
	DerivedMember m2;
public:
	Derived() { cout << "Derived Default Constructor" << endl; }
	Derived(double n) { cout << "Derived one argument constructor" << endl; }
	Derived(double n, int y) :Base(y) { cout << "Derived two argument constructor" << endl; }
	void BaseFunc() { cout << "Inside Derived's BaseFunc." << endl; }
	void DerivedFunc() { cout << "Inside DerivedFunc." << endl; }
};

int main()
{
	Base baseObj;
	Derived derivedObj;

	baseObj = derivedObj; // this is allowed

	int x=0;
	double d=5.5;
	x = d; // this works as well
	//however, it will not have the extra stuff
	// therefore, if you set the baseobj equal to the derivedobj, the extra stuff will not be copied
	//this is called slicing

	//derivedObj = baseObj is not allowed right now

	Base* basePtr = &derivedObj;//this would work because the derived object is technically a base.
	//basePtr -> DerivedFunc(); // we cannot do this
	basePtr->BaseFunc(); // however, this will call the basefunc from the base, not the derivated

	//polymorphism, always allowed.
	//poly - many, morphos - face
	//however, you cannot use a derived pointer to point to a base object.

	/*cout << "**********Making a derived*******" << endl;
	Derived d1;
	cout << "**********Completed*************" << endl;
	// displays Base Default Constructor and then Derived Default Constructor
	cout << "**********Making a derived with one argument constructor***" << endl;
	Derived d2(2);
	cout << "************completed" << endl;

	cout << "*****Making a derived with two constructors " << endl;
	Derived d3(3, 1);
	cout << "**************completed" << endl;
	*/
}
