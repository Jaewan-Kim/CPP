#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Pet;
class Person;

class Pet
{
public:
	Person* owner;
};

class Person
{
public:
	Pet* pet;
};
int main()
{
	vector<Pet*> pets;
	vector<Person*> persons;
	for (int i = 0; i < 20; i++)
	{
		Pet* ptr = new Pet;
		Person* pptr = new Person;
		pptr->pet = ptr;
		ptr->owner = pptr;

		pets.push_back(ptr);
		persons.push_back(pptr);
	}

	for (Person* person : persons)
	{
		delete person;
	}
	for (Pet* pet : pets)
	{
		delete pet;
	}
}