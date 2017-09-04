/*
    Program:     Text Application
    Author:      Jason Custodio
    Class:       CS202
    Date:        05/20/2014
    Description: This program simulates a text application
                 Info class acts as a string class
                 A message has an info and timeSent
                 A text is a message
                 A facebook is a message
                 An email is a message
                 Messages are stored in tree nodes
                 Tree nodes make up the tree BST app
                 Class account holds 5 strings
                 A person is an account
                 A contact node holds a person
                 The contact List is made up of LLL
*/

#include "treeApp.h"

//Organizes output
class menu
{
    public: menu(); //Constructor

            void check();              //Checkpoint pause
            void welcome();            //Welcome user
            void space(int);           //Provides clean output buffer
            int  interface();          //Display user interface, returns player's choice (1-5)

            void load(char[], char[]); //Load courses from external file
            void displayMessage();     //Display Message
            void displayContacts();    //Display Contacts

    private:
            treeApp myApp;             //Holds messages
            contactList myList;        //Holds list of contacts
};
