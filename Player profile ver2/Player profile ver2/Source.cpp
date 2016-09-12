#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Player 
{
private:
	string name, team, position, birthyear;

public: 
	void createPlayer(string, string, string, string);
	void display();
	void deletePlayers();
};

void Player::deletePlayers()
{
	ofstream outFile;
	outFile.open("players.txt");
	
}

void Player::display() 
{
	ifstream ifs("players.txt");
	ifs.clear();
	ifs.seekg(0);
	string line;
	while (getline(ifs, line)) {

		cout << line << endl;
	}
}
void Player::createPlayer(string x, string y, string z, string birth) 
{
	name = x;
	team = y;
	position = z;
	birthyear = birth;
	string input = name + ", " + team + ", " + position + ", " + birthyear;
	ofstream outFile;
	outFile.open("players.txt", ios::app);
	outFile << input << endl;
}
int main() 
{
	Player player;
	int input=0;
	while (input != 4) 
	{
		cout << "[1] Add a player." << endl;
		cout << "[2] Display players." << endl;
		cout << "[3] Reset the players list." << endl;
		cout << "[4] Quit program." << endl;
		cout << "> ";
		cin >> input;
		cin.ignore();
		if (input == 1) 
		{
			string name;
			cout << "Name of the player: "; getline(cin, name); 
			string team; cout << "Team of the player: "; getline(cin,team); 
			string position; cout << "Position of the player: "; getline(cin, position); 
			string birthyear; cout << "Birthyear of the player: "; cin >> birthyear; 
			player.createPlayer(name, team,position,birthyear);
		}
		else if (input == 2) 
		{
			player.display();
					
		}
		else if (input == 3)
		{
			player.deletePlayers();
		}
	}
}