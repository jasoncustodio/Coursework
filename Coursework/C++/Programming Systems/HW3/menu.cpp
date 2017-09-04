/*
    Program:     Text Application
    Author:      Jason Custodio
    Class:       CS202
    Date:        05/20/2014
    Description: This program simulates a text application
                 Info class acts as a string class
                 A message has an info and timeSent
                 A text is a message
                 A facebook is a message
                 An email is a message
                 Messages are stored in tree nodes
                 Tree nodes make up the tree BST app
                 Class account holds 5 strings
                 A person is an account
                 A contact node holds a person
                 The contact List is made up of LLL
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
    cout << "******* Text Application ******* "  << endl
         << "--------------------------------" << endl
         << "* Receive Message              |" << endl
         << "* Display Message              |" << endl
         << "--------------------------------" << endl
         << endl;
    check();
    space(100);
}

//Displays User Interface with multiple commands using a switch statement
int menu::interface()
{
    int choice = 0; //Choice to use for interface (1-5)

    cout << "* Text Application *"  << endl
         << "---------------------" << endl
         << "(1) Display Message |" << endl           //Move to change location and score points
         << "                    |" << endl
         << "(2) Display Contact |" << endl           //Display all items in inventory
         << "                    |" << endl
         << "(3) Exit            |" << endl           //Close program
         << "---------------------" << endl;

    cout << "\nInput number to choose option: ";
    cin  >> choice;
    cin.ignore(100, '\n');
    return choice;
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
void menu::load(char * contactText, char * treeText)
{
    myList.load(contactText);
    myApp.load(treeText);
}

//Displays Messages
void menu::displayMessage()
{
    myApp.display();
    check();
}

//Displays Contacts
void menu::displayContacts()
{
    myList.display();
    check();
}
//****************************************************************//







