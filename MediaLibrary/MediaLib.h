#pragma once
#include <vector>
#include "Media.h"
#include "Movie.h"
using namespace std;

int  readData(istream& i, ostream& o, vector<Media*>& m);
static int mediaCounts[4] = { 0,0,0,0 };

// all other class functions need to be added

void printList(vector<Media*>& m);
void printMovieList(vector<Media*>& m);
void printSongList(vector<Media*>& m);
void printBookList(vector<Media*>& m);
//pre (the four above this): all take the media vector as input
//post: prints out lists based on the information the user wants
void printTotals();
//pre: none
//post: prints total media
char printMenu();
//pre: none
//post: returns a char that will be used to make a choice between what the user will do

void listMovieStars(string s, vector<Media*>& m);
//pre:takes a string(name) and a media vector as input
//post: finds movie stars in a movie

void findMovie(string s, vector<Media*>& m);
//pre:takes a string(name) and a media vector as input
//post: finds movies a star features in







