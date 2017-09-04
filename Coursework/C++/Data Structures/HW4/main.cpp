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

#include "table.h"
#include "menu.h"

int main()
{
    menu   myMenu;       //Help with interface
    table  myTable;      //Actual binary tree
    course myCourse;     //Help as an argument to display


    char title   [SIZE]; //To communicate with application
    char section [SIZE]; //To communicate with application

    int choice = 0;      //Choice for interface

    strcpy(title, "course.txt");
    myTable.load(title); //Load mail into Stack from text file

    myMenu.welcome();    //Welcomes user
    do
    {
        myMenu.space(SIZE);          //Clean output buffer
        choice = myMenu.interface(); //Calls interface function to display user interface

        myMenu.space(SIZE);          //Clean output buffer

        switch (choice)              //Switch statement with 6 commands
        {
            case 1: //Retrieve Course
            {
                cout << "Input title of course: ";                  //Asks title to search
                cin.get(title,SIZE,'\n'); cin.ignore(SIZE,'\n');

                cout << "\nInput section of course (001 or 002): "; //Asks section to search
                cin.get(section,SIZE,'\n'); cin.ignore(SIZE,'\n');

                if(myTable.retrieve(title, section, myCourse))      //Match if both title/search are true
                    myCourse.display();
                else
                    cout << "\nCOURSE RETRIEVAL FAILURE!\n";

                myMenu.check();                                     //Pause
            }break;

            case 2: //Remove Course
            {
                cout << "Input title of course: ";                  //Title to search
                cin.get(title,SIZE,'\n'); cin.ignore(SIZE,'\n');

                cout << "\nInput section of course (001 or 002): "; //Section to search
                cin.get(section,SIZE,'\n'); cin.ignore(SIZE,'\n');

                if(myTable.remove(title, section))                  //Wrapper function
                    cout << "\nCOURSE REMOVAL SUCCESS!\n";
                else
                    cout << "\nCOURSE REMOVAL FAILURE!\n";

                myMenu.check();                                     //Pause
            }break;

            case 3: //Remove All
            {
                myTable.removeAll();
            }break;

            case 4: //Display all courses in table
            {
                myTable.display();
                myMenu.check();
            }break;

            default:break;
        }
    }while (choice!=5); //Exit program
    return 0;
}
