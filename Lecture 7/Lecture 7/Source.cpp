#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void func1()
{
	int *y = new int(100);
	delete y; // never forget to delete the pointer after use.
}

void func2(int* arr) // when using a pointer as the parameter, you don't need to put & to reference it.
{
	arr[5] = 100;


}

void func3(int* arr)// the array in the main function will be deleted. 
{
	delete[] arr;
	arr = new int[100]; // new array will be created, and the 7th element will be given the value of 100.
	arr[6] = 100;
	// however, the pointer arr doesn't get returned to the main function and the array will cause a memory leak.
	// if you add & next to int* in the parameter, the problem will be solved.
}

int main()
{
	int x = 5;
	int *y = &x;

	y = new int(100);

	delete y;

	for (int i = 0; i < 10000000000; i++)
	{
		func1();
	}

	// deleting a nullptr is valid.

	y = nullptr;

	delete y;

	// however, double deleting is prohibited. the program will crash no matter what.

	// interestingly, double deleting a nullptr won't crash the program, because it doens't do anything in the first place.

	int *z = new int(100);
	y = new int(200);
	int *w = z;
	z = y;
	y = w;
	delete y;
	delete z;
	delete w;

	// the problem with the program above is that y and w are pointing to the same variables.

	// use paper to keep track of pointers.

	// creating a single variable in the heap may be pointless

	// however, making arrays in the heap may be beneficial


	int sarr[5]; // an array of 5 elements. cannot change the size of it.
	// even non-constant variables cannot be used to create an array.

	//however, when the array is created on the heap, the variable can be used.
	int size = 100;
	z = new int[size];

	// z can be used like a regualr array.

	z[1] = INT_MAX;
	z[2] = INT_MIN;

	// element base = base of array(pointer) + index(given) * size of one element(based on datatype)
	
	// the size of the element is known based on the datatype

	// the equation up there is the reason why the index of the first element is 0

	delete[] z; // this deletes the whole array. if there are no brackets, only the first element will be deleted
	// cout << z[6]
	// and cout << *(z+6) function the same way

	int * other = z + 6;

	//other[0] is equal to z[6]
	// other [1] is equal to z [7]

	int *confusing = other + 2;
	// confusing will point to the 8th element of z

	int* thing1, thing2;
	// this will not create 2 pointers. only thing1 will be a pointer
	cout << *confusing++ << endl; 
	// this will print out *(confusing++) not the value of *confusing + 1


	/*suppose that there is a class called person with a function
	getname. when you create the class using a pointer, the function
	getname can be accessed this way.
	
	Person pptr;
	(*pptr).getname() or *pptr-> getname()*/

}