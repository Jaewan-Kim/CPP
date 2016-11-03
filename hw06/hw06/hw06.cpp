//Jaewan Kim
//14750277

// homework 06

/*
this is a continuation from the last homeworks.

In this edition, new derived classes of the nobles and the protectors were added.
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Noble; // declared beforehand so that the protector class can use it 

class Protector
{
protected:
	Noble* master; // protectors can have one master
	string const name; // and a name
	int strength; // aaaaand a strength to fight
	Protector(string name = "", int strength = 0) : name(name), strength(strength) { master = nullptr; }
public:
	Noble* isHired() const { return master; } // this will be used to tell if the protector is hired or not
	void setMaster(Noble* noble) { master = noble; } // and this will be used to set the master
	virtual	void defend() const = 0; // every protector will have their own unique defending sound
	string getName() const { return name; } // name getter
	void setStrength(int newstrength) { strength = newstrength; } // strength setter
	int getStrength() const { return strength; } // strength getter
};

// wizard is a type of the protector
class Wizard : public Protector
{

public:
	Wizard(string newname = "", int newstrength = 0) : Protector(newname, newstrength) {} // this is the default constructor for the wizard class, which is a derived class of protector
	void defend() const 
	{
		if (strength > 0) // this checks whether the protector is dead or not
			cout << "POOF!\n";  // if it is alive, then it will make a poof! sound when defending
	}
};

// warrior is a derived class of the protector
class Warrior : public Protector
{
protected:
	Warrior(string newname = "", int newstrength = 0) : Protector(newname, newstrength) {}
};

//there are two different types of warriors, and archer is one of them
class Archer : public Warrior
{

public:
	Archer(string newname = "", int newstrength = 0) : Warrior(newname, newstrength) {} // constructor for archer
	void defend() const;
};


// the second type of warrior is a swordsman
class Swordsman : public Warrior
{
public:
	Swordsman(string newname = "", int newstrength = 0) : Warrior(newname, newstrength) {}
	void defend() const;
};


class Noble // this is the noble class
{
protected:
	vector<Protector*> protectors; // only the lords can use this vector!
	string name;
	int strength; // however, lords will not have a strength on their own
	bool isalord = false;
	bool isalive = true;
	vector<Protector*> getProtectors() { return protectors; }
	Noble(string name) : name(name) {}
	Noble(string name, int strength) : name(name), strength(strength) {}
public:
	void battle(Noble& noble);
	string getName() const { return name; }
	virtual int getStrength() const = 0;
	virtual void death() = 0;
	virtual void newStrength(double ratio) = 0;
};

void Noble::battle(Noble& noble)
{
	cout << name << " battles " << noble.name << endl; // lets the world know who are fighting!
	int total1 = this->getStrength(); // the first total strength
	int total2 = noble.getStrength(); // second total strength
	if (isalord&&isalive) // if this is alive and is a lord, then the army will be called to make the defending sounds
		for (Protector* pptr : protectors)
			pptr->defend();
	
	if (total1 == 0 && total2 == 0) // if they are both with 0 strengths
	{
		if (isalive&& noble.isalive) // well, even if their strenths are zero, they might stil be alive because of lords without an amry
			cout << "You guys are alive, but you don't have any strength to fight!\n";
		else if (isalive)
		{
			cout << "He's dead, " << name << endl;
		}
		else if (noble.isalive)
			cout << "He's dead, " << noble.name << endl;
		else
			cout << "Oh NO! They're both dead! Yuck!\n";
	}
	else if (total1 > total2) // this case is when the total strength of the first noble is greater than the second
	{
		double ratio = total1 / total2; // this ratio will be used later to set new strengths
		if (noble.isalive)
		{
			cout << name << " defeats " << noble.name << endl;
			noble.death(); // now, the second noble is dead!
			this->newStrength(ratio); // and the first noble's status is set to new strengths
		}
		else
		{
			cout << "He's dead, " << name << endl; // in this case, the second noble is already dead
		}
	}
	else if (total1 < total2) // this is the same as the last case, but reversed with total 1 and total 2
	{
		double ratio = total1 / total2;
		if (isalive)
		{
			cout << noble.name << " defeats " << name << endl;
			this->death();
			noble.newStrength(ratio);
		}
		else
			cout << "He's dead, " << noble.name << endl;
	}
	else // this is the case when the strengths are equal, but not zero. they just both kill each other
	{
		cout << "Mutual Annihalation: " << name << " and " << noble.name << " die at each other's hands" << endl;
		this->death();
		noble.death();
	}
}

class PersonWithStrengthToFight : public Noble
{
public:
	PersonWithStrengthToFight(string noblename = "", int strength = 0) : Noble(noblename, strength) {}
protected:

	 // simple getters and setters! 
	int getStrength() const { return strength; }
	void death() { strength = 0; isalive = false; } // when this function is called, he is deaaaad
	void newStrength(double ratio) // this will just set the strength after the battle
	{
		strength = strength - strength* ratio;
	}
};


class Lord : public Noble
{
public:
	Lord(string name = "") : Noble(name) { isalord = true; }
	void hires(Protector& protector);
	Protector* fire(string name);
protected:	
	int getStrength() const; // getter for strengths.
	void death() // this will set all the army dead, as well as the noble itself
	{
		isalive = false;
		for (Protector* pptr : protectors)
			pptr->setStrength(0);
	}
	void newStrength(double ratio) // this will change the strengths of the army
	{
		for (Protector* pptr : protectors)
		{
			int temp = pptr->getStrength();
			pptr->setStrength(temp - temp* ratio);
		}

	}
};

int Lord::getStrength() const
{
	int strength1=0;
	for (Protector* pptr : protectors)
		strength1 += pptr->getStrength();
	return strength1;
}
Protector* Lord::fire(string name) // when the string is given, the function will look for the name in the vector of army and then fire him.
{
	vector<Protector*> updatedarmy;
	Protector* tempw = nullptr;
	for (Protector* wr : protectors)
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

	if (updatedarmy.size() != protectors.size())
	{
		protectors = updatedarmy;
		cout << tempw->getName() << ", you're fired! -- " << name << endl;
		return tempw;
	}
	return nullptr;
}

void Lord::hires(Protector& protector) // hiring a new protector!
{
	if (!protector.isHired() &&isalive) // noble can only hire someone when he is alive, and when the protector is not hired already
	{
		protectors.push_back(&protector);
		protector.setMaster(this);
	}
	else
	{
	}
}

void Archer::defend() const // defneding sound for the archers
{
	if (strength > 0)
		cout << "TWANG! " << name << " says: Take that in the name of my lord, " << master->getName() << endl;
}


void Swordsman::defend() const // defending sound for the swordsmen
{
	if (strength > 0)
		cout << "CLANG! " << name << " says: Take that in the name of my lord, " << master->getName() << endl;

}
int main() // this is the main function to test out the program!
{
	Lord sam("Sam");
	Archer samantha("Samantha", 200);
	sam.hires(samantha);
	Lord joe("Joe");
	PersonWithStrengthToFight randy("Randolf the Elder", 250);
	joe.battle(randy);
	joe.battle(sam);
	Lord janet("Janet");
	Swordsman hardy("TuckTuckTheHardy", 100);
	Swordsman stout("TuckTuckTheStout", 80);
	janet.hires(hardy);
	janet.hires(stout);
	PersonWithStrengthToFight barclay("Barclay the Bold", 300);
	janet.battle(barclay);
	janet.hires(samantha);
	Archer pethora("Pethora", 50);
	Archer thora("Thorapleth", 60);
	Wizard merlin("Merlin", 150);
	janet.hires(pethora);
	janet.hires(thora);
	sam.hires(merlin);
	janet.battle(barclay);
	sam.battle(barclay);
	joe.battle(barclay);
}