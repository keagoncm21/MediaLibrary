#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Media 
{
protected:
	char type;
	string title;
	int rating;
	int yearReleased;
	string genre;

public:
	Media();
	Media(char, string, int, int, string);
	//setters
	void setType(char c);
	void setTitle(string t);
	void setRating(int r);
	void setYearReleased(int yr);
	void setGenre(string g);

	//getters
	char   getType();
	string getTitle();
	int    getRating();
	int    getYearReleased();
	string getGenre();

	//virtuals all to allow functions to pass to child classes
	virtual void print(ostream& o);
	virtual void printStars();
	virtual bool findStar(string s);

	
	
};
