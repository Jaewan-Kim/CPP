#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
	Person(const string& name)
	{}
	void movesInWith(Person& newRoommate)
	{
		roomie = &newRoommate;
		newRoommate.roomie = this;
	}
	string getName() const { return this->name; }
	string getRoomiesName() const { return roomie->getName(); }
private:
	Person* roomie;
	string name;

};

int main()
{
	Person joeBob("Joe Bob"), billyJane("Billy Jane");


	joeBob.movesInWith(billyJane);
	cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
	cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;
}