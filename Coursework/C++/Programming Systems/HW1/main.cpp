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


#include "menu.h"

int main()
{
    menu myMenu;                   //Help with interface
    map  myMap;                    //Actual map graph
    player myPlayer;               //One player

    int choice = 0;                //Choice for interface

    char textOne [SIZE];           //Used to supply external vertex data
    char textTwo [SIZE];           //Used to supply external edge data
    strcpy(textOne, "vertex.txt"); //Used to supply external vertex data
    strcpy(textTwo, "edge.txt");   //Used to supply external edge data
    myMap.load(textOne, textTwo);  //Load vertex and edge data

    myMenu.welcome();              //Welcomes user
    do
    {
        myMenu.space(SPACE);                       //Clean output buffer
        choice = myMenu.interface(myPlayer,myMap); //Calls interface function to display user interface
        myMenu.space(SPACE);                       //Clean output buffer

        switch (choice) //Switch statement with 3 commands
        {
            case 1: //Move
            {
                myMenu.move(myPlayer, myMap);
                if(!myPlayer.getLocation()) //Once player gets to the end, they finish
                {
                    myMenu.space(SPACE);
                    cout << "YOU WIN!" << endl << "Score: ";
                    myPlayer.displayScore();
                    myMenu.check();
                    choice = EXIT; //EXIT is constant for exiting program
                }
            }break;

            case 2: //Display Inventory
            {
                myMenu.displayInventory(myPlayer); //Displays all items in the inventory
                myMenu.check();                    //Pause
            }break;

            default:break;
        }
    }while (choice!=EXIT); //Exit program
    return 0;
}
