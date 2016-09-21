#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

// continues from the last lecture.

using namespace std;

class Card
{
	char suit; // variables are private by default
	int value; // J = 11; Q = 12; K = 13; A =1
public:

	Card(char newSuit, int newValue);
	int getValue() const { return value; }
	char getSuit() const;
	bool setValue(int newval);

};


/*
Card::Card() // default constructor
{
	value = 1;
	suit = 'S';
}
*/
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




class DeckOfCards
{
	int originalNumber;
	vector <Card> cards;
	

public:
	DeckOfCards(int numOfCards = 52) :originalNumber(numOfCards) {
		shuffle();
	}; // default and one argument constructor
	void shuffle();
	Card deal();
	void addCard(Card card);
	int remaining() const { return cards.size(); };
};

void DeckOfCards::addCard(Card card)
{
	cards.push_back(card);
}

void DeckOfCards::shuffle()
{
	cards.clear();
	string suits = "CSDH";
	int cardNum = 0;
	while (cardNum < originalNumber)
	{
		Card temp( suits[(cardNum %52) / 13],(cardNum %13)+1 );
		cards.push_back(temp);
		cardNum++;
	}

}

Card DeckOfCards::deal()
{

	int num = rand() % cards.size();
	Card retval = cards[num];
	cards[num] = cards[cards.size() - 1];
	cards[cards.size() - 1] = retval; // not needed.

	cards.pop_back();
	return retval;
}


int main()
{
/*
	Card c;
	cout << c.getValue() << endl; // returns 1;
	Card other('H', 10);

	cout << other.getSuit() << other.getValue() << endl; // returns H 10
	*/

	DeckOfCards d;
	srand(time(NULL));
	while (d.remaining() != 0)
	{
		Card temp = d.deal();
		cout << temp.getSuit() << temp.getValue() << endl;
	}
	
}

/*

the difference between x++ and ++x

int x = 5;

int y;

y = x++;

cout << x ; // 6
cout << y; // 5

int x = 5;

int y;

y = ++x;

cout << x ; // 6
cout << y; // 6

*/