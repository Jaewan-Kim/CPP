// Jaewan Kim

// N14750277
// hw03

#include <iostream>
#include <vector>
#include <string>


/*this is a simple game/simulation in which you get to create nobles and warriors and make them battle each other(till death!)
*/
using namespace std;

// class warrior consists of the name and the strength of the warrior.
class Warrior
{
	string const name; // name doesn't change
	int strength; // however, strength does
public:
	Warrior(string name = "", int strength=0) : name(name), strength(strength) {} // constructor. by default, the name is set to "" and strength to 0
	string getName() const { return name; } // this function returns the name of the warrior
	int getStrength() const { return strength; } // this function returns the strength of the warrior
	void setStrength(int newstrength) { strength = newstrength; } // this function allows the user to change the strength of a warrior
};

// clas noble consists of name and the vector of warrior pointers
class Noble
{

	// just a numerical value used to indicate that a warrior is dead
	int const dead = 0;

	string const name; // once again, name doesn't change 
	vector <Warrior*> army; // this vector will contain the locations of the warriors
public:
	Noble(string name = "") :name(name) {} // constructor. by default, the name of the noble will be ""
	bool hire(Warrior& warrior); 
	void display();
	void fire(Warrior& warrior);
	void battle(Noble contestant);
	vector<Warrior*> getArmy() { return army; } // returns the vector of warrior pointers
	string getName() const { return name; }// returns the name of the noble.
};

// simply adds the warrior to the vector
bool Noble::hire(Warrior& warrior)
{
	// the same warrior can't be registered twice, right?
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

// nothing exciting here, just displaying things
void Noble::display()
{
	cout << this->name << " has an amry of " << army.size() << endl;

	for (Warrior* wr : army)
	{
		cout <<"        " << wr->getName() << ": " << wr->getStrength() << endl;
	}
}

void Noble::fire(Warrior& warrior)
{
	vector<Warrior*> updatedarmy;
	for (Warrior* wr : army)
	{
		// if the warrior pointer wr is pointing to warrior, the warrior will not be added to the new vector.
		if (wr == &warrior)
		{
			//nothing happens.
		}
		// if the warrior pointer doesn't point to warrior, the warrior will be added to the new vector
		else
		{
			updatedarmy.push_back(wr);
		}
	}

	/*
	if the sizes of updated army and the amry vectors are the same, it means that the warrior was not
	found in the vector and no one was fired.

	this if statement checks for it.
	*/
	if (updatedarmy.size() != army.size())
	{
		army = updatedarmy;
		cout << warrior.getName() << ", you're fired! -- " << name << endl;
	}
}

// this is a long function...
void Noble::battle(Noble contestant)
{
	/*
	it's assumed that the contestant exists.

	we will announce the names of the contestants
	*/
	cout << name << " battles " << contestant.getName() << endl;
	int total = 0;
	for (Warrior* wr : army) // this for-loop simply adds all the warriors' strengths in the army vector
	{
		total += wr->getStrength();
	}

	int total2 = 0;
	for (Warrior* wr : contestant.getArmy()) // does the same as the for loop above, but it's done on the contestant's vector
	{
		total2 += wr->getStrength();
	}
	
	if (total == dead) // first is dead
	{
		if (total2 == dead) // they are both dead
		{
			cout << "Oh, NO! They're both dead! Yuck!" << endl;
			// nothing happens when either one of them is dead. 
		}
		else // only the first is dead
		{
			cout << "He's dead " << contestant.getName() << endl;
			// nothing happens here
		}
	}
	else // first is alive
	{
		if (total2 == dead) // only the first is alive
		{
			cout << "He's dead " << name << endl;
			//nothing happens here as well
		}
		else //they are both alive
		{
			
			if (total == total2) // if both nobles have armies with same strengths, they both die.
			{
				cout << "Mutual Annihalation: " << name << " and " << contestant.getName() << " die at each other's hands" << endl;

				for (Warrior* wr : army) // this forloop replaces the strengths of the dead soldiers to 0
				{
					wr->setStrength(dead);
				}

				for (Warrior* wr : contestant.getArmy()) // this does the same for the contestant's vector
				{
					wr->setStrength(dead);
				}
			}

			else if (total > total2) // if total of the contestant 1 is bigger, than contestant 2 dies
			{
				cout << name << " defeats " << contestant.getName() << endl;
				double ratio = (double)total2 / (double)total; // find the ratio of smaller total / bigger total .
				for (Warrior* wr : army) // this will set the strengths of the warriors of the won side to ratio * origianl strength
				{
					int temp = wr->getStrength(); 
					temp = temp * ratio;  // because temp is an integer, the new strength value will be rounded
					wr->setStrength(temp);
				}

				for (Warrior* wr : contestant.getArmy()) // army 2 lost! so all the warriors are dead
				{
					wr->setStrength(dead);
				}

			}

			else // this thing does the same thing as the else if structure above, except that the second army won.
			{
				cout << contestant.getName() << " defeats " << name << endl;
				double ratio = (double)total / (double)total2;
				for (Warrior* wr : army) // army 1 is deaaddd
				{
					wr->setStrength(dead);

				}

				for (Warrior* wr : contestant.getArmy()) // warriors in the second army will have changed strengths
				{
					int temp = wr->getStrength();
					temp = temp * ratio;
					wr->setStrength(temp);
				}

			}

		}
	}
}

int main()
{
	// sample input
	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);

	jim.hire(nimoy);
	lance.hire(theGovernator);
	art.hire(wizard);
	lance.hire(dylan);
	linus.hire(lawless);
	billie.hire(mrGreen);
	art.hire(cheetah);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	art.fire(cheetah);
	art.display();
	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);
}