//Keagon Madison
//kcmc2f@umsystem.edu
//Media Library Project


#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include "MediaLib.h"
#include "Media.h"
#include "Book.h"
using namespace std;

int main() {

    // open input & output files
    ifstream inFile;
    ofstream outFile;

    try //opening files/checking to make sure they open correctly
	{
        inFile.exceptions(ifstream::failbit);
        inFile.open("mediaList.txt");
        outFile.exceptions(ifstream::failbit);
        outFile.open("mediaReport.txt");
    }
    catch (ifstream::failure& fail) {
        cout << "Could not open input file" << endl;
        cout << fail.what() << endl;
        cout << fail.code() << endl;
        exit(1);
    }

    // create vector of media data
    vector <Media*> myLib;


    // read data into myLib
    readData(inFile, outFile, myLib);
	
	char choice;
	string movie, star;

	while (true) //the menu will continue as long as the user doesn't choose 'Q'
	{
		choice = printMenu();
		if (choice == 'M') //user choice to see the list of movies
		{
			printMovieList(myLib);
		}
		else if (choice == 'B') //user choice to see the list of books
		{
			printBookList(myLib);
		}
		else if (choice == 'S')//user choice to see the list of songs
		{
			printSongList(myLib);
		}
		else if (choice == 'A') //user choice to see the list of all media
		{
			printList(myLib);
		}
		else if (choice == 'F') //user choice to see movies which include the specific star
		{			
			cout << "Enter the star's name: \n";
			cin.ignore();
			getline(cin, star);
			findMovie(star,myLib);
		}
		else if (choice == 'G')//user choice to see stars in a movie
		{
			cout << "Enter the movie name: ";
			cin.ignore();
			getline(cin, movie);
			listMovieStars(movie, myLib);
		}
		else if (choice == 'T') //user choice to print out total of all media
		{
			printTotals();
		}
		else if (choice == 'Q')//user choice to quit program
		{
			cout << endl << "Exiting the program..." << endl;
			break;
		}
	}




}