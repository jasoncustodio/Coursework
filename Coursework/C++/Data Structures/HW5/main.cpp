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

#include "table.h"
#include "menu.h"

int main()
{
    menu   myMenu;       //Help with interface
    table  myTable;      //Actual graph

    int choice = 0;      //Choice for interface
    int option = 0;

    char textOne [SIZE];
    char textTwo [SIZE];

    strcpy(textOne, "vertex.txt");
    strcpy(textTwo, "edge.txt");

    myTable.load(textOne, textTwo); //Load mail into Stack from text file

    myMenu.welcome();    //Welcomes user
    do
    {
        myMenu.space(SIZE);          //Clean output buffer
        choice = myMenu.interface(); //Calls interface function to display user interface

        myMenu.space(SIZE);          //Clean output buffer

        switch (choice)              //Switch statement with 4 commands
        {
            case 1: //Take Quiz
            {
                myTable.takeQuiz(option);
                myTable.reset();
                option = 0;
                myMenu.check();                                     //Pause
            }break;

            case 2: //Display Vertex
            {
                cout << "\nPlease enter index (0-4):";
                cin >> option;
                myTable.displayVertex(option);
                myTable.reset();
                myMenu.check();                                     //Pause
            }break;

            case 3: //Display Quiz
            {
                myTable.displayQuiz();
                myMenu.check();
            }break;

            default:break;
        }
    }while (choice!=4); //Exit program
    return 0;
}
