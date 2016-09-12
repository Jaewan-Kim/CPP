#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	cout << "Filename: ";
	string filename;
	cin >> filename;
	ofstream outFile;
	outFile.open(filename); // creates the file with the name of filename

	ifstream inFile;
	inFile.open("input.txt");
	if (!inFile) 
	{
		cout << "FILE DOES NOT EXISTS!!!";
		return 1;
	}

	char letter;
	while (inFile >> letter) 
	{
		double number;
		inFile >> number;
		if (letter == 'C')
		{
			outFile << number << endl;
		}
		else if (letter == 'K')
		{
			outFile << (number - 273) << endl;
		}
		else if (letter == 'F')
			outFile <<(5.0/9*(number-32))<<endl;
	}

	outFile << "Hello world!" << endl; // decides what goes in the file
	outFile.close(); // optional
	int x;
	x = 100;
	if (x > 1000)
		if (x > 2000)
			cout << 'A';
		else
			cout << 'B';
	// whitespace doesn't matter
	// therefore, nothing will be printed


	for (int i = 0; i < x; i++) // initialization; test; incrementation. however, these are optional(the semi-colons are not optional)
	{
		cout << x; // condition		
	}

	cout<<pow(4, 2); // pow(base,exp)
}