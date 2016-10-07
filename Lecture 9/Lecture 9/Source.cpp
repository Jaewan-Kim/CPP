#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
//continued from the last lecture
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

void DynArray::resize(int newSize)
{
	if (newSize < numOfElements)
	{
		numOfElements = newSize;

	}

	int * temp = new int[newSize];
	for (int i = 0; i < numOfElements; i++) 
		temp[i] = data[i];

	delete[] data; // you always gotta remember to delete something that pointer doesn't point to anymore

	data = temp;
	capacity = newSize;
}


class Pet 
{
	string name;
	string color;
	int age;
public:
	Pet() : age(0) {}
	Pet(string newName) : name(newName), age(0) {}
	string etColor() const { return color; }
	string getName() const { return name; }
	int getAge() const { return age; }
	void rename(string newName) { name = newName; }
	void paint(string newcolor) { color = newcolor; }
	void celebrateBirthday() { age++; }
};

class Dog : public Pet // inheritance. dog is a pet, but pet is not always a dog
{
	// the class dog will be able to access the functions and variables of the pet class
	// however, you can add specific properties that only apply to dogs.


};
int main()
{
	//you cannot know when the array ends

	//therefore, make sure that you always keep up with the array that you create

	//c++ does not have any protections for the wrong usage of pointers
	Dog good;
	good.rename("Fido");
	
}