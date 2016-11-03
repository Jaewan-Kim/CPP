#include <iostream>
#include <vector>
#include <string>

using namespace std;

// continued from lecture 14

class DynArray
{
	int* data;
	int numOfElements; // how many push_backs
	int sizeOfData; // capacity

public:
	DynArray() :data(new int[5]), sizeOfData(5), numOfElements(0) {}
	~DynArray() { delete[] data; } // destructor.
	DynArray(const DynArray& rhs) :data(nullptr) { *this = rhs; }; // copy constructor
	DynArray& operator= (const DynArray& rhs); // assignment operator
	int operator[] (int index) const { return data[index]; }
	int& operator[](int index) { return data[index]; }
	void push_back(int item);
	int pop_back();
	int size()const { return numOfElements; }
	int capacity() const { return sizeOfData; }
	void clear();
	void resize(int newSize);
};

void DynArray::resize(int newSize)
{
	int * temp = new int[newSize];
	if (newSize < numOfElements)
		numOfElements = newSize;

	for (size_t i = 0; i < numOfElements; i++)
		temp[i] = data[i];

	delete[] data;
	data = temp;
	sizeOfData = newSize;
}

void DynArray::clear()
{
	delete[] data;
	data = new int[5];
	sizeOfData = 5;
	numOfElements = 0;
}

int DynArray::pop_back()
{
	int retval;
	if (numOfElements > 0)
	{
		retval = data[--numOfElements];
	}
	return retval;
}

void DynArray::push_back(int item)
{
	if (numOfElements == sizeOfData)
		resize(sizeOfData * 2);

	data[numOfElements++] = item;
}

DynArray& DynArray :: operator= (const DynArray& rhs)
{
	if (this == &rhs) // test for self-assignment
		return *this;
	
	delete[] data;
	data = new int[rhs.numOfElements];

	numOfElements = rhs.numOfElements;
	for (int i = 0; i < numOfElements; i++)
		data[i] = rhs.data[i];
	sizeOfData = numOfElements;
	return *this;
}

//the problem with the copy constructor is that if two different dynarrays point to the same pointers, it's easy for you to double delete
int main()
{
	
}