#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;
//movie class to keep track of movies
class Movie : public Media {

private:
	string director;
	int duration;
	vector<string> stars;

public:
	Movie();
	Movie(char, string, string, int, string, int, int, vector<string>);
	void setDirector(string);
	void setDuration(int);
	void setStars(vector<string>);
	string getDirector();
	int getDuration();
	vector<string> getStars();

	void print(ostream& o);

	void printStars();
	//pre: none
	//post prints out stars
	
	bool findStar(string s);
	//pre takes a string as input
	//post: returns true or false depending if the star is found in the stars vector
	
};
