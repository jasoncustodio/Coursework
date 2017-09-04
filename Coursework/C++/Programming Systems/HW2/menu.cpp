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

//Menu
//****************************************************************//
//Menu default constuctor
menu::menu(){}

//Welcomes user and explains rules
void menu::welcome()
{
    space(100);
    cout << "******* Math Adventure ******* "  << endl
         << "--------------------------------" << endl
         << "* Move throughout map          |" << endl
         << "* Pickup items in each path    |" << endl
         << "* Get points for right answers |" << endl
         << "* Get to the end to win        |" << endl
         << "* Add multiple players         |" << endl
         << "--------------------------------" << endl
         << endl;
    gameRoster.add();
    check();
    space(100);
}

//Displays User Interface with multiple commands using a switch statement
int menu::interface()
{
    int choice = 0; //Choice to use for interface (1-5)

    gameMap.displayLocation(gameRoster.getLocation()); //Displays location's info
    gameRoster.display();                              //Displays player's name
    gameRoster.displayId();                            //Displays player's id
    gameRoster.displayScore();                         //Displays player's score
    cout << endl;

    cout << "*** Math Adventure ***"<< endl
         << "---------------------" << endl
         << "(1) Move            |" << endl           //Move to change location and score points
         << "                    |" << endl
         << "(2) Inventory       |" << endl           //Display all items in inventory
         << "                    |" << endl
         << "(3) Add Player      |" << endl           //Add player to roster
         << "                    |" << endl
         << "(4) Change Player   |" << endl           //Switch the current player
         << "                    |" << endl
         << "(5) Exit            |" << endl           //Close program
         << "---------------------" << endl;

    cout << "\nInput number to choose option: ";
    cin  >> choice;
    cin.ignore(100, '\n');
    return choice;
}

//Move in map
int menu::move()
{
    int answer = 0; //User input answer
    int right  = 0; //Used if answer is correct
    int wrong  = 0; //Used if answer is incorrect
    info myInfo;    //Used to communicate with player function

    gameMap.retrieveItem(myInfo, gameRoster.getLocation());    //Changes item's info

    gameRoster.addItem(myInfo);                                //Pass item's info to add into player inventory

    gameMap.displayQuestion(gameRoster.getLocation());         //Display player's location info
    cout << endl;
    cin >> answer;
    right = gameMap.compare(gameRoster.getLocation(), answer); //Used for correct answer
    wrong = gameMap.compare(gameRoster.getLocation(), FALSE);  //Used for incorrect answeer, FALSE is constant

    if(right)
    {
        gameRoster.setLocation(right); //Set player's location to the index of the correct answer
        gameRoster.addScore(TRUE);     //Add 100 points to player's score
        return gameRoster.getLocation();
    }
    else
        gameRoster.setLocation(wrong); //Set player's location to index of the incorrect answer
        return gameRoster.getLocation();
}

//Displays all items in player's inventory
void menu::displayInventory()
{
    gameRoster.displayInventory();
    check();
}

//Add player to roster
void menu::add()
{
    gameRoster.add();
}

//Switches current player playing the game
void menu::setCurrentPlayer()
{
    int id = 0;

    cout << "Current Player Id: "; //Displays all the id's of available players
    gameRoster.displayAllId();
    cout << "\n\nEnter Player Id: ";
    cin  >> id;

    while(!(id >= 0 && id < gameRoster.getNumPlayer())) //Must choose correct numbers or will loop
    {
        space(SPACE);
        cout << "Current Player Id: ";
        gameRoster.displayAllId();
        cout << "\n\nEnter player id: ";
        cin  >> id;
    }
    gameRoster.setCurrentPlayer(id); //Changes current player
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

//Load vertives and edges into map
void menu::load(char vertexText[], char edgeText[])
{
    gameMap.load(vertexText, edgeText);
}

//Congratulates the winner
void menu::win()
{
    space(SPACE);
    gameRoster.display();
    gameRoster.displayId();
    cout << " WINS!";
    gameRoster.displayScore();
    check();
}
//****************************************************************//







