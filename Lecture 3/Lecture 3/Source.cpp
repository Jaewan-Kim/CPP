#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const double TAX_RATE = 0.08875; // you can always access this variable from anywhere in the program. 
// the const prohibits any changes on this variable, meaning the value of the variable will never change.

// do not ever use a non-constant variable as a global variable

struct Date
{
	int day;
	int month;
	int year;
};
struct Person // creating an object called person
{
	string name;
	int height; // inches
	double weight;
	Date bday;
	vector <string> childrenNames;
};

int main()
{
	Person p1;
	p1.name = "Jay";
	p1.height = 68;
	p1.weight = 160;
	p1.bday.year = 1997;
	p1.bday.month = 5;
	p1.bday.day = 27;
	p1.childrenNames.push_back("No one");
	vector <Person> vp;

	vp.push_back(p1);

	for(Person p : vp)
	{
		cout << p.name << endl;
	}
	/* if you wanna change the variables in the main program, you always have to put & next to the input parameter of the function
	if there is no reference parameter, the varaibles will only use the 'copy' of the variables from the main function*/

	// when a variable is created within the scope, it cannot be accessed from outside the scope.
	
	/*
	for example,
	for (int i = 0; i < 100; i++)
			cout << i << endl;
		cout << i << endl;

		does not work because i only works within the parameter.

		@@solution :

	int i=0;
	for (i = 0; i < 100;i++)
			cout << i << endl;
		cout << i << endl;
	*/
	vector<int> v; // vector of integers


	for (int i = 0; i < 100 ; i ++)
	{
		v.push_back(i * 2); // stores a * 2 into the vector
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl; // [] allows you to access the value at the certain syntax. first index of the vector is 0. 
	}

	for (int number : v) // another way to access the values inside the vector
	{
		cout << number << endl;
	}
	v.clear(); // empties out the vector


}