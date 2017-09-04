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

//Constructor for hash table, allocates hash table, sets elements to 0
table::table(int size)
{
    hashTable = new node*[size];
    tableSize = size;

    for(int i=0; i<size; ++i)
       hashTable[i] = NULL;
}

//Deallocates array of pointers
table::~table()
{
    node * current;
    node * temp;

    for(int i = 0; i < tableSize; ++i)
    {
        if(hashTable[i])
        {
            for(current=hashTable[i]; current; current=temp)
            {
                temp = current->next;
                delete current;
            }
        hashTable[i] = NULL;
        }
    }
    delete [] hashTable;
    hashTable = NULL;
}

//Using a hash function, insert a new value into head of chain
int table::insert(char key[], const course & addCourse)
{
    node * temp;

    int i = hash(key);

    if(!hashTable[i]) //If head pointer is null, create at start
    {
        hashTable[i] = new node;
        hashTable[i]->data.copy(addCourse);
        hashTable[i]->next = NULL;
        return 1;
    }
    else //Create at end of chain
    {
        temp = new node;
        temp->data.copy(addCourse);
        temp->next = hashTable[i];
        hashTable[i] = temp;
        return 1;
    }
}

//Using a hash function determine which chain to search
int table::retrieveCourse(char key[], course & newCourse)
{
    node * current;

    for(current = hashTable[hash(key)]; current; current = current->next)
    {
        if(current->data.retrieveCourse(key)) //Uses strcmp to retrieve
        {
            newCourse.copy(current->data);
            return 1;
        }
    }
    return 0;
}

//Using hash function to determine chain according to title and section
int table::retrieveSection(char key[], char id[], course & newCourse)
{
    node * current;

    for(current = hashTable[hash(key)]; current; current = current->next)
    {
        if(current->data.retrieveSection(id) && current->data.retrieveCourse(key))
        {
            newCourse.copy(current->data);
            return 1;
        }
    }
    return 0;
}

//Sums all elements modded by const MAX
int table::hash(char key[]) const
{
    int sum = 0;

    for(int i = 0; i < strlen(key); ++i)
        sum += key[i];
    sum %= MAX;

    return sum;
}

//Load courses info from a text file
void table::load()
{
    ifstream inFile;
    course myCourse;

    char  crn        [SIZE];
    char  days       [SIZE];
    char  time       [SIZE];
    char  title      [SIZE];
    char  credit     [SIZE];
    char  subject    [SIZE];
    char  section    [SIZE];
    char  location   [SIZE];
    char  instructor [SIZE];

    inFile.open("course.txt");

    if(inFile)
    {
        inFile.ignore(SIZE, ' ');
        inFile.get(crn, SIZE, '~');
        inFile.ignore(SIZE, '\n');

        while(inFile && !inFile.eof())
        {
            inFile.ignore(SIZE, ' ');
            inFile.get(days, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(time, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(title, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(credit, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(subject, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(section, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(location, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(instructor, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            myCourse.set(crn, days, time, title, credit, subject,  //Sets a course's member data
                         section, location, instructor);

            insert(title, myCourse);                               //Insert course into hash table

            inFile.ignore(SIZE, ' ');
            inFile.get(crn, SIZE, '~');
            inFile.ignore(SIZE, '\n');
        }
    }
    inFile.close();
}

//Display all courses in hash table
void table::display()
{
    node * current;

    for(int i = 0; i < tableSize; ++i)
    {
        if(hashTable[i])
        {
            for(current=hashTable[i]; current; current=current->next)
            {
                cout << "\nChain: " << i << " "; //Shows the array index
                current->data.displaySection();
            }
        }
    }
}

//Removes course recursively using title and section
int table::removeCourse(node * &head, char key[], char id[])
{
    if(!head) return 0;

    if(head->data.retrieveCourse(key) && head->data.retrieveSection(id))
    {
        node * temp = head->next;
        delete head;
        head = temp;
        return 1;
    }
    else removeCourse(head->next,key,id);
}

//Wrapper function for removeCourse
int table::remove(char key[], char id[])
{
    return removeCourse(hashTable[hash(key)], key, id);
}

int table::hashTime(char key[], char id[]) const
{
    int sum = 0;
    int i;

    for(i = 0; i < strlen(key); ++i)
        sum += key[i];
    for(i = 0; i < strlen(id); ++i)
        sum += key[i];
    sum += (' ');
    sum %= MAX;

    return sum;
}

int table::insertTime(char key[], char id[], const course & addCourse)
{
    node * temp;

    int i = hashTime(key, id);

    if(!hashTable[i]) //If head pointer is null, create at start
    {
        hashTable[i] = new node;
        hashTable[i]->data.copy(addCourse);
        hashTable[i]->next = NULL;
        return 1;
    }
    else //Create at end of chain
    {
        temp = new node;
        temp->data.copy(addCourse);
        temp->next = hashTable[i];
        hashTable[i] = temp;
        return 1;
    }
}

void table::loadTime()
{
    ifstream inFile;
    course myCourse;

    char  crn        [SIZE];
    char  days       [SIZE];
    char  time       [SIZE];
    char  title      [SIZE];
    char  credit     [SIZE];
    char  subject    [SIZE];
    char  section    [SIZE];
    char  location   [SIZE];
    char  instructor [SIZE];

    inFile.open("course.txt");

    if(inFile)
    {
        inFile.ignore(SIZE, ' ');
        inFile.get(crn, SIZE, '~');
        inFile.ignore(SIZE, '\n');

        while(inFile && !inFile.eof())
        {
            inFile.ignore(SIZE, ' ');
            inFile.get(days, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(time, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(title, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(credit, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(subject, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(section, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(location, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(instructor, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            myCourse.set(crn, days, time, title, credit, subject,  //Sets a course's member data
                         section, location, instructor);

            insertTime(days, time, myCourse);                               //Insert course into hash table

            inFile.ignore(SIZE, ' ');
            inFile.get(crn, SIZE, '~');
            inFile.ignore(SIZE, '\n');
        }
    }
    inFile.close();
}

void table::displayTime(char key[], char id[])
{
    node * current;

    for(current = hashTable[hashTime(key, id)]; current; current = current->next)
        current->data.displaySection();
}


