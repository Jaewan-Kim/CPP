// Jaewan Kim
// 14750277

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class Sandwich {
	const int bread = 2;
	int cheese;
	double mayo;
	int tomato;
	double mustard;
public:

	Sandwich(int c = 1, double m = 1, int t = 2, double mu = 0.05) : cheese(c), mayo(m), tomato(t), mustard(mu) {};
	void display() const;
	double getMayo() const { return mayo; };
	void setMayo(double ma) { mayo = ma; };
	int getCheese() const { return cheese; };
	void setCheese(int ch) { cheese = ch; };
	int getTomato() const { return tomato; };
	void setTomato(int to) { tomato = to; };
	double getMustard() const { return mustard; };
	void setMustard(double mu) { mustard = mu; };
};


void Sandwich::display() const
{
	cout << "Bread: " << bread << endl;
	cout << "Cheese: " << cheese << endl;
	cout << "Tomato: " << tomato << endl;
	cout << "Mayo: " << mayo << endl;
	cout << "Mustard: " << mustard << endl;
}


class SandwichTruck {
	vector <Sandwich> sandwiches;

public:
	void checkBeforeLeaving();
	void insertSandwich(Sandwich sw) { sandwiches.push_back(sw); };
	void deliver() {sandwiches.clear();}
};

void SandwichTruck::checkBeforeLeaving()
{
	int i = 1;
	for (Sandwich sand : sandwiches)
	{
		cout << "Sandwich " << i << ":"<< endl;
		i++;
		sand.display();
	}
}

int main()
{

	Sandwich customer1;
	Sandwich customer2;
	customer2.setMustard(0);
	Sandwich customer3;
	int numcheese3 = customer3.getCheese();
	customer3.setCheese(numcheese3 + 1);
	Sandwich customer4; 

	SandwichTruck truck;
	truck.insertSandwich(customer1);
	truck.insertSandwich(customer2);
	truck.insertSandwich(customer3);
	truck.insertSandwich(customer4);

	truck.checkBeforeLeaving();
}