#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Person
{
private:
	string name;
};

class BigInt
{
	int data;
public:
	BigInt(int x = 0) : data(x) {}
	BigInt& operator -= (const BigInt& rhs);
	BigInt operator*(const BigInt& rhs) { return data / rhs.data; } // you can do this!
	bool operator<(const BigInt& rhs)const { return data < rhs.data; }// instead of writing all the other functions you can just write b <a or ! (b < a) etc in the main
	// a> c -> b <a 
	//a <= b -> !(b<a)
	// a >= b -> !(a<b)
	// a == b -> !(a<b||b<a)
	// a != b -> a <b || b < a
	bool operator> (const BigInt& rhs) const { return rhs < *this; } // this is useful when the first operator takes a lot of lines to code
	bool operator<= (const BigInt& rhs) const { return !(rhs < *this); }
	bool operator >= (const BigInt& rhs) const { return !(*this < rhs); }
	bool operator == (const BigInt& rhs) const { return !(*this < rhs || rhs < *this); }
	bool operator != (const BigInt& rhs) const { return *this < rhs || rhs < *this; }
	BigInt& operator++() 
	{//pre-increment operator ++x
		data++;
		return *this;
	}
	BigInt& operator++(int) // if there is an integer as a parameter, c++ will see it as the post increment operator
	{
		BigInt temp = *this;
		data++;
		return temp;
	}
	friend ostream& operator<<(ostream& outs, const BigInt& rhs); // this allowes the nonmember function overload to have access to the private variable, data	
	// classes can be functions as well
	friend Person;
};

// the law of associativity doesn't apply the same in c++.
// only return by reference if you are returning something that you have created already

// if the returning variable only exists within the function, return by value

BigInt operator-(const BigInt& lhs, const BigInt& rhs)
{
	BigInt temp = lhs;
	temp -= rhs;

	return temp;
}

BigInt& BigInt :: operator -= (const BigInt& rhs)
{
	data -= rhs.data;
	return *this;
}

ostream& operator<<(ostream& outs, const BigInt& rhs) // streams are always passed by reference
{
	// friends have access to their private variables
	outs << rhs.data << endl; // data is not accessible from here
	return outs;
}

int main()
{
	//trivia : eps + eps = eps
	
	// the difference between x= a++ and x = ++a is the return values

	int x;
	int a = 5;
	x = a++; // returns by value
	cout << "a++: " << x << endl;
	cout << a << endl;
	a = 5;
	x = ++a; // returns by reference
	cout << "++a" << x << endl;
}