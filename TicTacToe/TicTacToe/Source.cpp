#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

class Game
{
	int boxes[9] = {};
	bool turn = true;
public:
	void display();
	void logic();
};

void Game::display()
{
	system("cls");
	int five = 5;

	for (int i = 0; i < five; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < five; j++)
			{
				if (j % 2 == 0)
				{
					cout << " ";
				}
				else
				{
					cout << "|";
				}
			}
		}
		else
		{
			for (int j = 0; j < five; j++)
			{
				cout << "_";
			}
		}
		cout << endl;
	}
}

void Game::logic()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case '0':

			if (boxes[0] != "1" && boxes[0] != "0")
			{
				if (turn)
				{
					boxes[0] = "1";
				}
				else
				{
					boxes[0] = "0";
				}
				if (turn)
				{
					turn = false;
				}
				else
				{
					turn = true;
				}
			}
			else
			{
				cout << "Invalid move!" << endl;
			}
			break;

		}
	}
}

int main()
{
	Game game;
	game.display();
}