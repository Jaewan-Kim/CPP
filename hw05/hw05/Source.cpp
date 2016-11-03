//Jaewan Kim
// 14750277

// this is the last problem from the first exam.

/*
this program will read in names of artists and paintings from two separate files
there will be two different classes: artist and painting
the main will read in from the file and display
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Painting;

// this is the artist class
class Artist
{
public:
	Artist(string name = "") : name(name) {} // constructor for artists. takes the name of the artist
	// functions will be explained below
	Painting* addPainting(string nameofp);
	string getName() const { return name; } // returns name. it's a constant function
	void setName(string newName) { name = newName; } // changing the name of the artist
	void display() const;
private:
	string name;
	vector<Painting*> paintings;
};

class Painting
{
private:
	Artist* painter;
	string name;
public:
	Painting (string name = "", Artist* painter = nullptr) :name(name), painter(painter) {}
	//painting will be constructed with the name, and a pointer to the artist which cannot be changed
	string getName() const { return name; } // returns the name of the painting
	string getArtistName() const { return painter->getName(); } // returns the name of the artist
	void setTitle(string newtitle) { name = newtitle; } // chaning the name of the painting
	void display()const // display function.
	{
		cout << name << "painted by " << painter->getName() << endl;
	}
};

// this function adds a painting to the vector of paintings
Painting* Artist::addPainting(string nameofp) 
{
	// firstly, the painting is created on the heap.
	Painting* paintingptr = new Painting(nameofp, this);
	paintings.push_back(paintingptr); // added to the vector of paintings
	return paintingptr; // returns the painting made. it will make sense in the main
}

void Artist::display() const
{
	for (Painting* paint : paintings)
		paint->display(); // this function simply goes thorugh the vector of paintings and calls the display function
}

// this function will search for the name with of the given parameter, and return the artist pointer
Artist* searchByArtist(vector<Artist*> vec, string name)
{
	for (Artist* artist : vec)
	{
		if (artist->getName() == name)
			return artist;
	}
	return nullptr;
	// however, if the artist is not found, it will just return nullptr
}

int main()
{
	ifstream artist; 
	ifstream painting;
	string filename;

	// the do while functions below will simply ask the user the name of the files.
	// if the file with the input doesn't exist, it will just return to the top of the while function
	// if the file exists, then the file will be opened
	do
	{
		cout << "What is the Artist filename?\n";
		cin >> filename;
		artist.open(filename.c_str());
		if (!artist)
			cerr << "BAD filename!\n";
	} while (!artist);
	do
	{
		cout << "What is the Painting filename?\n";
		cin >> filename;
		painting.open(filename.c_str());
		if (!painting)
			cerr << "BAD filename!\n";
	} while (!painting);

	vector<Artist*> artists; // this vector will store all the artists
	string name;
	while (artist >> name) // the artist input file will have names of the artists
	{
		Artist* ptrsearch = searchByArtist(artists, name);
		if (!ptrsearch) // if the artist with the name already exists, then it will not do anythign
		{
			Artist* ptr = new Artist(name); 
			artists.push_back(ptr);
		}
	}

	/*
	the structure below is pretty long.

	it was assuming that there is a space between the painting name and the last painting name

	it would have been simpler if the input file was formatted with diffferent lines,
	because i could've used a getline function instead.

	the exam does not clarify whether artist with painting is separated by lines, 
	therefore i used the method below since it will work in both cases
	*/
	string pstring="";
	string paintname = "";
	Artist* artistptr = nullptr;
	Artist* artistptr2 = nullptr;
	Painting* pptr = nullptr;
	vector<Painting*> paintings;

	while (painting >> pstring) // reads in one string at a time
	{
		artistptr = searchByArtist(artists, pstring);
		// then, checks if the string is a name of one of the existing artists

		
		if (artistptr)
		{
			if (paintname == "") // even though the artist was found, if the name of the paint is empty, that means it's the first artist
			{
			}
			else
			{
				// if the paintname is not empty and the string is a name of the artist,
				pptr = artistptr2->addPainting(paintname); // a painting is created
				paintname = ""; // then the paintname is emptied out again
				paintings.push_back(pptr); // and the pointer to the painting, which has been returned from the addPainting function is added to the vector of painting pointers
			}
			artistptr2 = artistptr;
		}
		else
		{
			paintname += pstring + " "; // if the string is not a name of the artist, then the string will  be added to the string of the paint name
		}
	}

	// because the last intput won't be include in the previous whileloop, the codes below will add the painting
	pptr = artistptr2->addPainting(paintname); 
	paintings.push_back(pptr);

	// display
	for (Painting* paints : paintings)
	{
		paints->display();
	}

	//closing the input files
	artist.close();
	painting.close();

	//deleting the pointers
	for (Artist* deleting : artists)
		delete deleting;
	for (Painting* deleting : paintings)
		delete deleting;

	// we don't want vectors full of nullptrs do we? 
	artists.clear();
	paintings.clear();

}