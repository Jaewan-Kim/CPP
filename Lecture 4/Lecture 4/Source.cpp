#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Card
{
	char suit; // variables are private by default
	int value; // J = 11; Q = 12; K = 13; A =1
public:
	Card(); //default constructor
	Card(char newSuit, int newValue);
	int getValue() const { return value; }
	char getSuit() const;
	bool setValue(int newval);

};
Card::Card()
{
	value = 1;
	suit = 'S';
}

Card::Card(char newSuit, int newValue)
{
	if (newSuit != 'C' && newSuit != 'S' && newSuit != 'D' && newSuit != 'H')
	{
		suit = 'S';
	}
	else
		suit = newSuit;
	if (newValue > 13 || newValue <= 0)
	{
		value = 1;
	}
	else
		value = newValue;
}

bool Card::setValue(int newValue)
{
	if (newValue <= 13 && newValue > 0)
	{
		value = newValue;
		return false;
	}
	return true;
}

char Card::getSuit() const
{
	return suit; // different ways of constructing a function for a class
}
int main()
{
	Card c;
	cout << c.getValue() << endl;
	Card other('H', 10);

	cout << other.getSuit() << other.getValue() << endl;
}