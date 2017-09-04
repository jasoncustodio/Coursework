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

//Organizes output
class menu
{
    public: menu();           //constructor
            void check ();    //Checkpoint pause
            void welcome();   //Welcome user
            int  interface(); //Display user interface
            void space (int); //Provides clean output buffer
};
