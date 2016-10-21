//Jaewan Kim
//14750277

#include <iostream>
#include <vector>

using namespace std;

class PrintedMaterial {
public:
	PrintedMaterial(unsigned numPages)
		: numOfPages(numPages)
	{}
	virtual void displayNumPages() const = 0;
	
protected:
private:
	unsigned numOfPages;
};

void PrintedMaterial::displayNumPages() const
{
	cout << numOfPages << endl;
}
class Magazine : public PrintedMaterial {
public:
	Magazine(unsigned numPages)
		: PrintedMaterial(numPages)
	{}
	void displayNumPages() const
	{
		PrintedMaterial::displayNumPages();
	}
protected:
private:
};

class Book : public PrintedMaterial {
public:
	Book(unsigned numPages)
		: PrintedMaterial(numPages)
	{}
	void displayNumPages() const
	{
		PrintedMaterial::displayNumPages();
	}
protected:
private:
};

class TextBook : public Book {
public:
	TextBook(unsigned numPages, unsigned numIndxPgs)
		: Book(numPages),
		numOfIndexPages(numIndxPgs)
	{}
	void displayNumPages() const
	{
		cout << "Pages: ";
		PrintedMaterial::displayNumPages();
		cout << "Index pages: ";
		cout << numOfIndexPages << endl;
	}
protected:
private:
	unsigned numOfIndexPages;
};

class Novel : public Book {
public:
	Novel(unsigned numPages)
		: Book(numPages)
	{}
	void displayNumPages() const
	{
		PrintedMaterial::displayNumPages();
	}
protected:
private:
};

void displayNumberOfPages(const PrintedMaterial& pm)
{
	pm.displayNumPages();
}

// tester/modeler code
int main()
{
	TextBook t(5430, 234);
	Novel n(213);
	Magazine m(6);

	t.displayNumPages();
	n.displayNumPages();
	m.displayNumPages();
	PrintedMaterial* pmptr = &t;
	pmptr->displayNumPages();
	vector <PrintedMaterial*> pmvec;
	pmvec.push_back(&t);
	pmvec.push_back(&n);
	pmvec.push_back(&m);
	for (PrintedMaterial* p: pmvec)
	{
		p->displayNumPages();
	}

}