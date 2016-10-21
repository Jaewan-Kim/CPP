//virtual function--

/*
virtual allows a base pointer to point to the derived classes' functions as well.

pure virtual makes the base function an abstract class.

abstract class cannot be created.

the only thing that you can do with an abstract class is creating a pointer for it.

however, the pointer cannot point to the abstract class, but only the derived classes.

if you don't override the pure virtual functions in the derived classes,
the pure virtual functions will be passed on and make the derived classes
also abstract classes.

therefore, whenever you create a pure virtual function, make sure that you override 
the function in the derived classes.

**you can never create an instance of an abstract class**

the difference between pure virtual and virtual is that virtual still needs some code
*/

//lesson on operators

//overriding an operator is called operator overloading

// member vs non-member

// operators that cannot be overloaded = sizeOf, ., ?:, ::, .*  (there's really no point of overloading these anyway)
// operators which must be members = =, []
// (restrictions in reality) operators that are almost impossible to be overloaded by members = << , >>

// benefit of being non-member

#include <iostream>
#include <string>

using namespace std;

class BigInt
{
	int data;
public:
	BigInt(int x=0) : data(x) {} 
	BigInt operator+(const BigInt& rhs) { return data + rhs.data; } // member overload int turns into bigint because of the constructor
	int getData() const { return data; }
};

BigInt operator-(const BigInt& lhs, const BigInt& rhs) // non-member. basically, c++ constructs a bigint using the int and returns it
{
	return lhs.getData() - rhs.getData();
}
int main()
{
	BigInt a(100), b(200), c;
	c = a + b;
	c = a + 5;
	c = 5 + a; // this doesn't work because the first varialbe needs to be a big int

	c =a - b;
	c = a - 5;
	c = 5 - a;
	// however, you'll realize that subtraction works even when the int comes before bigint!

	//that's the benefit of non member overloading.
}