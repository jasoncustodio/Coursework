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

#include "table.h"
#include "menu.h"

int main()
{
    menu   myMenu;       //Help with interface
    table  myTable;      //Actual hash table
    course myCourse;     //Help as an argument to display


    char title   [SIZE]; //To communicate with application
    char section [SIZE]; //To communicate with application

    int choice = 0;         //Choice for interface

    myTable.load();         //Load mail into Stack from text file
    myTableTime.loadTime(); //Extra credit

    myMenu.welcome();   //Welcomes user
    do
    {
        myMenu.space(SIZE);          //Clean output buffer
        choice = myMenu.interface(); //Calls interface function to display user interface

        myMenu.space(SIZE);          //Clean output buffer

        switch (choice)              //Switch statement with 6 commands
        {
            case 1: //Retrieve Course
            {
                cout << "Input title of course: ";         //Asks title to search
                cin.get(title,SIZE,'\n'); cin.ignore(SIZE,'\n');

                if(myTable.retrieveCourse(title, myCourse))//Compares two strings
                    myCourse.displayCourse();              //Push mail into stack made from user input

                myMenu.check();                            //Pause
            }break;

            case 2: //Retrieve Section
            {
                cout << "Input title of course: ";                    //Asks title to search
                cin.get(title,SIZE,'\n'); cin.ignore(SIZE,'\n');

                cout << "\nInput section of course (001 or 002): ";   //Asks section to search
                cin.get(section,SIZE,'\n'); cin.ignore(SIZE,'\n');

                if(myTable.retrieveSection(title, section, myCourse)) //Match if both title/search are true
                    myCourse.displaySection();

                myMenu.check();                                       //Pause
            }break;

            case 3: //Retrieve Time
            {
                cout << "Input days of course: ";                  //Title to search
                cin.get(title,SIZE,'\n'); cin.ignore(SIZE,'\n');

                cout << "\nInput time of course: ";                //Section to search
                cin.get(section,SIZE,'\n'); cin.ignore(SIZE,'\n');

                myTableTime.displayTime(title, section);
                myMenu.check();
            }break;

             case 4: //Display all courses in table
            {
                myTableTime.display();
                myMenu.check();
            }break;

            case 5: //Remove Course Section
            {
                cout << "Input title of course: ";                  //Title to search
                cin.get(title,SIZE,'\n'); cin.ignore(SIZE,'\n');

                cout << "\nInput section of course (001 or 002): "; //Section to search
                cin.get(section,SIZE,'\n'); cin.ignore(SIZE,'\n');

                myTable.remove(title, section);                     //Wrapper function
                myMenu.check();
            }break;

            default:break;
        }
    }while (choice!=6); //Exit program
    return 0;
}
