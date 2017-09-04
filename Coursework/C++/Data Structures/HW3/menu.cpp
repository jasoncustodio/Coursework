/*
    Program:     Hash Table
    Author:      Jason Custodio
    Class:       CS163
    Date:        02/25/2014
    Description: This program will simulate class registration
                 A hash table is implemented to store courses
                 The courses are loaded in from an external file
                 The hash table consists of a dynamically allocated array of node pointers
                 A hash function is used to put the course in a specified slot
                 The hash function sums up all the elements in the array modded by the array size
                 Each node consists of one course and a next node pointer
*/

#include "menu.h"
#include "table.h"

menu::menu(){}

//Welcomes user and explains rules
void menu::welcome()
{
    space(100);
    cout << "******** Course Table ******** " << endl
         << "-------------------------------" << endl
         << "* Retrieve Course             |" << endl
         << "* Retrieve Section            |" << endl
         << "* Retrieve Time               |" << endl
         << "* Display All                 |" << endl
         << "* Remove Section              |" << endl
         << "------------------------------- " << endl
         << endl;
    check();
    space(100);
}

//Displays User Interface with multiple commands using a switch statement
int menu::interface()
{
    int choice = 0;

    cout << "**** MAIL INBOX ****"  << endl
         << "---------------------" << endl
         << "(1) Retrieve Course |" << endl
         << "                    |" << endl
         << "(2) Retrieve Section|" << endl
         << "                    |" << endl
         << "(3) Retrieve Time   |" << endl
         << "                    |" << endl
         << "(4) Display All     |" << endl
         << "                    |" << endl
         << "(5) Remove Section  |" << endl
         << "                    |" << endl
         << "(6) Exit            |" << endl
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







