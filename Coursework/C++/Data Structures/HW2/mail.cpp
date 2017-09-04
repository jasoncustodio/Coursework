/*
    Program:     Inbox
    Author:      Jason Custodio
    Class:       CS163
    Date:        02/11/2014
    Description: Object to be manipulated in stack and queue
                 Holds a dynamic char array for: name, date, email, subject, message
*/

#include "inbox.h"

//Constructor, sets char arrays to NULL
mail::mail()
{
   name    = NULL;
   date    = NULL;
   email   = NULL;
   subject = NULL;
   message = NULL;
}

//Destructor, deletes mail's private data members if it exists
mail::~mail()
{
    if(name)    delete [] name;
    if(date)    delete [] date;
    if(email)   delete [] email;
    if(subject) delete [] subject;
    if(message) delete [] message;
}

//Sets private data members from application
void mail::set(char setN[], char setD[], char setE[], char setS[], char setM[])
{
    if(name)    delete [] name;         //To prevent core dumps
    if(date)    delete [] date;
    if(email)   delete [] email;
    if(subject) delete [] subject;
    if(message) delete [] message;

    name    = new char[strlen(setN)+1]; //All dynamically allocated char arrays
    date    = new char[strlen(setD)+1];
    email   = new char[strlen(setE)+1];
    subject = new char[strlen(setS)+1];
    message = new char[strlen(setM)+1];

    strcpy(name,    setN);
    strcpy(date,    setD);
    strcpy(email,   setE);
    strcpy(subject, setS);
    strcpy(message, setM);
}

//Sets private data members by copying from referenced argument
void mail::copy(const mail& copyM)
{
    if(name)    delete [] name; //Prevent core dumps
    if(date)    delete [] date;
    if(email)   delete [] email;
    if(subject) delete [] subject;
    if(message) delete [] message;

    name    = new char[strlen(copyM.name)+1];
    date    = new char[strlen(copyM.date)+1];
    email   = new char[strlen(copyM.email)+1];
    subject = new char[strlen(copyM.subject)+1];
    message = new char[strlen(copyM.message)+1];

    strcpy(name,    copyM.name);
    strcpy(date,    copyM.date);
    strcpy(email,   copyM.email);
    strcpy(subject, copyM.subject);
    strcpy(message, copyM.message);
}

//Displays mail's data private members
int mail::display()
{
    cout << "\nName: "    << name
         << "\nDate: "    << date
         << "\nEmail: "   << email
         << "\nSubject: " << subject
         << "\nMessage: " << message
         << endl;
}





