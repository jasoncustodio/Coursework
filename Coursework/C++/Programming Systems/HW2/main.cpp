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

#include "menu.h"

int main()
{
    menu myMenu;                   //Help with interface

    int choice = 0;                //Choice for interface

    char textOne [SIZE];           //Used to supply external vertex data
    char textTwo [SIZE];           //Used to supply external edge data
    strcpy(textOne, "vertex.txt"); //Used to supply external vertex data
    strcpy(textTwo, "edge.txt");   //Used to supply external edge data
    myMenu.load(textOne, textTwo); //Load vertex and edge data

    myMenu.welcome();              //Welcomes user
    do
    {
        myMenu.space(SPACE);         //Clean output buffer
        choice = myMenu.interface(); //Calls interface function to display user interface
        myMenu.space(SPACE);         //Clean output buffer

        switch (choice) //Switch statement with 5 commands
        {
            case 1: //Move
            {
                if(!myMenu.move()) //Once player gets to the end, they finish
                {
                    myMenu.win();  //Congratulates player that won
                    choice = EXIT; //EXIT is constant for exiting program
                }
            }break;

            case 2: //Display Inventory
            {
                myMenu.displayInventory(); //Displays all items in the inventory
            }break;

            case 3: //Add Player
            {
                myMenu.add(); //Adds a player to the roster
            }break;

            case 4: //Change Player
            {
                myMenu.setCurrentPlayer(); //Switches player
            }break;

            default:break;
        }
    }while (choice!=EXIT); //Exit program
    return 0;
}
