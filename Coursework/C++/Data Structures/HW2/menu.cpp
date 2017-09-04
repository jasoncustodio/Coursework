/*
    Program:     Inbox
    Author:      Jason Custodio
    Class:       CS163
    Date:        02/11/2014
    Description: Holds functions for menu class.
                 Creates interface
*/

#include "menu.h"
#include "inbox.h"

menu::menu(){}

//Welcomes user and explains rules
void menu::welcome()
{
    space(100);
    cout << "********* MAIL INBOX ********* " << endl
         << "-------------------------------" << endl
         << "* Push Mail                   |" << endl
         << "* Peek Mail                   |" << endl
         << "* Pop Mail                    |" << endl
         << "* Display Mail                |" << endl
         << "* Enqueue VIP                 |" << endl
         << "* Peek VIP                    |" << endl
         << "* Dequeue VIP                 |" << endl
         << "* Display VIP                 |" << endl
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
         << "(1) Push    Mail    |" << endl
         << "                    |" << endl
         << "(2) Peek    Mail    |" << endl
         << "                    |" << endl
         << "(3) Pop     Mail    |" << endl
         << "                    |" << endl
         << "(4) Display Mail    |" << endl
         << "---------------------" << endl
         << "(5) Enqueue VIP     |" << endl
         << "                    |" << endl
         << "(6) Peek    VIP     |" << endl
         << "                    |" << endl
         << "(7) Dequeue VIP     |" << endl
         << "                    |" << endl
         << "(8) Display VIP     |" << endl
         << "---------------------" << endl
         << "(9) Exit            |" << endl
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







