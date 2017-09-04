/*
    Program:     Adventure Map
    Author:      Jason Custodio
    Class:       CS202
    Date:        04/16/2014
    Description: This program simulates a math riddle game
                 There will be a menu class that acts as an interface
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
    public: menu();                         //Constructor

            void check();                  //Checkpoint pause
            void welcome();                 //Welcome user
            void space(int);               //Provides clean output buffer
            void move(player&,map&);        //Move to next location, answer question
            int  interface(player&,map&);   //Display user interface
            void displayInventory(player&); //Display player's inventory
};
