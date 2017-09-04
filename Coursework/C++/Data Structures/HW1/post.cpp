/*
    Program: Blogs
    Author:  Jason Custodio
    Class:   CS163
    Date:    01/23/2014
    Description: Used to create LLL for thread class
*/

#include "blog.h"

//Constructor for post
post::post()
{
   title   = NULL;
   comment = NULL;
   rating  = 0;
}

//Destructor for post
post::~post()
{
    if(title)
        delete [] title;
    if(comment)
        delete [] comment;
}

//Helper function to communicate with application
void post::set(char setTitle[], char setComment[])
{
    if(title)   delete [] title;
    if(comment) delete [] comment;

    title   = new char[strlen(setTitle)+1];
    comment = new char[strlen(setComment)+1];

    strcpy(title, setTitle);
    strcpy(comment, setComment);
}

//Helper function to add a post
void post::copy(const post & copyPost)
{
    if(title)   delete [] title;
    if(comment) delete [] comment;

    title   = new char[strlen(copyPost.title)+1];
    comment = new char[strlen(copyPost.comment)+1];

    strcpy(title, copyPost.title);
    strcpy(comment, copyPost.comment);

    rating = 0;
}

//Displays post's data private members
int post::display()
{
    cout << "\nTitle: "   << title
         << "\nComment: " << comment
         << "\nRating: "  << rating
         << endl;
}

//Helper function to rate a post
int post::find(char match[], int newRate)
{
    if(strcmp(title, match))
        return 0;
    else
        rating = newRate;
        return 1;
}

//Helper function to search through LLL
int post::find(char match[])
{
    if(strcmp(title, match))
        return 0;
    else
        return 1;
}








