#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Person
{
	string name;
	Person* coworker = nullptr; // let's just say you can only have one coworker at a time;
public:
	Person(string name = "") : name(name) {}
	bool addCoworker(Person& cw);
	void quitJob();
	string getCoworker();
	string getName() { return name; }
};

string Person::getCoworker()
{
	if (coworker)
	{
		return coworker->name;
	}
}

bool Person::addCoworker (Person& cw)
{
	if (coworker != nullptr|| coworker!= nullptr)
		return false;


	coworker = &cw;
	cw.coworker = this;
	return true;
}

void Person::quitJob()
{
	if (coworker)
	{
		coworker->coworker = nullptr;
		coworker = nullptr;
	}
}

class Country
{
	string name;
	Person* president=nullptr;
public:
	Country(string name = "") : name(name) {}
	void newPresident(Person& president);
	string returnPresident();
};

string Country::returnPresident()
{
	if (president)
		return president->getName();
	else
		return "This country does not have a president yet.";
}

void Country::newPresident(Person& newpresident)
{
	if (president)
	{
		president = &newpresident;
	}
	else
	{
		president = &newpresident;
	}
}

int main()
{
	Person jay("Jay");
	Person* cow;
	cow = new Person("Cow");
	cow->addCoworker(jay);
	cout << jay.getCoworker() << endl;
	cout << cow->getCoworker() << endl;

	Country newc("USA");
	newc.newPresident(jay);
	cout << newc.returnPresident() << endl;

	newc.newPresident(*cow);

	cout << jay.getName() << endl;
}