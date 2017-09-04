/*
    Program:     Hash Table
    Author:      Jason Custodio
    Class:       CS163
    Date:        02/25/2014
    Description: This program will simulate class registration
                 A hash table is implemented to store courses
                 The courses are loaded in from an external file
                 The hash table consists of a dynamically allocated array of node pointers
                 A hash function is used to put the course in a specified slot
                 The hash function sums up all the elements in the array modded by the array size
                 Each node consists of one course and a next node pointer
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

//Communicates with application to find match according to title
int course::retrieveCourse(char key[])
{
    if(!strcmp(title, key)) return 1;
    return 0;
}

//Communicates with application to find match according to section
int course::retrieveSection(char key[])
{
    if(!strcmp(section, key)) return 1;
    return 0;
}

//Displays course's data private members
void course::displaySection()
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

//Display part of course's data members
void course::displayCourse()
{
    cout << "\nTitle:      " << title
         << "\nCredit:     " << credit
         << "\nSubject:    " << subject
         << endl;
}











