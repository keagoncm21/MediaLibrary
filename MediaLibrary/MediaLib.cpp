#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include "MediaLib.h"
#include "Media.h"
#include "Book.h"
#include "Movie.h"
#include "Music.h"
using namespace std;

int readData(istream& inFile, ostream& outFile, vector<Media*>& mediaLib) {
    cout << "\n\n\nLoading Data File\n\n\n";

    string inLine, title, director, genre, tempStr, testChar, name, author, artist;
    int rating, duration, year, pages;
    vector<string> stars;
    vector<string> row;
    char choice = ' ';

    while (inFile.good()) {
        getline(inFile, inLine);
        testChar = inLine.substr(0, 1);
        if (testChar == "Q")
            break;

        //read data in string vector
        row.clear();
        stringstream inSS(inLine);
        while (getline(inSS, tempStr, ','))
        {
            row.push_back(tempStr);
        }

        //parse data for Book type
        if (testChar == "B") 
        {
            title = row[1];
            author = row[2];
            genre = row[4];
            try {
                rating = stoi(row[3]);
                pages = stoi(row[5]);
                year = stoi(row[6]);
            }
            catch (invalid_argument& e) {
                string msg = "\nERROR: " + inLine.substr(0, inLine.length() - 2);
                outFile << msg << "\nPrevious record has an " << e.what() << " error\n\n";
                continue;
            }
            catch (string a) {
                cout << a << endl;
                exit(1);
            }
            char type = 'B';
            Book* tempBook = new Book(type, title, author, rating, genre, pages, year);

            mediaLib.push_back(tempBook);
            mediaCounts[1] ++;
        }
        // all other data types need to be added


        if (testChar == "M") //Adding movies
        {
            title = row[1];
            director = row[2];
            
            genre = row[4];
            
            for (int i = 7; i < row.size(); i++) //sending each star into a vector for stars
            {
                stars.push_back(row[i]);
            }
            
            try {
                rating = stoi(row[3]);
                duration = stoi(row[5]);
                year = stoi(row[6]);
            }
            catch (invalid_argument& e) {
                string msg = "\nERROR: " + inLine.substr(0, inLine.length() - 2);
                outFile << msg << "\nPrevious record has an " << e.what() << " error\n\n";
                continue;
            }
            catch (string a) {
                cout << a << endl;
                exit(1);
            }
            char type = 'M';
            Movie* tempMovie = new Movie(type,title,director,rating,genre,duration,year,stars);
            mediaLib.push_back(tempMovie);
            mediaCounts[0] ++;
        }


        if (testChar == "S") // Adding Songs 
        {
            title = row[1];
            artist = row[2];
            genre = row[4];

            try {
                rating = stoi(row[3]);
                duration = stoi(row[5]);
                year = stoi(row[6]);
            }
            catch (invalid_argument& e) {
                string msg = "\nERROR: " + inLine.substr(0, inLine.length() - 2);
                outFile << msg << "\nPrevious record has an " << e.what() << " error\n\n";
                continue;
            }
            catch (string a) {
                cout << a << endl;
                exit(1);
            }
            char type = 'S';
            Music* tempMusic = new Music(type, title, artist, rating, genre, duration, year);
            mediaLib.push_back(tempMusic);
            mediaCounts[2] ++;
        }
        stars.clear();
    }
    mediaCounts[3] = mediaCounts[0] + mediaCounts[1] + mediaCounts[2];
    return 0;
}


//Next 4 functions all are layed out the same: they all print out different types of lists based on what type is being filtered
void printList(vector<Media*>& m)
{
    cout << right << setw(40) << "All Media: " << endl << endl;
    cout << left << setw(30) << "#" << setw(30) << "Title" << setw(10) << "Year" << setw(10) << "Rating" << endl << endl;
    for (int i = 0; i < m.size(); i++)
        cout << left << setw(5) << i << left << setw(55) << m.at(i)->getTitle() << left << setw(10) << m.at(i)->getYearReleased() << left << setw(10) << m.at(i)->getRating() << endl;
}

void printBookList(vector<Media*>& m)
{
    cout << right << setw(40) << "Book List: " << endl << endl;
    cout << left << setw(30) << "#" << setw(30) << "Title" << setw(10) << "Year" << setw(10) << "Rating" << endl << endl;
    for (int i = 0; i < m.size(); i++)
    {
        if(m.at(i)->getType() == 'B')
            cout << left << setw(5) << i << left << setw(55) << m.at(i)->getTitle() << left << setw(10) << m.at(i)->getYearReleased() << left << setw(10) << m.at(i)->getRating() << endl;     
    }
}

void printMovieList(vector<Media*>& m)
{
    cout << right << setw(40) << "Movie List: " << endl << endl;
    cout << left << setw(30) << "#" << setw(30) << "Title" << setw(10) << "Year" << setw(10) << "Rating" << endl << endl;
    for (int i = 0; i < m.size(); i++)
    {
        if (m.at(i)->getType() == 'M')
            cout << left << setw(5) << i << left << setw(55) << m.at(i)->getTitle() << left << setw(10) << m.at(i)->getYearReleased() << left << setw(10) << m.at(i)->getRating() << endl;
    }
}

void printSongList(vector<Media*>& m)
{
    cout << right << setw(40) << "All Songs: " << endl << endl;
    cout << left << setw(30) << "#" << setw(30) << "Title" << setw(10) << "Year" << setw(10) << "Rating" << endl << endl;
    for (int i = 0; i < m.size(); i++)
    {
        if (m.at(i)->getType() == 'S')
            cout << left << setw(5) << i << left << setw(55) << m.at(i)->getTitle() << left << setw(10) << m.at(i)->getYearReleased() << left << setw(10) << m.at(i)->getRating() << endl;
    }
}


char printMenu()
{
    cout << endl << "      MENU CHOICES" << endl 
        << "M - Print Movie List" << endl
        << "B - Print Book List" << endl
        << "S - Print Song List" << endl
        << "A - Print All Media" << endl
        << "F - Find the Movie the Star is in" << endl
        << "G - Print Stars for a Given Movie" << endl
        << "T - Print Media Counts" << endl
        << "Q - Quit" << endl << endl;
    char choice;
    while (true) //function will loop until a valid option is chosen, in which it will return 'choice'
    {
        cin >> choice;
        choice = toupper(choice);

        switch (choice) //depending on what the user inputs will decide what get's returned or if the user has to re-enter another input
        {
        case 'M':
            return choice;
        case 'B':
            return choice;
        case 'S':
            return choice;
        case 'A':
            return choice;
        case 'F':
            return choice;
        case 'G':
            return choice;
        case 'T':
            return choice;
        case 'Q':
            return choice;
        default:
            cout << "That is not a valid option, please try again: ";
            continue;
        }
    }
    return choice;
}


void listMovieStars(string s, vector<Media*>& m) //finds the movie stars in movies and prints them out using the printstars function
{
    
    string movie;
    int count = 0;
    for (int i = 0; i < m.size(); i++)
    {
        if (m.at(i)->getType() == 'M')
        {
            
            if (m.at(i)->getTitle() == s)
            {
                m.at(i)->printStars();
                count++;
            }
        }
    }
    if (count == 0)
        cout << "This movie was not found. :(" << endl;
}

void printTotals() //prints out totals for each of the types found in the types array
{
    string types[4] = { "Movies","Books","Songs","Items" };
    
    cout << "Your Media Library:" << endl << endl;
    cout << left << setw(5) << "#" << left << setw(6) << "TYPE" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << left << setw(5) << mediaCounts[i] << left << setw(6) << types[i] << endl;
    }
    
}


//Finds movies that actors act in
void findMovie(string s, vector<Media*> & m)
{
    bool star;
    int count = 0; //if count doesn't get added to within the for loop after this, it will mark that the star was not found

    cout << endl << endl;
    cout << s << " appears in the following movie(s): " << endl;

    for (int i = 0; i < m.size(); i++)
    {
        if (m.at(i)->getType() == 'M') //if the type in the media vector is a movie, it will continue to specifically work for that type
        {
            star = m.at(i)->findStar(s);

            if (star)
            {
                count++;
                cout << m.at(i)->getTitle() << endl;
            }
        }
    }
    if (count == 0)
        cout << "Sorry, but the star, " << s << ", is not found in any movies in your list :(." << endl << endl;
}
