/*
    Program:     Binary Search Tree
    Author:      Jason Custodio
    Class:       CS163
    Date:        03/13/2014
    Description: This program will simulate class registration
                 A binary search tree is implemented to store courses
                 The courses are loaded in from an external file
                 Each node in the binary search tree holds one course and a pointer to its left and right child
                 Most functions performed on the binary search tree is done recursively.
*/

#include "table.h"

//Constructor, sets char arrays to NULL
course::course()
{
    crn        = NULL;
    days       = NULL;
    time       = NULL;
    title      = NULL;
    credit     = NULL;
    subject    = NULL;
    section    = NULL;
    location   = NULL;
    instructor = NULL;
}

//Destructor, deletes course's private data members if it exists
course::~course()
{
    if(crn)        delete [] crn;
    if(days)       delete [] days;
    if(time)       delete [] time;
    if(title)      delete [] title;
    if(credit)     delete [] credit;
    if(subject)    delete [] subject;
    if(section)    delete [] section;
    if(location)   delete [] location;
    if(instructor) delete [] instructor;
}

//Sets private data members from application/text file
void course::set(char setCrn[], char setDays[], char setTime[], char setTitle[], char setCredit[],
               char setSubject[], char setSection[], char setLocation[], char setInstructor[])
{
    if(crn)        delete [] crn;
    if(days)       delete [] days;
    if(time)       delete [] time;
    if(title)      delete [] title;
    if(credit)     delete [] credit;
    if(subject)    delete [] subject;
    if(section)    delete [] section;
    if(location)   delete [] location;
    if(instructor) delete [] instructor;

    crn        = new char[strlen(setCrn)+1];     //All dynamically allocated char arrays
    days       = new char[strlen(setDays)+1];
    time       = new char[strlen(setTime)+1];
    title      = new char[strlen(setTitle)+1];
    credit     = new char[strlen(setCredit)+1];
    subject    = new char[strlen(setSubject)+1]; //All dynamically allocated char arrays
    section    = new char[strlen(setSection)+1];
    location   = new char[strlen(setLocation)+1];
    instructor = new char[strlen(setInstructor)+1];

    strcpy(crn,        setCrn);
    strcpy(days,       setDays);
    strcpy(time,       setTime);
    strcpy(title,      setTitle);
    strcpy(credit,     setCredit);
    strcpy(subject,    setSubject);
    strcpy(section,    setSection);
    strcpy(location,   setLocation);
    strcpy(instructor, setInstructor);
}

//Sets private data members by copying from referenced argument
void course::copy(const course& copyC)
{
    if(crn)        delete [] crn;
    if(days)       delete [] days;
    if(time)       delete [] time;
    if(title)      delete [] title;
    if(credit)     delete [] credit;
    if(subject)    delete [] subject;
    if(section)    delete [] section;
    if(location)   delete [] location;
    if(instructor) delete [] instructor;

    crn        = new char[strlen(copyC.crn)+1];     //All dynamically allocated char arrays
    days       = new char[strlen(copyC.days)+1];
    time       = new char[strlen(copyC.time)+1];
    title      = new char[strlen(copyC.title)+1];
    credit     = new char[strlen(copyC.credit)+1];
    subject    = new char[strlen(copyC.subject)+1]; //All dynamically allocated char arrays
    section    = new char[strlen(copyC.section)+1];
    location   = new char[strlen(copyC.location)+1];
    instructor = new char[strlen(copyC.instructor)+1];

    strcpy(crn,        copyC.crn);
    strcpy(days,       copyC.days);
    strcpy(time,       copyC.time);
    strcpy(title,      copyC.title);
    strcpy(credit,     copyC.credit);
    strcpy(subject,    copyC.subject);
    strcpy(section,    copyC.section);
    strcpy(location,   copyC.location);
    strcpy(instructor, copyC.instructor);
}

//Communicates with application to find match according to section
int course::retrieve(char key[])
{
    char check[SIZE];
    strcpy(check, title);
    strcat(check, section);

    return strcmp(key, check);
}

//Displays course's data private members
void course::display()
{
    cout << "\nCrn:        " << crn
         << "\nDays:       " << days
         << "\nTime:       " << time
         << "\nTitle:      " << title
         << "\nCredit:     " << credit
         << "\nSubject:    " << subject
         << "\nSection:    " << section
         << "\nLocation:   " << location
         << "\nInstructor: " << instructor
         << endl;
}










