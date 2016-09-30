// Jaewan Kim N14750277

/*
This is a simple game.

The game will read an input file and collect the data from it and compile the commands.

There are three commands: warrior, battle, and status.

When the command warrior is called, the game will add a warrior to the vector of warriors.

When the command battle is called, two warriors that come after the command will battle each other.

Status command will display the name and the weapons of the warriors.

*/


#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// this is a variable that will be given to the dead warriors. since it will not change, const was put there.
int const dead = 0;

// class weapon consists of the name and the strength of the weapon.
class Weapon 
{
	string name;
	int strength;
public:
	Weapon(string newname, int newstrength) : name(newname), strength(newstrength) {}
	int getStrength() const { return strength; }
	string getName() const { return name; }
	void setStrength(int newstrength) { strength=newstrength; } // after a warrior battles another, the strength of the weapon will be changed using this function
};

// class warrior consists of the name of the warrior and the weapon of the warrior.
class Warrior 
{
	string name;
	Weapon  weapon;
public: 
	Warrior(string newname, Weapon newweapon) : name(newname), weapon(newweapon) {}
	Weapon getWeapon() const { return weapon; }
	string getName() const { return name; }
	// the following two functions call in functions from the weapon class to make the code more readable in the main function.
	int getWeaponStrength() const { return weapon.getStrength(); }
	void setWeaponStrength(int newstrength) { weapon.setStrength(newstrength); } 
};

// this function will take in a vector of warriors as a parameter and display each warrior in the form of
// Warrior: Name, weapon: Weapon, Strength
void display(vector<Warrior> warriors)
{
	for (Warrior temp : warriors)
	{
		cout << "Warrior: " << temp.getName() << ", weapon: " << temp.getWeapon().getName() << ", " << temp.getWeapon().getStrength() << endl;
	}
}

// battle function takes in the vector of warriors and the names of the warriors.
vector<Warrior> battle(vector<Warrior>& warriors, string name1, string name2)
{
	vector<Warrior> warriors2;
	Weapon tempweapon("",1);
	Warrior warrior1("", tempweapon );
	Warrior warrior2("",tempweapon);
	
	// this for loop will find the warriors with the names given, and then store the warriors into temporary variables.

	for (Warrior temp : warriors)
	{
		if (temp.getName() == name1)
		{
			warrior1 = temp;
		}
		else if (temp.getName() == name2)
		{
			warrior2 = temp;
		}
		
	}

	/*
	when the temporary warriors were declared, they were given names of "". Therefore, the following if structure
	will make sure that the temporary warriors don't have the name of "", meaning that the if structure will make sure that
	the warriors with the given names exist inside the vector.
	*/
	if (warrior1.getName() != "" && warrior2.getName() != "")
	{
		cout << name1 << " battles " << name2 << endl;
 		int weapon1 = warrior1.getWeaponStrength();
		int weapon2 = warrior2.getWeaponStrength();
		// the if structure below will compare the strengths of the warriors and 
		// display the results and change the strength values accordingly.
		if (weapon1 == dead && weapon2 == dead)
		{
			cout << "On, NO! They're both dead! Yuck!" << endl;
		}
		else if (weapon1 == dead)
		{
			cout << "He's dead, " << name2<<endl;
		}
		else if (weapon2 == dead)
		{
			cout << "He's dead, " << name1 << endl;
		}
		else if (weapon1 == weapon2)
		{
			warrior1.setWeaponStrength(dead);
			warrior2.setWeaponStrength(dead);
			cout << "Mutual Annihilation: " << name1 << " and " << name2 << " die at each other's hands" << endl;
		}
		else if (weapon1 > weapon2)
		{
			warrior1.setWeaponStrength(weapon1 - weapon2);
			warrior2.setWeaponStrength(dead);
			cout << name1 << " defeats " << name2 << endl;
		}
		else
		{
			warrior1.setWeaponStrength(dead);
			warrior2.setWeaponStrength(weapon2 - weapon1);
			cout << name2 << " defeats " << name1 << endl;
		}

		/*
		this for loop modifies the warriors2 vector, which will be returned to the main program.

		when it was initialized, vector was set equal to the vector given as the parameter.

		this for loop will check for the names given and replace the values will the temporary warriors which have been modified in the if structure above.
		*/
		for (Warrior wa : warriors)
		{
			if (wa.getName() == name1)
			{
				warriors2.push_back(warrior1);
			}
			else if (wa.getName() == name2)
			{
				warriors2.push_back(warrior2);
			}
			else
			{
				warriors2.push_back(wa);
			}
		}
	}
	return warriors2;
}

int main()
{
	// opens file.
	ifstream ifs;
	string filename = "warriors.txt";
	ifs.open(filename);
	string command;
	string warr= "Warrior";
	string bat = "Battle";
	string stat = "Status";
	vector<Warrior> warriors;
	// the while loop takes one command at a time
	while (ifs >> command)
	{
		// if command is equal to "Warrior", then the if structure will add a warrior to the warriors vector.
		if (command == warr)
		{
			string name;
			string weaponname;
			int strength;
			ifs >> name >> weaponname >> strength;
			Weapon newWeapon(weaponname, strength);
			Warrior newWarrior(name, newWeapon);

			warriors.push_back(newWarrior);
		}
		// if the command is equal to "Status", the program will display the status of the warriors.
		else if (command == stat)
		{
			cout << "There are: " << warriors.size() << " warriors" << endl;
			display(warriors);
		}
		// if the command is equal to "Battle" , the program will start a battle. 
		else if (command == bat)
		{
			string name1;
			string name2;
			ifs >> name1 >> name2;
			warriors = battle(warriors,name1, name2);

		} 
	}
	// closes the file opened. 
	ifs.close();
}