// hw01 
// Jaewan Kim
// 14750277

/*
The purpose of the program is to decode an encrypted file.
The encrypted file will contain an integer indicating the number of steps
in shifting the chracters.
Capital letters will not be encrypted.
On top of that, the lines are revesed.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// this function decrypts only lowercase characters, one at a time.
char decrypt(char characterIn, int numberOfSteps)
{
	// 27 and 1 practically functions as the same. therefore, it is more efficient to change numberOfSteps 
	// to a smaller number.
	if (numberOfSteps > 26)
	{
		numberOfSteps %= 26;
	}

	// this if structure determines whether the character input is a lower case alphabet letter.

	if (characterIn >= 'a' && characterIn <= 'z') 
	{
		characterIn -= numberOfSteps;

		if (characterIn < 'a')
		{
			characterIn += 26;
		}
	}
	return characterIn;

}

/*this function uses the function decrypt and decrypts the string as the whole
and returns the string that was given into the function.
*/

string decryptString(string stringIn, int numberOfSteps)
{
	string newString;
	for (char character : stringIn)
	{
		newString += decrypt(character, numberOfSteps);
	}

	return newString;
}

// because the encrypted file is reversed, it needs to be reversed back again

/*this function uses the vector of strings. each string contains the line from the encrypted
	file. then, the program swaps the order of the lines.
*/
void reverseVec(vector<string>& vectorOfStrings)
{
	int sizeVal = vectorOfStrings.size();
	for (int i = 0; i < sizeVal / 2; i++)
	{
		string temp = vectorOfStrings[sizeVal - 1 - i];
		vectorOfStrings[sizeVal - 1 - i] = vectorOfStrings[i];
		vectorOfStrings[i] = temp;
	}
}

int main()
{

	// opening the file 
	ifstream ifs;
	string fileName = "encrypted.txt";
	ifs.open(fileName);

	// determines how many times the characters will be shifted
	int numberOfSteps;
	int x;
	if (ifs >> x)
	{
		// when an integer is found in the file, the integer will be used as number of steps.
		numberOfSteps = x;


		vector <string> output;
		string line;

		/*when we used ifs >> x, the program finished reading the encrypted file. therefore, we need to 
		tell the program to go back to the beginning of the program.
		however, we don't want the integer to be included in the output. therefore, we will 
		find out how many digits there are in the integer and make the program go back to the spot where
		the integer just ends.*/
		int tens = 10;
		int nOfDigits = 1;
		while (numberOfSteps >= tens)
		{
			tens *= 10;
			nOfDigits++;
		}

		ifs.clear();

		// return the program to where the integer ends
		ifs.seekg(nOfDigits);

		// program reads the file line by line
		while (getline(ifs, line))
		{

			// decrpyts the line
			line = decryptString(line, numberOfSteps);
			// and stores the line in the vector that will be used for the output
			output.push_back(line);
		}

		// function is used to reverse the order of the lines
		reverseVec(output);

		// this for loop sequence displays the output line by line.
		for (string lines : output)
		{

			cout << lines << endl;
		}
	}
}



