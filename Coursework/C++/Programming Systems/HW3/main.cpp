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

#include "menu.h"

int main()
{
    menu myMenu;                         //Help with interface

    int choice = 0;                      //Choice for interface

    char textOne [SIZE];                //Used to supply external contact data
    char textTwo [SIZE];                //Used to supply external edge data
    strcpy(textOne, "contactText.txt"); //Used to supply external vertex data
    strcpy(textTwo, "treeText.txt");    //Used to supply external edge data
    myMenu.load(textOne, textTwo);      //Load vertex and edge data

    myMenu.welcome();                   //Welcomes user
    do
    {
        myMenu.space(SIZE);             //Clean output buffer
        choice = myMenu.interface();    //Calls interface function to display user interface
        myMenu.space(SIZE);            //Clean output buffer

        switch (choice) //Switch statement with 5 commands
        {
            case 1: //Display Messages
            {
                myMenu.displayMessage();//Displays all messages in BST
            }break;

            case 2: //Display Contacts
            {
                myMenu.displayContacts(); //Displays all contacts
            }break;

            default:break;
        }
    }while (choice!=EXIT); //Exit program
    return 0;
}
