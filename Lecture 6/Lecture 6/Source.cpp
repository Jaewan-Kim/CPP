#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
// main memory is organized boxes (like an array, very big)

/* 
numen-architecture
64-bit operating system means that the size of the address in the main memory is up to 2^64. 
therefore, 32-bit operating system can only contain up to 2^ 32, or 4GB.

2^64 can contain up to 1.8 exabytes(billion gigs)

each individual boxes, or bytes have unique addresses

when the code calls for an int, the operating system will assign a specific address to store the integer. (int is 4 bytes on average)

C++ only cares about where the 'address' starts.

a pointer is a way to store the memory address

* the pointer does not store the value.

the pointer only stores the memory address.

pointers have to be pointed something.

pointers are variable type specific

int pointers point to integers! double pointers point to doubles!

we always need to know where the pointer is pointed at 

dereferencing a null will crash the program immediately. One of the 3 biggest errors with pointers.
second error is the double delete. 
garbage on the heap (memory leak) // you need to make sure that you delelte the garbage values
*/

class Person {
	Person * mom;
	Person * dad;
	string name;
public: 
	string getName() const { return name; }
	Person(string newName = "", Person* newMom = nullptr, Person * newDad = nullptr) :mom(newMom), dad(newDad), name(newName) {}
	string getMomName() const { return (*mom).getName(); }
};
int main() 
{
	int x = 5;
	int * z; // dangling pointer
	z = nullptr;
	z = &x; //address-of operator. this will store the memory address, not the memory value.
	cout << z; // displays the address of the variable x;
	cout << *z; // dereference operator. goes to the pointer and follows where the pointer is pointing to. therefore, this will display 5.
	Person mom("asdf");
	Person me("jay", &mom);
	cout << me.getMomName();
	// variables on the heap cannot have a name. therefore, we need to use pointers 

	int * y = new int;
	*y = 100;
	cout << *y;
	delete y; // deletes what the pointer points to 
	int x1 = 2000;

	int* y1 = &x;
	int z1 = 100;
	*y += 20;

	cout << x1;
}