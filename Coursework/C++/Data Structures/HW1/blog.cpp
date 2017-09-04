/*
    Program: Blogs
    Author:  Jason Custodio
    Class:   CS163
    Date:    01/23/2014
    Description: Holds functions for class blog and nodeT

*/

#include "blog.h"

//Constructor to set pointers to NULL
blog::blog()
{
    head = NULL;
    tail = NULL;
}

//Destructor to deallocate pointers
blog::~blog()
{
    if(head)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
}

//Destructor for thread node
nodeT::~nodeT()
{
    if(next)
    {
        delete next;
        next = NULL;
    }
}

//Helper function for add function
void blog::addThread(char topic[], post& newPost)
{
    nodeT * temp = new nodeT;
    temp->data.copyTopic(topic);
    temp->next = NULL;

    if(!head)
    {
        head = temp;
        tail = head;
    }
    else
    {
        tail->next = temp;
        tail = tail->next;
    }
    temp->data.addPost(newPost);
}

//Adds a post to a thread
int blog::add(char topic[], post& newPost)
{
    nodeT * current;

    if(!head)
    {
        addThread(topic, newPost);
        return 0;
    }
    else
    {
        for(current = head; current; current = current->next)
        {
            if(current->data.find(topic))
            {
                current->data.addPost(newPost);
                return 1;
            }
        }
        addThread(topic, newPost);
        return 0;
    }
}

//Displays all threads and posts
int blog::display()
{
    nodeT * current;

    if(!head) return 0;

    else
    {
        for(current=head; current; current=current->next)
        {
           current->data.display();
           cout << "\n--------------\n";
        }
        return 1;
    }
}

//Display specific thread
int blog::display(char topic[])
{
    nodeT * current;

    if(!head) return 0;

    else
    {
        for(current=head; current; current=current->next)
        {
            if(current->data.find(topic))
            {
                current->data.display();
                return 1;
            }
        }
    }
    return 0;
}

//Rate a comment
int blog::rate(char topic[], char title[], int newRate)
{
    nodeT * current;

    if(!head) return 0;

    for(current=head; current; current=current->next)
    {
        if(current->data.find(topic))
            if(current->data.ratePost(title, newRate))
                return 1;
    }
    return 0;
}
