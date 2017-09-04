/*
    Program: Blogs
    Author:  Jason Custodio
    Class:   CS163
    Date:    01/23/2014
    Description: Used to create LLL for blog class
*/

#include "blog.h"

//Constructor for Thread
thread::thread()
{
    topic = NULL;
    head  = NULL;
    tail  = NULL;
}

//Destructor for Thread
thread::~thread()
{
    delete [] topic;

    if(head)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
}

//Destructor for post node
nodeP::~nodeP()
{
    if(next)
    {
        delete next;
        next = NULL;
    }
}

//A helper function
void thread::copyTopic(char newTopic[])
{
    if(topic) delete [] topic;
    topic = new char[strlen(newTopic)+1];
    strcpy(topic, newTopic);

    head = NULL;
    tail = NULL;
}

//Adds post to thread's LLL
int thread::addPost(const post & newPost)
{
    nodeP * temp = new nodeP;
    temp->data.copy(newPost);
    temp->next = NULL;

    if(!head)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = tail->next;
    }
}

//Displays all posts in thread
int thread::display()
{
    nodeP * current;

    if(!head) return 0;

    else
    {
        cout << "\nThread: " << topic << endl;
        for(current=head; current; current=current->next)
            current->data.display();
    }
}

//Changes rating of a post
int thread::ratePost(char title[], int newRate)
{
    nodeP * current;

    if (!head) return 0;

    for(current = head; current; current = current->next)
    {
        if(current->data.find(title, newRate))
        {
            return 1;
        }
    }
    return 0;
}

//Helper function to match topic
int thread::find(char newTopic[])
{
    if(strcmp(topic, newTopic))
        return 0;
    else
        return 1;
}

