#include <string>
#include <iostream>
#include <vector>
#include "Media.h" 
#include "Movie.h"
using namespace std;

Movie::Movie() : Media()
{
	director = " ";
	duration = 0;
	stars = {};
}

Movie::Movie(char type, string t, string a, int r, string g, int d, int yr, vector<string> s) : Media(type, t, r, yr, g)
{
	director = a;
	duration = d;
	stars = s;
}

//getters and setters 

void Movie::setDirector(string d)
{
	director = d;
}
void Movie::setDuration(int d)
{
	duration = d;
}
void Movie::setStars(vector<string> s)
{
	stars = s;
}
string Movie::getDirector()
{
	return director;
}
int Movie::getDuration()
{
	return duration;
}
vector<string> Movie::getStars()
{
	return stars;
}

//prints out movie information to the outfile
void Movie::print(ostream& o) 
{
	o << "Movie: " << title << " : " << director << endl;
}

void Movie::printStars() {
	// for loop to print stars
	cout << "Here are the movie stars in the given movie: " << endl;
	for (int i = 0; i < stars.size(); i++)
		cout << stars.at(i) << endl;
}

//returns true or false depending if the star is found in the stars vector
bool Movie::findStar(string s)
{
	for (int i = 0; i < stars.size(); i++)
	{
		if (s == stars.at(i))
			return true;
	}
	return false;

}