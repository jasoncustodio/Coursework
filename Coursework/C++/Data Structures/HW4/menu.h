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

//Organizes output
class menu
{
    public: menu();           //constructor
            void check ();    //Checkpoint pause
            void welcome();   //Welcome user
            int  interface(); //Display user interface
            void space (int); //Provides clean output buffer
};
