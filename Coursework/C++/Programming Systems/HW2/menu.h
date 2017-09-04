/*
    Program:     Adventure Map
    Author:      Jason Custodio
    Class:       CS202
    Date:        05/07/2014
    Description: This program simulates a math riddle game
                 There will be a menu class that acts as an interface
                 Menu has a roster and has a map
                 A player roster will be implemented in the future
                 The info class acts as any kind of simple data
                 A player is derived from the info class
                 A player has a score, a name, a location, and inventory
                 The score is only an int, the name is info, the location
                 is the index of where it is in the map
                 Inventory is a DLL that holds items found in the map
                 An item is an info
                 Info only has a name and points to the next and previous items
                 The map is implemented using a graph
                 Each vertex holds a question, location, object, a visit flag, and
                 a head pointer to a LLL of edges
                 Each edge holds an answer, index of where it points to, and a pointer
                 to the next edge
                 To win the game, you must get to the end
                 Whoever gets the highest score at the end wins with multiplayer
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include "map.h"
using namespace std;

//Organizes output
class menu
{
    public: menu(); //Constructor

            void add();                //Add a player to the game
            void win();                //If player gets to the end, they win, displaying name, applause, score
            int  move();               //Move to next location, answer question, if 0 is returned, player wins
            void check();              //Checkpoint pause
            void welcome();            //Welcome user
            void space(int);           //Provides clean output buffer
            int  interface();          //Display user interface, returns player's choice (1-5)
            void displayInventory();   //Display player's inventory
            void setCurrentPlayer();   //Change player
            void load(char[], char[]); //Load courses from external file

    private:
            roster gameRoster; //Holds list of players
            map gameMap;       //Holds graph of vertices
};
