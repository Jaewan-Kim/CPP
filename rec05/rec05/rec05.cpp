// Jaewan Kim 14750277

// 1124 DLAB

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct Complex
{
	double real;
	double img;
};

class PlainOldClass
{
public:
	PlainOldClass() : x(-72) {}
	int getX() const { return x; }
	void setX(int x) { this->x = x; }
private:
	int x;
};

class Colour
{

public:
	Colour(const string& name, unsigned r, unsigned g, unsigned b)
		: name(name), r(r), g(g), b(b) {}
	void display() const
	{
		cout << name << " (RBG: " << r << "," << g << "," << b << ")";
	}
private:
	string name;
	unsigned r, g, b;
};

class SpeakerSystem
{
public:
	void vibrateSpeakerCones(unsigned signal) const
	{
		cout << "Playing: " << signal << "HZ sound..." << endl;
		cout << "Buzz, buzzy, buzzer, bzap!!!\n";
	}

};

class Amplifier
{
public:
	void attachSpeakers(SpeakerSystem& spkrs)
	{
		if (attachedSpeakers)
		{
			cout << "already have speakers attached!\n";
		}
		else
			attachedSpeakers = &spkrs;
	}

	void detachSpeakers()
	{
		attachedSpeakers = NULL;
	}
	void playMusic() const
	{
		if (attachedSpeakers)
			attachedSpeakers->vibrateSpeakerCones(440);
		else
			cout << "No speakers attached\n";
	}
private:
	SpeakerSystem* attachedSpeakers = NULL;
};

class Person
{
public:
	Person(const string& name) : name(name)
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
	int x;
	x = 10;
	cout << "x = " << x << endl;

	int* p;
	p = &x;
	cout << "p = " << p << endl;

	cout << "p points to where " << *p << " is stored\n";
	cout << "*p contains " << *p << endl;

	*p = -2763;

	cout << "p points to where " << *p << " is stored\n";
	cout << "*p now contains " << *p << endl;
	cout << "x now contains " << x << endl;

	int y(13);
	cout << "y contains " << y << endl;
	p = &y;
	cout << "p now points to where " << *p << " is stored\n";
	cout << "*p now contains " << *p << endl;
	*p = 980;
	cout << "*p points to where " << *p << " is contained\n";
	cout << "*p now contains " << *p << endl;
	cout << "y now contains " << y << endl;

	int* q;
	q = p;
	cout << "q points to where " << *q << " is stored\n";
	cout << "*q contains " << *q << endl;

	Complex c = {11.23,45.67};
	Complex* pC(&c);

	cout << "real: " << pC->real << "\nimaginary: " << pC->img << endl;

	// other way of doing this would be

	cout << "real: " << (*pC).real << "\nimaginary: " << (*pC).img << endl;

	PlainOldClass poc;
	PlainOldClass* ppoc(&poc);
	cout << ppoc->getX() << endl;
	ppoc -> setX(2837);
	cout << ppoc->getX() << endl;

	int* pDyn = new int(3);
	*pDyn = 17;

	cout << "The " << *pDyn << " is stored at address " << pDyn
		<< " which is in the heap\n";

	cout << pDyn << endl;
	delete pDyn;
	cout << pDyn << endl;
	pDyn = NULL;
	
	double* pDouble(NULL);

	double* pTest = new double(12);
	delete pTest;
	pTest = NULL;
	delete pTest;

	short* pShrt = new short(5);
	delete pShrt;

	long jumper(12238743);

	long* ptrTolong(&jumper);

	Complex cmplx;

	vector <Complex*> compIV;

	Complex* tmpPCmplx;
	for (size_t ndx = 0; ndx < 3; ++ndx)
	{
		tmpPCmplx = new Complex;
		tmpPCmplx->real = ndx;
		tmpPCmplx->img = ndx;
		compIV.push_back(tmpPCmplx);
	}

	for (size_t ndx = 0; ndx < 3; ++ndx)
	{
		cout << compIV[ndx]->real << endl;
		cout << compIV[ndx]->img << endl;
	}
	for (size_t ndx = 0; ndx < 3; ++ndx)
	{
		delete compIV[ndx];
	}
	compIV.clear();

	vector<Colour*> colours;
	string inputName;
	unsigned inputR, inputG, inputB;

	while (cin >> inputName >> inputR >> inputG >> inputB)
	{
		colours.push_back(new Colour(inputName, inputR, inputG, inputB));
	}

	for (size_t ndx = 0; ndx < colours.size(); ++ndx)
	{
		colours[ndx]->display();
		cout << endl;
	}
	SpeakerSystem spkr;
	Amplifier amp;
	amp.attachSpeakers(spkr);
	amp.playMusic();

	Person joeBob("Joe Bob"), billyJane("Billy Jane");


	joeBob.movesInWith(billyJane);
	cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
	cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;
}