/*
    Program: RentAGame.cpp
    Author:  Jason Custodio
    Class:   CS162
    Date:    11/11/2013
    Description: Load game info from text file.
                 Welcome user and explain program.
                 Display Interface and options.
                 Keep looping until user wants to exit.
                 Clean output buffer with new line loop.
                 Add games to the list.
                 Renting a game makes it unavailable.
                 Returning games make it available.
                 Display full game info.
                 Display only available games.
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

const int SIZE = 50;     //Size for all arrays

struct game              //Struct for games
{
    char name    [SIZE]; //Name of game
    char email   [SIZE]; //Email of owner
    char rating  [SIZE]; //Game rating
    char summary [SIZE]; //Game summary
    char platform[SIZE]; //Platform that game plays on
    char comments[SIZE]; //Any comments on game
    bool valid;          //Availability
};

void space    (int);             //Provides clean output buffer
void check    ();                //Allows for a resting point
void welcome  ();                //Greets user and explains program
int  interface();                //Creates a user interface
void add         (game[], int&); //Add a game to the array
void load        (game[], int&); //Load game info from text file
void write       (game[], int);  //Output to a file
void rentGame    (game[], int);  //Rent available games
void returnGame  (game[], int);  //Return unavailable game
void displayAll  (game[], int);  //Display all games
void displayValid(game[], int);  //Display all available games

int main()
{
    game gameArray[21];       //Array of games
    int gameNum = 0;          //Number of games in the game array
    int choice  = 0;          //Used for switch statement

    load(gameArray, gameNum); //Load game info from text file

    space(100);

    welcome();                //Welcomes User and explains program

    do
    {
        choice = interface(); //Calls interface function to display user interface

        space(100);           //Creates a clean page after every command

        switch (choice)       //Switch statement with 6 commands
        {
            case 1:
            {
                add(gameArray, gameNum);          //Add game to gameArray
            }break;

            case 2:
            {
                rentGame(gameArray, gameNum);     //Rent an available game
            }break;

            case 3:
            {
                returnGame(gameArray, gameNum);   //Return an unavailable game
            }break;

            case 4:
            {
                displayAll(gameArray, gameNum);   //Display full game info
            }break;

            case 5:
            {
                displayValid(gameArray, gameNum); //Display available game info
            }break;

            default:break;
        }

    }while (choice!=6);

    write(gameArray, gameNum); //Write game info out to text file
    return 0;
}

//Welcomes user and explains rules
void welcome()
{
    cout << "*** WELCOME TO RENT-A-GAME ***  " << endl
         << "------------------------------- " << endl
         << "* Add games to the list.       |" << endl
         << "* Rent available games.        |" << endl
         << "* Return games.                |" << endl
         << "* Display all games.           |" << endl
         << "* Display only available games.|" << endl
         << "* Have fun!                    |" << endl
         << "------------------------------- " << endl
         << endl;
         check();
}

//Creates numerous new lines
void space(int num)
{
    for (int i = 0; i < num; i++)
        cout << endl;
}

//Allows for a resting point between commands
void check()
{
    char check;

    do
    {
        cout << "\nEnter any key to continue: ";
        cin  >> check;
        cin.ignore();
    }while (isblank(check) == 1);
}

//Displays User Interface with multiple commands using a switch statement
int interface()
{
    int choice = 0;

    space(100);

    cout << "**** RENT-A-GAME ****" << endl << endl
         << "---------------------" << endl
         << "(1) Add             |" << endl
         << "                    |" << endl
         << "(2) Rent            |" << endl
         << "                    |" << endl
         << "(3) Return          |" << endl
         << "                    |" << endl
         << "(4) All Games       |" << endl
         << "                    |" << endl
         << "(5) Available Games |" << endl
         << "                    |" << endl
         << "(6) Exit            |" << endl
         << "---------------------" << endl;

    cout << "\n\nInput number to choose option: ";
    cin  >> choice;
    cin.ignore();
    return choice;
}

//Add game to gameArray
void add(game gameArray[], int& gameNum)
{
    if(gameNum < 21)
    {
        cout << "Input name:     ";
        cin.get(gameArray[gameNum].name,     SIZE, '\n');
        cin.ignore(100, '\n');

        cout << "Input email:    ";
        cin.get(gameArray[gameNum].email,    SIZE, '\n');
        cin.ignore(100, '\n');

        cout << "Input rating:   ";
        cin.get(gameArray[gameNum].rating,   SIZE, '\n');
        cin.ignore(100, '\n');

        cout << "Input summary:  ";
        cin.get(gameArray[gameNum].summary,  SIZE, '\n');
        cin.ignore(100, '\n');

        cout << "Input platform: ";
        cin.get(gameArray[gameNum].platform, SIZE, '\n');
        cin.ignore(100, '\n');

        cout << "Input comments: ";
        cin.get(gameArray[gameNum].comments, SIZE, '\n');
        cin.ignore(100, '\n');

        gameArray[gameNum].valid = 1;

        ++gameNum;
    }
}

//Load game info from text file
void load(game gameArray[], int& gameNum)
{
    ifstream inFile;
    char validCheck[SIZE];

    inFile.open("games.txt");

    if(inFile)
    {
        inFile.ignore(SIZE, ' ');
        inFile.get(gameArray[gameNum].name, SIZE, '\n');
        inFile.ignore(SIZE, '\n');

        while(inFile && !inFile.eof())
        {
            inFile.ignore(SIZE, ' ');
            inFile.get(gameArray[gameNum].email,   SIZE, '\n');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(gameArray[gameNum].rating,  SIZE, '\n');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(gameArray[gameNum].summary, SIZE, '\n');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(gameArray[gameNum].platform,SIZE, '\n');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(gameArray[gameNum].comments,SIZE, '\n');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(validCheck, SIZE, '\n');
            inFile.ignore(SIZE, '\n');

            if(!strcmp(validCheck, "Yes"))
                gameArray[gameNum].valid = 1;
            else
                gameArray[gameNum].valid = 0;

            ++gameNum;

            inFile.ignore(SIZE, ' ');
            inFile.get(gameArray[gameNum].name, SIZE, '\n');
            inFile.ignore(SIZE, '\n');
        }
    }
    inFile.close();
}

//Write out all game info onto text file
void write(game gameArray[], int gameNum)
{
    ofstream outFile;

    outFile.open("games.txt");

    if(outFile)
    {
        for(int i = 0; i < gameNum; ++i)
        {
            outFile << "Name: "     << gameArray[i].name     << endl
                    << "Email: "    << gameArray[i].email    << endl
                    << "Rating: "   << gameArray[i].rating   << endl
                    << "Summary: "  << gameArray[i].summary  << endl
                    << "Platform: " << gameArray[i].platform << endl
                    << "Comments: " << gameArray[i].comments << endl;

            if(gameArray[i].valid)
                outFile << "Available: Yes\n" << endl;
            else
                outFile << "Available: No\n"  << endl;
        }
    }
    outFile.close();
    outFile.clear();
}

//Rent available game and change availability
void rentGame(game gameArray[], int gameNum)
{
    int i      = 0;
    int choice = 0;
    int flag   = 0;

    for(i = 0; i < gameNum; ++i)
    {
        if(gameArray[i].valid)
            ++flag;
    }

    if(flag > 0)
    {
        for(int i = 0; i < gameNum; ++i)
        {
            if(gameArray[i].valid)
            {
               cout << "(" << i+1 << ") Name: "
                     << gameArray[i].name << endl
                     << endl;
            }
        }

        cout << "Input game number to rent: ";
        cin  >> choice;
        cin.ignore();

        gameArray[choice-1].valid = 0;
    }
}

//Return unavailable game and change availability
void returnGame(game gameArray[], int gameNum)
{
    int i      = 0;
    int flag   = 0;
    int choice = 0;

    for(i = 0; i < gameNum; ++i)
    {
        if(!gameArray[i].valid)
            ++flag;
    }

    if(flag > 0)
    {
        for(int i = 0; i < gameNum; ++i)
        {
            if(!gameArray[i].valid)
            {
                cout << "(" << i+1 << ") Name: "
                     << gameArray[i].name << endl
                     << endl;
            }
        }

        cout << "Input game number to return: ";
        cin  >> choice;
        cin.ignore();

        gameArray[choice-1].valid = 1;
    }
}

//Display all game info in gameArray
void displayAll(game gameArray[], int gameNum)
{
    if( gameNum > 0)
    {
        for(int i = 0; i < gameNum; ++i)
        {
            cout << "("               << i+1                   << ") "
                 <<     "Name:      " << gameArray[i].name     << endl
                 << "    Email:     " << gameArray[i].email    << endl
                 << "    Rating:    " << gameArray[i].rating   << endl
                 << "    Summary:   " << gameArray[i].summary  << endl
                 << "    Platform:  " << gameArray[i].platform << endl
                 << "    Comments:  " << gameArray[i].comments << endl;

            if(gameArray[i].valid)
                    cout << "    Available: Yes\n" << endl;
                else
                    cout << "    Available: No\n"  << endl;
        }
        check();
    }
}

//Display all available games
void displayValid(game gameArray[], int gameNum)
{
    for(int i = 0; i < gameNum; ++i)
    {
        if(gameArray[i].valid)
        {
            cout << "("               << i+1                   << ") "
                 <<     "Name:      " << gameArray[i].name     << endl
                 << "    Email:     " << gameArray[i].email    << endl
                 << "    Rating:    " << gameArray[i].rating   << endl
                 << "    Summary:   " << gameArray[i].summary  << endl
                 << "    Platform:  " << gameArray[i].platform << endl
                 << "    Comments:  " << gameArray[i].comments << endl
                 << endl;
        }
    }
    check();
}


