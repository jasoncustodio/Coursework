/*
    Program:     Binary Search Tree
    Author:      Jason Custodio
    Class:       CS163
    Date:        03/13/2014
    Description: This program will simulate class registration
                 A binary search tree is implemented to store courses
                 The courses are loaded in from an external file
                 Each node in the binary search tree holds one course and a pointer to its left and right child
                 Most functions performed on the binary search tree is done recursively.
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
         << "* Remove Course               |" << endl
         << "* Remove All                  |" << endl
         << "* Display All                 |" << endl
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
         << "(2) Remove Course   |" << endl
         << "                    |" << endl
         << "(3) Remove All      |" << endl
         << "                    |" << endl
         << "(4) Display All     |" << endl
         << "                    |" << endl
         << "(5) Exit            |" << endl
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







