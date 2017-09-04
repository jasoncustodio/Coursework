/*
    Program:     Inbox
    Author:      Jason Custodio
    Class:       CS163
    Date:        02/11/2014
    Description: Implemented using a CLL
                 Uses nodeQ to hold one mail and a pointer to next node
                 Enqueues mail from the rear and dequeues from the front
*/

#include "inbox.h"

//Constructor, sets rear to NULL
queue::queue()
{
    rear = NULL;
}

//Destructor, deletes rear
queue::~queue()
{
   if(rear)
   {
       delete rear;
       rear = NULL;
   }
}

//Adds a mail to the rear of the CLL
int queue::enqueue(const mail& addMail)
{
    if(!rear)
    {
        rear = new nodeQ;         //Creates a new node after rear, points to front
        rear->next = rear;

        rear->data.copy(addMail); //Copies the mail and enqueues the mail
        return 1;
    }

    nodeQ * temp = rear->next;

    rear->next = new nodeQ; //Create a new node, store front's address
    rear = rear->next;
    rear->next = temp;      //New rear points to stored temporary address

    rear->data.copy(addMail);
    return 1;
}

//Remove the front of the queue
int queue::dequeue ()
{
    if(!rear) return 0;     //Case for no items

    if(rear == rear->next)  //Case for 1 item
    {
        delete rear;
        rear = NULL;
        return 1;
    }

    nodeQ * temp = rear->next->next; //Case for 1+ items
    delete rear->next;
    rear->next = temp;
    return 1;
}

//Look at the front of the CLL
int queue::peek(mail& peekM)
{
    if(!rear) return 0;

    peekM.copy(rear->next->data); //Copies data in the front through argument
    return 1;
}

//Displays all mail in queue
int queue::display()
{
    if(!rear) return 0;

    nodeQ * current = rear->next;

    do                             //Uses do while to make sure it starts
    {
        current->data.display();
        current = current->next;
    }while(current != rear->next); //Stops when current equals where it starts

    return 1;
}
