/*
    Program:     Inbox
    Author:      Jason Custodio
    Class:       CS163
    Date:        02/11/2014
    Description: First welcome and instruct user how to use the program.
                 Display Interface.
                 Keep looping until user wants to exit.
                 Keep looping new lines to create clean screens after each command.
                 Add Mail to stack's yop
                 Peek at stack's top
                 Pop stack's top
                 INPUT: name, date, email, subject, message
                 OUTPUT: All mail in stack and queue
*/

#include "inbox.h"
#include "menu.h"

int main()
{
    menu  myMenu;       //Help with interface
    mail  myMail;       //Help as an argument to display and peek
    queue myQueue;      //Actual Queue
    stack myStack;      //Actual Stack

    char name   [SIZE]; //To communicate with application
    char date   [SIZE]; //To communicate with application
    char email  [SIZE]; //To communicate with application
    char subject[SIZE]; //To communicate with application
    char message[SIZE]; //To communicate with application

    int choice = 0;     //Choice for interface

    myStack.load();     //Load mail into Stack from text file

    myMenu.welcome();   //Welcomes user
    do
    {
        myMenu.space(SIZE);          //Clean output buffer
        choice = myMenu.interface(); //Calls interface function to display user interface

        myMenu.space(SIZE);          //Clean output buffer

        switch (choice)              //Switch statement with 9 commands
        {
            case 1: //Push Mail
            {
                cout << "Input name: ";
                cin.get(name,SIZE,'\n'); cin.ignore(SIZE,'\n');

                cout << "\nInput date: ";
                cin.get(date,SIZE,'\n'); cin.ignore(SIZE,'\n');

                cout << "\nInput email: ";
                cin.get(email,SIZE,'\n'); cin.ignore(SIZE,'\n');

                cout << "\nInput subject: ";
                cin.get(subject,SIZE,'\n'); cin.ignore(SIZE,'\n');

                cout << "\nInput message: ";
                cin.get(message,SIZE,'\n'); cin.ignore(SIZE,'\n');
                myMail.set(name, date, email, subject, message); //Sets mail from user input

                myStack.push(myMail); //Push mail into stack made from user input
                myMenu.check();       //Pause
            }break;

            case 2: //Peek Mail
            {
                if(myStack.peek(myMail)) //If there is a top, look at top, copy through argument
                    myMail.display();    //Display mail modified through reference
                myMenu.check();          //Pause
            }break;

            case 3: //Pop Mail
            {
                if(myStack.peek(myMail)) //If there is a top, copy top into arugment
                {
                    myMail.display();    //Display mail through reference
                    myStack.pop();       //Decrement top, remove top of stack
                }
                myMenu.check();
            }break;

             case 4: //Display Mail
            {
                myStack.display(); //Display all of mail in stack
                myMenu.check();
            }break;

            case 5: //Enqueue VIP
            {
                cout << "Input name: ";
                cin.get(name,SIZE,'\n'); cin.ignore(SIZE,'\n');

                cout << "\nInput date: ";
                cin.get(date,SIZE,'\n'); cin.ignore(SIZE,'\n');

                cout << "\nInput email: ";
                cin.get(email,SIZE,'\n'); cin.ignore(SIZE,'\n');

                cout << "\nInput subject: ";
                cin.get(subject,SIZE,'\n'); cin.ignore(SIZE,'\n');

                cout << "\nInput message: ";
                cin.get(message,SIZE,'\n'); cin.ignore(SIZE,'\n');

                myMail.set(name, date, email, subject, message); //Sets mail according to user input
                myQueue.enqueue(myMail); //Enqueue maul into front of CLL

                myMenu.check();
            }break;

            case 6: //Peek VIP
            {
                if(myQueue.peek(myMail)) //If there is a front, copy through argument
                    myMail.display();    //Display the front mail in CLL
                myMenu.check();
            }break;

            case 7: //Dequeue VIP
            {
                if(myQueue.peek(myMail)) //If there is mail in the front, copy through argument
                {
                    myMail.display();    //Display front of queue
                    myQueue.dequeue();   //Remove front mail of queue
                }
                myMenu.check();
            }break;

            case 8: //Display VIP
            {
                myQueue.display(); //Displays all items in queue
                myMenu.check();
            }break;

            default:break;
        }
    }while (choice!=9); //Exit program
    return 0;
}
