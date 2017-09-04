/*
    Program:     Inbox
    Author:      Jason Custodio
    Class:       CS163
    Date:        02/11/2014
    Description: Stack implemented using a flexible array
                 If an array is MAX(5) create a new node
*/

#include "inbox.h"

//Constructor, sets head pointer to NULL and top index to 0
stack::stack()
{
    head = NULL;
    top = 0;
}

//Destructor to deallocate head pointer
stack::~stack()
{
    if(head)
    {
        delete head;
        head = NULL;
    }
}

//Destructor for dynamic mail array
nodeS::~nodeS()
{
    if(data) delete [] data;
}

//Push mail to top of stack
int stack::push(const mail& addMail )
{
    if(top==MAX) top = 0; //When top reaches MAX, reset top to 0

    if(!top)              //When top index is 0, create a new node with a stack in first index
    {
        nodeS * temp = head;

        head = new nodeS;
        head->data = new mail[MAX];
        head->next = temp;

        head->data[0].copy(addMail); //Copies the mail passed in through reference
        return ++top;                //Increment top everytime push is called
    }
    else
    {
        head->data[top].copy(addMail); //Put mail on top of stack
        return ++top;
    }
}

//Decrements the top
int stack::pop()
{
    if(!head) return 0; //Checks if there is a top

    else if(!--top)     //Decrement top, if it becomes 0, delete node, go to next
    {
        nodeS * temp = head->next;

        delete head;
        head = temp;
        top = MAX;
    }
    return 1;
}

//Looks at top of stack
int stack::peek(mail& peekM)
{
    if(!head) return 0; //No top, return false

    peekM.copy(head->data[top-1]); //Provide information on top of stack through argument
    return 1;
}

//Display all mail in the stack
int stack::display()
{
    if(!head) return 0;

    nodeS * current = head;
    int i = top;

    if(top < MAX)             //Used to display a nonfull array
        for(--i; i >= 0; --i)
            current->data[i].display();
    else
        for(i=4; i >= 0; --i) //Displays a full array
            current->data[i].display();

    for(current = head->next; current; current=current->next) //Displays rest of full arrays
        for(i=4; i >= 0; --i)
            current->data[i].display();

    return 1;
}

//Load mail info from a text file
void stack::load()
{
    ifstream inFile;
    mail myMail;

    char name   [SIZE];
    char date   [SIZE];
    char email  [SIZE];
    char subject[SIZE];
    char message[SIZE];

    inFile.open("mail.txt");

    if(inFile)
    {
        inFile.ignore(SIZE, ' ');
        inFile.get(name, SIZE, '\n');
        inFile.ignore(SIZE, '\n');

        while(inFile && !inFile.eof())
        {
            inFile.ignore(SIZE, ' ');
            inFile.get(date, SIZE, '\n');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(email, SIZE, '\n');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(subject, SIZE, '\n');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(message, SIZE, '\n');
            inFile.ignore(SIZE, '\n');

            myMail.set(name, date, email, subject, message); //Sets a mail's member data
            push(myMail);                                    //Push that mail into stack

            inFile.ignore(SIZE, ' ');
            inFile.get(name, SIZE, '\n');
            inFile.ignore(SIZE, '\n');
        }
    }
    inFile.close();
}

