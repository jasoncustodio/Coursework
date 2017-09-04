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

//Menu
//****************************************************************//
//Menu default constuctor
menu::menu(){}

//Welcomes user and explains rules
void menu::welcome()
{
    space(100);
    cout << "******* Math Adventure ******* " << endl
         << "--------------------------------" << endl
         << "* Move throughout map          |" << endl
         << "* Pickup items in each path    |" << endl
         << "* Get points for right answers |" << endl
         << "* Get to the end to win        |" << endl
         << "-------------------------------- " << endl
         << endl;
    check();
    space(100);
}

//Displays User Interface with multiple commands using a switch statement
int menu::interface(player& p, map& m)
{
    int choice = 0;

    cout << "Location: ";
    m.displayLocation(p.getLocation()); //Displays location's info
    cout << "\nName:  ";
    p.display();                        //Displays player's name
    cout << "Score: ";
    p.displayScore();                   //Displays player's score
    cout << endl;

    cout << "*** Math Adventure ***"<< endl
         << "---------------------" << endl
         << "(1) Move            |" << endl
         << "                    |" << endl
         << "(2) Inventory       |" << endl
         << "                    |" << endl
         << "(3) Exit            |" << endl
         << "---------------------" << endl;

    cout << "\nInput number to choose option: ";
    cin  >> choice;
    cin.ignore(100, '\n');
    return choice;
}

//Move in map
void menu::move(player& p, map& m)
{
    int answer = 0; //User input answer
    int right  = 0; //Used if answer is correct
    int wrong  = 0; //Used if answer is incorrect
    info myInfo;    //Used to communicate with player function

    m.retrieveItem(myInfo, p.getLocation());     //Changes item's info

    p.addItem(myInfo);                           //Pass item's info to add into player inventory

    m.displayQuestion(p.getLocation());          //Display player's location info
    cout << endl;
    cin >> answer;
    right = m.compare(p.getLocation(), answer); //Used for correct answer
    wrong = m.compare(p.getLocation(), FALSE);  //Used for incorrect answeer, FALSE is constant

    if(right)
    {
        p.setLocation(right); //Set player's location to the index of the correct answer
        p.addScore(TRUE);     //Add 100 points to player's score
    }
    else
        p.setLocation(wrong); //Set player's lcoation to index of the incorrect answer
}

//Displays all items in player's inventory
void menu::displayInventory(player& p)
{
    p.displayInventory();
}

//Pause checkpoint function
void menu::check()
{
    char check;

    do
    {
        cout << "\nEnter any key to continue: ";
        cin  >> check;
        cin.ignore(100, '\n');
    }while (isblank(check) == 1);
}

//Creates numerous new lines
void menu::space(int num)
{
    for (int i = 0; i < num; i++)
        cout << endl;
}
//****************************************************************//







