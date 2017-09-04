/*
    Program: GameCollection.cpp
    Author:  Jason Custodio
    Class:   CS162
    Date:    12/02/2013
    Description: Welcome user and explain program.
                 Ask for size of array.
                 Display Interface and options.
                 Keep looping until user wants to exit.
                 Clean output buffer with new line loop.
                 Add games to the list.
                 Display full game info.
                 Add comments to games.
                 Find games.
*/

#include "GameCollection.h"

int main()
{
    GameCollection games; //Holds new/used/sale games
    int num;              //Used to find array size
    int choice = 0;       //Used for navigating interface

    games.welcome();      //Welcomes user

    cout << "Input number of new games:  "; //Allocate dynamic memory for newGame array
    cin  >> num; cin.ignore();
    games.setNew(num);

    cout << "Input number of used games: "; //Allocate dynamic memory for usedGame array
    cin  >> num; cin.ignore();
    games.setUsed(num);

    cout << "Input number of sale games: "; //Allocate dynamic memory for saleGame array
    cin  >> num; cin.ignore();
    games.setSale(num);

    do
    {
        games.space(100);
        choice = games.interface(); //Calls interface function to display user interface

        games.space(100);           //Creates a clean page after every command

        switch (choice)             //Switch statement with 5 commands
        {
            case 1:
            {
                games.addGame();    //Add game to gameArray
            }break;

            case 2:
            {
                games.findGame();   //Find a game in collection
            }break;

            case 3:
            {
                games.displayAll(); //Display full info of all games
            }break;

            case 4:
            {
                 games.comment();   //Change comments of a game
            }break;

            default:break;
        }
    }while (choice!=5);
    return 0;
}
