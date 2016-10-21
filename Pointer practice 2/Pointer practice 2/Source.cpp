#include <iostream>
#include <vector>
#include <string>

//incomplete
using namespace std;

class Book;
class Bookshelf;
class Library;

class Book
{
	string name;
	string author;
	int year;
public:
	Book(string name = "", string author = "", int year = 0) : name(name), author(author), year(year) {}
	void display();
};

void Book::display()
{
	cout << name << ", written by " << author << ", published in " << year << endl;
}

class Bookshelf
{
	string name;
	vector<Book*> books;
	int maximum;
	int numberOfBooks = 0;
public:
	Bookshelf(string name, int maximum = 10): name(name), maximum(maximum) {}
	void addBook(string name, string author, int year);
	void display();
};

void Bookshelf::addBook(string name, string author, int year)
{
	Book* temp =new Book(name, author, year);
	if (numberOfBooks < maximum)
	{
		numberOfBooks++;
		books.push_back(temp);
	}
}

void Bookshelf::display()
{
	for (Book* b : books)
	{
		b->display();
	}
}

class Library
{
	string name;
	vector<Bookshelf*> bookshelves;
public:
	Library(string name = "") : name(name){}
	bool addBook(Bookshelf& bs, string name, string author, int year);
	void addBookshelf(Bookshelf* bs);
	void display();
};

void Library::addBookshelf(Bookshelf* bs)
{
	bookshelves.push_back(bs);
}

bool Library::addBook(Bookshelf& bs, string name, string author, int year)
{
	for (Bookshelf* b : bookshelves)
	{
		if (b == &bs)
		{
			b->addBook(name, author, year);
			return true;
		}
	}
	return false;
}

void Library::display()
{
	for (Bookshelf* b : bookshelves)
	{
		b->display();
	}
}

int main()
{
	Library library = Library ("Bern Dibner");
	while (true)
	{
		cout << "What do you wish to do?" << endl;
		cout << "[1] add a bookshelf" << endl;
		cout << "[2] add a book to a specific bookshelf" << endl;
		cout << "[3] display books" << endl;
		cout << "[4] clear books" << endl;
		int input;
		cin >> input;
		switch (input)
		{
		case 1:
		{
			cout << "What is the name of the bookshelf? ";
			string name;
			getline(cin, name);
			cin.ignore();
			int max;
			cout << "What is the maximum capacity of the bookshelf? ";
			cin >> max;
			Bookshelf* temp = new Bookshelf(name, max);
			library.addBookshelf(temp);
		}
		case 2:
		{
			cout << "What is the name of the bookshelf? ";
			string name;
			getline(cin, name);
			cin.ignore();
			cout << "What is the name of the book? ";
			string nob;
			getline(cin, nob);
			cin.ignore();
			string author;
			cout << "What is the name of the author? ";
			getline(cin, author);
			cin.ignore();
			int year;
			cout << "What year was it published? ";
			cin >> year;
		}
		case 3:
		{}
		case 4:
		{}
		}
	}
}