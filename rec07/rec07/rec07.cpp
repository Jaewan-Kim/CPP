//Jaewan Kim
//14750277

#include <vector>
#include <iostream>
using namespace std;

class Instrument
{
public:
	virtual void makeSound() const = 0;
	virtual void play() const = 0;
};

class Brass : public Instrument
{
protected:
	unsigned mouthpiece;
public:
	void makeSound() const { cout << "To make a sound... blow on a mouthpiece of size " << mouthpiece << endl; }
};

class Trumpet : public Brass
{
public:
	Trumpet(unsigned mouthpiece = 9) { if (mouthpiece == 9 || mouthpiece == 4 || mouthpiece == 12)this->mouthpiece = mouthpiece; }
	void play() const { cout << "Toot"; }
};


class Trombone : public Brass
{
public: 
	Trombone(unsigned mouthpiece = 9) { if (mouthpiece == 9 || mouthpiece == 4 || mouthpiece == 12)this->mouthpiece = mouthpiece; }
	void play() const { cout << "Blat"; }
};


class String : public Instrument
{
protected:
	unsigned pitch;
public:
	void makeSound() const { cout << "To make a sound... bow a string with pitch " << pitch << endl; }
};

class Violin: public String
{
public:
	Violin(unsigned pitch) {this->pitch = pitch; }
	void play() const { cout << "Screech"; }
};

class Cello : public String
{
public:
	Cello(unsigned pitch) { this->pitch = pitch; }
	void play() const { cout << "Squak"; }
};

class Percussion : public Instrument
{
public:
	void makeSound() const { cout << "To make a sound... hit me!" << endl; }
};

class Drum : public Percussion
{
public:
	Drum() {}
	void play() const { cout << "Boom"; }
};

class Cymbal: public Percussion
{
public:
	Cymbal() {}
	void play() const { cout << "Crash"; }
};

class Musician {
public:
	Musician() : instr(NULL) {}
	void acceptInstr(Instrument & i) { instr = &i; }
	Instrument* giveBackInstr() {
		Instrument* tmp(instr);
		instr = NULL;
		return tmp;
	}
	void testPlay() const {
		if (instr)
			instr->makeSound();
		else
			cerr << "have no instr\n";
	}
	void play() const;
private:
	Instrument* instr;
};

void Musician::play() const
{
	if (instr)
		instr->play();
}

class MILL 
{
private:
	vector<Instrument*> instruments;
public:
	void receiveInstr(Instrument& inst);
	void dailyTestPlay() const;
	Instrument* loanOut();
};

void MILL::receiveInstr(Instrument& inst)
{
	/*vector<Instrumnet*> temp = instrumetns;
	instruments.clear();
	for (size_t i = 1; i < size())*/
	bool flag = false;
	for (size_t i = 0; i < instruments.size(); i++) {
		if (instruments[i] == NULL) {
			instruments[i] = &inst;
			flag = true;
			break;
		}
	}
	if (!flag) {
		instruments.push_back(&inst);
	}
}
Instrument* MILL::loanOut()
{/*
	Instrument* inst = instruments[0];

	instruments[0] = instruments[instruments.size()-1];
	instruments.pop_back();
	return inst;*/
	if (instruments.size() > 0) {
		for (size_t i = 0; i < instruments.size(); i++) {
			if (instruments[i] != NULL) {
				cout << "Loan Out" << endl;
				Instrument* x = instruments[i];
				instruments[i] = NULL;
				return x;
			}
		}
	}
	else { return NULL; }
	
	

}
void MILL::dailyTestPlay() const
{
	for (Instrument* inst : instruments)
	{
		inst->makeSound();
	}
}

class Orch
{
private:
	vector<Musician*> musicians;
public:
	Orch() {}
	void addPlayer(Musician& musician) { musicians.push_back(&musician); }
	void play() const;
};

void Orch::play() const
{
	for (Musician* musc : musicians)
		musc->play();
	cout << endl;
}
// PART ONE
int main()
{

	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone(4);
	Trumpet trpt(12);
	Violin violin(567);

	MILL mill;
	mill.receiveInstr(trpt);
	mill.receiveInstr(violin);
	mill.receiveInstr(tbone);
	mill.receiveInstr(drum);
	mill.receiveInstr(cello);
	mill.receiveInstr(cymbal);

	Musician bob;
	Musician sue;
	Musician mary;
	Musician ralph;
	Musician jody;
	Musician morgan;

	Orch orch;



	// THE SCENARIO

	//Bob joins the orchestra without an instrument.
	orch.addPlayer(bob);

	//The orchestra performs
	cout << "orch performs\n";
	orch.play();

	//Sue gets an instrument from the MIL2 and joins the orchestra.
	sue.acceptInstr(*mill.loanOut()); 
	orch.addPlayer(sue);

	//Ralph gets an instrument from the MIL2.
	ralph.acceptInstr(*mill.loanOut());

	//Mary gets an instrument from the MIL2 and joins the orchestra.
	mary.acceptInstr(*mill.loanOut());
	orch.addPlayer(mary);

	//Ralph returns his instrument to the MIL2.
	mill.receiveInstr(*ralph.giveBackInstr());

	//Jody gets an instrument from the MIL2 and joins the orchestra.
	jody.acceptInstr(*mill.loanOut());
	orch.addPlayer(jody);

	// morgan gets an instrument from the MIL2
	morgan.acceptInstr(*mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Ralph joins the orchestra.
	orch.addPlayer(ralph);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	// bob gets an instrument from the MIL2
	bob.acceptInstr(*mill.loanOut());

	// ralph gets an instrument from the MIL2
	ralph.acceptInstr(*mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Morgan joins the orchestra.
	orch.addPlayer(morgan);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

}

