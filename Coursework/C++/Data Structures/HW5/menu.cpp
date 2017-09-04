/*
    Program:     Graph
    Author:      Jason Custodio
    Class:       CS163
    Date:        03/20/2014
    Description: This program will simulates a quiz for computers
                 A list of vertices are used with edges that connect to adjacent vertices
                 The vertices and edges are loaded from an external file
                 Each node node holds an answer, a pointer to the next node, and index
                 The vertices hold a question, a visit flag, and a head pointer to a LLL
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
         << "* Take Quiz                   |" << endl
         << "* Display Vertex              |" << endl
         << "* Display Quiz                |" << endl
         << "------------------------------- " << endl
         << endl;
    check();
    space(100);
}

//Displays User Interface with multiple commands using a switch statement
int menu::interface()
{
    int choice = 0;

    cout << "**** LAPTOP QUIZ ****"  << endl
         << "---------------------" << endl
         << "(1) Take Quiz       |" << endl
         << "                    |" << endl
         << "(2) Display Vertex  |" << endl
         << "                    |" << endl
         << "(3) Display Quiz    |" << endl
         << "                    |" << endl
         << "(4) Exit            |" << endl
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







