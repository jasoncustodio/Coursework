#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int SIZE = 50;     //Size for all arrays in game struct

struct game              //Struct for games
{
    char name    [SIZE]; //Name of game
    char email   [SIZE]; //Email of owner
    char rating  [SIZE]; //Game rating
    char summary [SIZE]; //Game summary
    char platform[SIZE]; //Platform that game plays on
    char comments[SIZE]; //Any comments on game
    int  type;           //New(1), Used(2), Sale(3)
};

class GameCollection
{
    public: GameCollection  (); //Construtor
            ~GameCollection (); //Destructor
            void check      (); //Checkpoint pause
            void addGame    (); //Add a game to array according to type
            void comment    (); //Add comments for a game
            void welcome    (); //Welcome user
            void findGame   (); //Find a game and display info
            int  interface  (); //Display user interface
            void displayAll (); //Display full game info on all games

            void space      (int); //Provides clean output buffer
            void setNew     (int); //Dynamically allocate memory for newGames
            void setUsed    (int); //Dynamically allocate memory for usedGames
            void setSale    (int); //Dynamically allocate memory for saleGames

            void display    (game[], int); //Display all games
            void displayName(game[], int); //Support function for comment function
            void add        (game[], int&);//Add a game to the array

            bool find       (game[], int, char[]); //find game, if found, return game info
            bool findComment(game[], int, char[]); //Support function for comment function

    private: game * newGame;  //Pointer for array of new games
             game * usedGame; //Pointer for array of used games
             game * saleGame; //Pointer for array of sales games

             int numNew;  //Number of new games in collection
             int numUsed; //Number of used games in collection
             int numSale; //Number of sale games in collection
};
