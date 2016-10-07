#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Person
{
	string name;
	Person* spouse;
public:
	Person(string newName = "") : name(newName),spouse(nullptr) {}
	void setName(string newName) { name = newName; }
	string getName() const { return name; }
	bool marry(Person& p);
	bool isMarried() const { return spouse != nullptr; }
	void divorce();
};

bool Person::marry(Person& p)
{
	if (&p == this) // you have to compare using the address, not the object itself.
		return false;//making sure that people don't marry themselves
	if (spouse != nullptr)
		return false;
	if (p.spouse != nullptr)
		return false;
	
	spouse = &p;
	p.spouse = this;
	return true;
	// private variables are not accessible outside the class.
	// therefore, you can use a pointer to access private variables.
}

void Person::divorce()
{
	if (spouse) // if the pointer points to null, then the value of this will be false.
	{
		spouse->spouse = nullptr; // this has to be done first, because you are gonna lose access to spouse.
		spouse = nullptr;
	}
}

class DynArray
{
	int numOfElements;
	int capacity;
	int * data;
public:
	DynArray() :data(new int[5]), capacity(5), numOfElements(0) {};
	void push_back(int newvalue);
	int size() const { return numOfElements; }
	int getAtPosition(int index) { return data[index]; }
	int pop_back();
	void resize(int newSize);
};

void resize(int newSize)
{
}

int DynArray::pop_back()
{
	if (numOfElements>0)
		return data[--numOfElements];
	return 0;
}

void DynArray::push_back(int newvalue)
{
	if (numOfElements == capacity)
	{
		resize(numOfElements * 2);
	}
	data[numOfElements++] = newvalue;
}

int main()
{
	Person* pptr;
	pptr = new Person("Jack");
	Person p("Jill");

}