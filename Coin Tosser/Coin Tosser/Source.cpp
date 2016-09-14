#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	while (true)
	{
		int heads=0;
		int tails=0;
		cout << "Number of coins: ";
		int numberOf;
		cin >> numberOf;
		cout << "     ";
		
		for (int i = 0; i < numberOf; i++) 
		{
			int number;
			number = rand() % 100;
			cout << i + 1 << ": ";
			if (number < 50)
			{
				cout << "  Heads   " << endl; heads++;
			}
			else
			{
				cout << "  Tails   " << endl;; tails++;
			}
		}

		cout << heads << " head(s) and " << tails << " tail(s)" << endl;
		if (numberOf == 0)
		{
			break;
		}
	}
}