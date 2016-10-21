// Jaewan Kim
// 14750277

// hw04

// this takes the noble/warrior game from last week, and adds more features to it.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Warrior;
class Noble; 

// class warrior did not really change
class Warrior
{
	string const name; // name is constant and cannot be changed!
	int strength; // however, the strength is able to be changed
public:
	Warrior(string name = "", int strength = 0) : name(name), strength(strength) {}
	// this is the constructor for this class
	string getName() const { return name; }  // this will just return the name of the warrior
	int getStrength() const { return strength; } // same thing as above, but for strength.
	void setStrength(int newstrength) { strength = newstrength; } // this function is used to assign a new strength
	void display() const { cout << name << ": " << strength << endl; } // the good ol' display function
};

// class noble didn't really change either
class Noble
{

	int const dead = 0; // just a constant variable to be used when the warriors die in a battle

	string const name; 
	vector <Warrior*> army;
public:
	Noble(string name = "") :name(name) {} // default constructor
	bool hire(Warrior& warrior);
	void display();
	Warrior* fire(string name);
	void battle(Noble& contestant);
	string getName() const { return name; } // returns the name.
	void clear();
};

// this function goes through the vector of the warriors under this noble and deletes all of the pointers
void Noble::clear()
{
	for (Warrior* warrior : army)
		delete warrior;
}

// this function checkes whether the specific warrior was hired already or not and if not, adds the warrior and returns true
bool Noble::hire(Warrior& warrior)
{
	for (Warrior* wr : army)
	{
		if (wr == &warrior)
		{
			return false;
		}
	}
	army.push_back(&warrior);
	return true;
}

// this display calls in the display function from the warrior class
void Noble::display()
{
	cout << this->name << " has an amry of " << army.size() << endl;

	for (Warrior* wr : army)
	{
		cout << "        " << wr->getName() << ": " << wr->getStrength() << endl;
	}
}

// firing is done using the string of name. this function checks if there is a warrior in the army with the
// same name as the parameter and if there is, then fires the warrior and returns it back to main
Warrior* Noble::fire(string name)
{
	vector<Warrior*> updatedarmy;
	Warrior* tempw = nullptr;
	for (Warrior* wr : army)
	{
		if (wr->getName() == name)
		{
			tempw = wr;
		}
		else
		{
			updatedarmy.push_back(wr);
		}
	}

	if (updatedarmy.size() != army.size())
	{
		army = updatedarmy;
		cout << tempw->getName() << ", you're fired! -- " << name << endl;
		return tempw;
	}
	return nullptr;
}

// WAR! the logic is the same as last week, but i got rid of the getArmy function
void Noble::battle(Noble& contestant)
{

	cout << name << " battles " << contestant.getName() << endl;
	int total = 0;
	for (Warrior* wr : army)
	{
		total += wr->getStrength();
	}

	int total2 = 0;
	for (Warrior* wr : contestant.army)
	{
		total2 += wr->getStrength();
	}

	if (total == dead)
	{
		if (total2 == dead)
		{
			cout << "Oh, NO! They're both dead! Yuck!" << endl;
		}
		else
		{
			cout << "He's dead " << contestant.getName() << endl;
		}
	}
	else
	{
		if (total2 == dead) 
		{
			cout << "He's dead " << name << endl;
		
		}
		else
		{

			if (total == total2)
			{
				cout << "Mutual Annihalation: " << name << " and " << contestant.getName() << " die at each other's hands" << endl;

				for (Warrior* wr : army) 
				{
					wr->setStrength(dead);
				}

				for (Warrior* wr : contestant.army) 
				{
					wr->setStrength(dead);
				}
			}

			else if (total > total2)
			{
				cout << name << " defeats " << contestant.getName() << endl;
				double ratio = (double)total2 / (double)total; 
				for (Warrior* wr : army) 
				{
					int temp = wr->getStrength();
					int strength = temp;
					temp = temp * ratio; 
					wr->setStrength(strength-temp);
				}

				for (Warrior* wr : contestant.army) 
				{
					wr->setStrength(dead);
				}

			}

			else
			{
				cout << contestant.getName() << " defeats " << name << endl;
				double ratio = (double)total / (double)total2;
				for (Warrior* wr : army) 
				{
					wr->setStrength(dead);

				}

				for (Warrior* wr : contestant.army) 
				{
					int temp = wr->getStrength();
					int strength = temp;
					temp = temp * ratio;
					wr->setStrength(strength-temp);
				}

			}

		}
	}
}

int main()
{
	// opening the file
	ifstream ifs;
	string filename = "nobleWarriors.txt";
	ifs.open(filename.c_str());

	//vectors for nobles and warriors that are not hired are created (uses pointers)
	vector <Noble*> nobles;
	vector <Warrior*> available;
	// checks whether the file was opened or not
	if (ifs)
	{
		string command;

		while (ifs >> command) // reads in the command
		{
			if (command == "Noble") // if the command is noble, then it checks whether a noble with the same name exists or not 
			{
				string name;
				ifs >> name;
				bool alreadyexists = false;
				for (Noble* noble : nobles)
				{
					if (noble->getName() == name)
					{
						alreadyexists = true;
					}
				}

				if (!alreadyexists) // because a noble with the same name doesn't exist, a new noble is created on the heap&added to the nobles vec
				{
					Noble* nptr = new Noble(name);
					nobles.push_back(nptr);
				}
				else
					cout << "This noble exists already!\n";
			}
			else if (command == "Warrior") // checks whether there is any available warrior with the same name or not 
			{
				string name;
				int strength;
				ifs >> name >> strength;
				bool alreadyexists = false;
				for (Warrior* warrior : available)
				{
					if (warrior->getName() == name)
					{
						alreadyexists = true;
					}
				}

				if (!alreadyexists) // if there isn't one, then a new warrior is created
				{
					Warrior* wptr = new Warrior(name,strength);
					available.push_back(wptr);
				}
				else
				{
					cout << "This warrior exists already!\n";
				}
			}
			else if (command == "Hire") // before hiring, the for loops will cehck whether the noble and the warrior exist or not
			{
				string noblename;
				string warriorname;
				ifs>>noblename>>warriorname;
				bool nobleexists = false;
				bool warriorexists = false;
				Noble* tempn = nullptr;
				Warrior* tempw = nullptr;
				int index;
				for (Noble* noble : nobles)
					if (noble->getName() == noblename)
					{
						nobleexists = true;
						tempn = noble;
					}
				for (int i = 0; i < available.size(); i++)
					if (available[i]->getName() == warriorname)
					{
						warriorexists = true;
						tempw = available[i];
						index = i;
					}

				if (nobleexists && warriorexists)
				{
					tempn->hire(*tempw);

					available[index] = available[available.size() - 1];
					available.pop_back();
				}
				else if (nobleexists)
					cout << "Are you sure that the warrior exists?\n";
				else if (warriorexists)
					cout << "The noble doesn't exist!\n";
				else
					cout << "NO ONE EXISTS!\n";
			}
			else if (command == "Fire") // same thing as hire.
			{
				string noblename;
				string warriorname;
				ifs >> noblename >> warriorname;
				bool nobleexists = false;
				Noble* tempnoble = nullptr;
				for (Noble* noble : nobles)
				{
					if (noble->getName() == noblename)
					{
						nobleexists = true;
						tempnoble = noble;
					}
				}
				if (nobleexists)
				{
					Warrior* warriorexists = tempnoble->fire(warriorname);
					if (warriorexists)
					{
						available.push_back(warriorexists);
					}
					else
					{
						cout << "The warrior doesn't exist!\n";
					}
				}
				else
				{
					cout << "Make sure that you aren't making someone up!" << endl;
				}

			}
			else if (command == "Battle") // battle checks whether both nobles exist or not
			{
				string name1;
				string name2;
				ifs >> name1 >> name2;
				Noble* noble1 = nullptr;
				Noble* noble2 = nullptr;
				for (Noble* noble : nobles)
				{
					if (noble->getName() == name1)
						noble1 = noble;
					else if (noble->getName() == name2)
						noble2 = noble;
				}
				if (noble1 && noble2)
				{
					noble1->battle(*noble2);
				}
				else if (noble1)
				{
					cout << "The first noble doesn't exists!" << endl;
				}
				else if (noble2)
					cout << "The second noble doesn't exist!\n";
				else
					cout << "Both of the nobles don't exist!\n";
			}
			else if (command == "Status") // this will just call in display function
			{
				cout << "Status" << endl;
				cout << "======" << endl;
				cout << "Nobles:" << endl;
				if (nobles.size() == 0)
					cout << "NONE\n";
				else
				{
					for (Noble* noble : nobles)
						noble->display();
				}
				cout << "Unemployed Warriors:" << endl;

				if (available.size() == 0)
				{
					cout << "NONE" << endl;
				}
				else
				{
					for (Warrior* warrior : available)
						warrior->display();
				}
			}
			else if (command == "Clear") 
			{
				for (Noble* noble : nobles) // deletes the hired warriors of the specific noble, and then the noble
				{
					noble->clear();
					delete noble;
				}
				nobles.clear(); // gets rid of all the nullptrs in the vector!


				for (Warrior* warrior : available) // deletes all the available warriors
					delete warrior;

				available.clear(); // gets rid of all the nullptrs again!
			}

		}
		ifs.close(); // close program
	}
	else // this happens if the file doesn't exist!
	{
		cout << "Make sure that the file exists!" << endl;
		return 0;
	}
}