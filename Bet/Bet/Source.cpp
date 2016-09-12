#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	string name;
	cout << "What is your name? > ";
	cin >> name;
	int random; 
	int balance = 100;
	for (int i = 0; i < 10; i++)
	{
		
		cout << "Your balance is " << balance << endl;
		random = rand() % 100;
		cout << "How much do you want to bet? > ";
		int bet;
		cin >> bet;
		if (random < 50) 
		{
			balance -= bet;
		}
		else
		{
			balance += bet;
		}

	}
	
	ifstream ifs("Highest.txt");
	int number;
	if ((ifs >> number))
	{
		if (number <= balance)
		{
			ofstream outFile;
			outFile.open("top.txt");
			outFile << name << endl;
		}
	}

	
	
}