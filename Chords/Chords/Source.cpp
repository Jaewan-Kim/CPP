#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


int main()
{
	char answer;
	do
	{
		cout << "Name of the song: ";
		string name;
		getline(cin, name);

		ofstream outFile;
		outFile.open(name);
		string chord = "";
		vector<string> chords;
		while (chord != "x" || chord != "X")
		{
			cout << "Chord(x to quit): ";
			cin >> chord;
			if (chord != "x" || chord != "X")
			{
				chords.push_back(chord);
			}
			if (chord == "x" || chord == "X")
			{
				break;
			}
		}
		int i = 1;
		for (string chord : chords)
		{
			if (i % 4 == 0) 
			{
				outFile << chord << " |" << endl;
			}
			else
			{
				outFile << chord << " - ";
			}
			i++;
		}

		cout << "Do you want to add another song? y/n: ";
		cin >> answer;
	} while (answer == 'y' | answer == 'Y');
}