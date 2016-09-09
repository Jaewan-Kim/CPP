#include <iostream>
#include <string>

using namespace std;

class Player {
	string name, team, position;
	int height, weight, birthYear;
public :
	void saveAPlayer(string, string, string,int,int,int);
	void display();
};

void Player::display() {

	cout << "Player name: " << name << endl;
	cout << "Player team: " << team << endl;
	cout << "Player position: " << position << endl;
	cout << "Player height: " << height << endl;
	cout << "Player weight: " << weight << endl;
	cout << "Player birth year: " << birthYear << endl;
}
void Player::saveAPlayer(string x, string y, string z,int x1, int y2, int z2) {

	name = x;
	team = y;
	position = z;
	height = x1;
	weight = y2;
	birthYear = z2;

}

class Players {
	Player list[1];
	int numberOfPlayers=0;
public: 
	void addPlayer(Player);
	void showPlayers();
};

void Players::addPlayer(Player player) 
{
	list [numberOfPlayers] = player;
	numberOfPlayers++;
	list[numberOfPlayers] = {};
}

void Players::showPlayers() {

	for (int i = 0; i < numberOfPlayers; i++) {
	
		Player hi = list[i];
		hi.display();
	}
}

int main() {
	Players hello;
	int ui;
	do {

		cout << "[1] Add player" << endl;
		cout << "[2] Show players" << endl;
		cout << "[3] Exit" << endl;
		cout << "> ";
		cin >> ui;
		cout<<endl;
		if (ui == 1) {
			string name;
			string team;
			string position;
			cout << "Name of the player: ";

			cin >> name;

			cout << "Team of the player: ";

			cin >> team;

			cout << "Position of the player: ";

			cin >> position;
			int height; int weight; int birthYear;

			cout << "Height of the player: "; cin >> height;

			cout << "Weight of the player: "; cin >> weight;

			cout << "Birth year of the player: "; cin >> birthYear;
			Player bleh = {};
			bleh.saveAPlayer(name, team, position, height, weight, birthYear);
			
			hello.addPlayer(bleh);
		}
		else if (ui == 2) {
		
			hello.showPlayers();

		}
	} while (ui != 3);
}