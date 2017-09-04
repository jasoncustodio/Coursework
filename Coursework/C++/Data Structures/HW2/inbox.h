/*
    Program:     Inbox
    Author:      Jason Custodio
    Class:       CS163
    Date:        02/11/2014
    Description: This program will simulate a email inbox
                 A stack is implemented to store emails
                 The emails are loaded in from an external file
                 A queue is implemented to keep the VIP messages
                 The stack uses a flexible array to gain direct access
                 Also to be able to dynamically allocate memory as needed
                 The queue uses a circular linked list format
                 Mail is queued in the rear and deqeueued from the front
                 The stack uses a top index to indicate where the top is
                 The stack and queue will each have its own type of node
                 Stack's node has an array of mail and a pointer to the next node
                 Queue's node has a mail and a pointer to the next node
                 Each data structure has a peek and display function
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

const int SIZE = 100; //Used to create arrays in main function
const int MAX = 5;    //Max index array for flexible array

using namespace std;

//The object that is manipulated in the stack and queue
class mail
{
    public:
            mail();  //Sets char pointers to NULL
            ~mail(); //Deallocates dynamic char arrays

            void set(char[], char[], char[], char[], char[]); //Sets the private member data in main
            void copy(const mail&);                           //Used for add function, to hide data structure
            int  display();                                   //Displays name, date, email, subject, message

    private:
            char * name;    //Name of sender
            char * date;    //Date that it is sent
            char * email;   //Email of sender
            char * subject; //Subject of message
            char * message; //Mail's message
};

//Used to traverse and hold array of mail for stack
struct nodeS
{
    mail  * data; //Each nodeS holds an array of mail
    nodeS * next; //Pointer to next nodeS for stack

    ~nodeS();     //Destructor for nodeS, deallocates char array
};

//Flexible array implemented to hold stack of mail
class stack
{
    public:
            stack();  //Creates stack, set head to NULL and top index to 0
            ~stack(); //Deallocates head

            int push(const mail&);  //Pushes a mail to top of stack, increment top index
            int pop();              //Decrements top
            int peek(mail&);        //Checks to see if there is a top and what is top
            int display();          //Display everything in the stack
            void load();            //Load mail from external file

    private:
            nodeS * head; //Head pointer for stack flexible array
            int top;      //Serves as top index with the MAX of 5
};

//Node made for Queue, holds one mail and a pointer to next node
struct nodeQ
{
    mail data;    //Each nodeQ holds a mail
    nodeQ * next; //Pointer to next nodeQ
};

//Implemented using a CLL, using FIFO
class queue
{
    public:
            queue();  //Sets rear to NULL
            ~queue(); //Deallocates rear

            int enqueue(const mail&); //Enqueues a mail to the read of the CLL
            int dequeue();            //Dequeues a mail from the front of the CLL
            int peek(mail&);          //Looks at the front of the queue
            int display();            //Displays everything in the queue

    private:
            nodeQ * rear; //The last node of the queue that points to the front of the queue
};
