// Jaewan Kim
// 14750277
// jk5149

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int getLines(string name) {
	ifstream ifs(name);
	ifs.clear();
	ifs.seekg(0);
	string line;
	int number = 0;
	while (getline(ifs, line)) {
	
		cout << line <<endl;
		number++;
	}
	return number;
}

int getWords(string name) {
	ifstream ifs(name);
	ifs.clear();
	ifs.seekg(0);
	string word;
	int number = 0;
	while (ifs >> word) {
	
		cout << word << endl;
		number++;
	}
	return number;
}

int getChar(string name) {
	
	ifstream ifs(name);
	ifs.clear();
	ifs.seekg(0);
	ifs >> noskipws;
	char ch;
	int number = 0;
	while (ifs >> ch) {

		cout << ch << endl;
		number++;
	
	}
	ifs >> skipws;
	return number;

}

int main() {

	cout << "What is the name of the file? ";
	string nameOf;
	cin >> nameOf;
	
	
	int numberOfLines = getLines(nameOf);
	int numberOfWords = getWords(nameOf);
	int numberOfChar = getChar(nameOf);
	/*int numberOfWords=0;
	int numberOfLines=0;

	string line;
	while (getline(ifs, line)) {
	
		numberOfLines++;
		cout << line << endl;
	}

	ifs.clear();
	ifs.seekg(0);

	string word;
	while (ifs >> word) {
	
		cout << word << endl;
		numberOfWords++;
	}
	ifs >> noskipws;
	ifs.clear();
	ifs.seekg(0);
	int numberOfChar=0;
	char ch;
	while (ifs >> ch) {
	
		cout << ch << endl;
		numberOfChar++;
	}
	*/
	cout << "There were " << numberOfLines << " lines, " << numberOfWords << " words, and " << numberOfChar <<" characters in the file." << endl;
}