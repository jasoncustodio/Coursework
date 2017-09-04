/*
    Program: Blogs
    Author:  Jason Custodio
    Class:   CS163
    Date:    01/23/2014
    Description: First welcome and instruct user how to use the program.
                 Display Interface.
                 Keep looping until user wants to exit.
                 Keep looping new lines to create clean screens after each command.
                 Add Threads and posts
                 Display all the linear linked lists
                 Have destructors to deallocate pointers
                 INPUT: TOPIC, TITLE, COMMENT, RATING
                 OUTPUT: LLL of threads/posts
*/

#include "blog.h"
#include "menu.h"

const int SIZE = 100;

int main()
{
    menu   myMenu;      //Help with interface
    blog   myBlog;      //Actual Blog
    thread myThread;    //Help with Blog
    post   myPost;      //Help with Thread

    char topic[SIZE];   //To communicate with application
    char title[SIZE];   //To communicate with application
    char comment[SIZE]; //To communicate with application
    int rating = 0;     //To communicate with application

    int choice = 0;     //Choice for interface

    myMenu.welcome();   //Welcomes user
    do
    {
        myMenu.space(100);
        choice = myMenu.interface(); //Calls interface function to display user interface

        myMenu.space(100);           //Creates a clean page after every command

        switch (choice)              //Switch statement with 6 commands
        {
            case 1: //Adds a thread/post
            {
                cout << "Input THREAD topic:  ";
                cin.get(topic,SIZE,'\n'); cin.ignore(SIZE,'\n');

                cout << "\nInput POST title:    ";
                cin.get(title,SIZE,'\n'); cin.ignore(SIZE,'\n');

                cout << "\nInput POST comments: ";
                cin.get(comment,SIZE,'\n'); cin.ignore(SIZE,'\n');
                myPost.set(title, comment);

                myMenu.space(100);

                if(myBlog.add(topic, myPost)) //Pass in arguments from user
                    cout << "\nPOST (" << title
                         << ") added to EXISTING THREAD ("
                         << topic << ")\n";
                else
                    cout << "\nPOST (" << title
                         << ") added to NEW THREAD ("
                         << topic << ")\n";

                myMenu.check();
            }break;

            case 2: //Displays specific thread
            {
                cout << "Input THREAD topic: ";
                cin.get(topic,SIZE,'\n'); cin.ignore(SIZE,'\n');

                myMenu.space(100);

                if(!myBlog.display(topic))
                    cout << "\nERROR\n";
                myMenu.check();
            }break;

            case 3: //Displays all threads/posts
            {
                if(!myBlog.display())
                    cout << "\nEMPTY BLOG\n";
                myMenu.check();
            }break;

             case 4: //Change rating of post
            {
                cout << "Input THREAD topic: ";
                cin.get(topic,SIZE,'\n'); cin.ignore(SIZE,'\n');

                cout << "\nInput POST title:   ";
                cin.get(title,SIZE,'\n'); cin.ignore(SIZE,'\n');

                cout << "\nInput POST rating:  ";
                cin  >> rating;

                myMenu.space(100);

                if(myBlog.rate(topic,title,rating))
                    cout << "\nPOST ("    << title
                         << ") in THREAD (" << topic
                         << ") RATING: "    << rating
                         << endl;
                else
                    cout << "\nERROR\n";

                myMenu.check();
            }break;

            default:break;
        }
    }while (choice!=5);
    return 0;
}
