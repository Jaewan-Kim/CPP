// Jaewan Kim
// 14750277
// this program organizes the txt file with the information about the hydrocarbon molecules


#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// struct molecule includes the number of carbon atoms, number of hydrogen atoms, and names of the specific formula
struct molecule
{
	int nofCarbon;
	int nofHydro;
	vector<string> names;

};

// this function sorts the vector based on the carbon numbers of the molecules, from the smallest to the biggest
void vectorSort(vector<molecule>& molecules)
{
	
	for (int i = 0; i < molecules.size(); i++)
	{
		int min = 10000;
		int j = i;
		int index = 0;
		molecule temp;
		for (j; j < molecules.size(); j++)
		{
			if (molecules[j].nofCarbon < min)
			{
				min = molecules[j].nofCarbon;
				temp = molecules[j];
				index = j;
			}
		}
		molecule temp2 = molecules[i];
		molecules[index] = temp2;
		molecules[i] = temp;
	}
	
}

int main()
{
	vector <molecule> molecules;

	// input file
	ifstream ifs;
	ifs.open("hydrocarbons.txt");
	string name;
	char dummy;
	int nofcarbons;
	int nofhydro;
	//reads the file by molecules
	while (ifs >> name >> dummy >> nofcarbons >> dummy >> nofhydro)
	{
		// adds the molecule into the vector of molecules
		molecule tempmolecule;
		tempmolecule.names.push_back(name);
		tempmolecule.nofCarbon = nofcarbons;
		tempmolecule.nofHydro = nofhydro;

		molecules.push_back(tempmolecule);
	}
	
	// calls in the function and sorts them
	vectorSort(molecules);
	
	// prints out the molecules
	for (molecule ms : molecules)
	{
		cout << 'C' << ms.nofCarbon << 'H' << ms.nofHydro << endl;
		for (string ss : ms.names)
		{
			cout << ss<< "  ";
		}
		cout << endl;
		cout << endl;
	}
	

	
}