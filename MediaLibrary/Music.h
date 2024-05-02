#pragma once
#include <string>
#include <iostream>

using namespace std;
//Music Class to keep track of songs
class Music : public Media {

private:
	string artist;
	int duration;

public:
	Music();
	Music(char, string, string, int, string, int, int);
	void setArtist(string a);
	void setDuration(int d);
	string getArtist();
	int getDuration();
	void print();
	void print(ostream& o);
};