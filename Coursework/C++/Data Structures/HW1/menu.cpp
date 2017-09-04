/*
    Program: Blogs
    Author:  Jason Custodio
    Class:   CS163
    Date:    01/23/2014
    Description: Holds functions for menu class.
                 Creates interface
*/

#include "menu.h"
#include "blog.h"

menu::menu(){}

//Welcomes user and explains rules
void menu::welcome()
{
    space(100);
    cout << "***** BLOGS THREADS POSTS ***** " << endl
         << "------------------------------- " << endl
         << "* Add Post.                   |" << endl
         << "* Display Specific Thread.    |" << endl
         << "* Display Blog.               |" << endl
         << "* Rate Comment.               |" << endl
         << "------------------------------- " << endl
         << endl;
    check();
    space(100);
}

//Displays User Interface with multiple commands using a switch statement
int menu::interface()
{
    int choice = 0;

    cout << "*BLOGS THREADS POSTS*"  << endl
         << "---------------------" << endl
         << "(1) Add Post        |" << endl
         << "                    |" << endl
         << "(2) Display Thread  |" << endl
         << "                    |" << endl
         << "(3) Display Blog    |" << endl
         << "                    |" << endl
         << "(4) Rate Post       |" << endl
         << "                    |" << endl
         << "(5) Exit            |" << endl
         << "---------------------" << endl;

    cout << "\n\nInput number to choose option: ";
    cin  >> choice;
    cin.ignore();
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
        cin.ignore();
    }while (isblank(check) == 1);
}

//Creates numerous new lines
void menu::space(int num)
{
    for (int i = 0; i < num; i++)
        cout << endl;
}







