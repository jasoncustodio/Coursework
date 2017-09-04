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

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

const int SIZE = 100; //Used to create arrays in main function
const int MAX = 13;   //Max index array for hash table

using namespace std;

//The object that is manipulated in the hash table
class course
{
    public:
            course();  //Sets char pointers to NULL
            ~course(); //Deallocates dynamic char arrays

            void  set(char[], char[], char[], char[], char[], //Sets the private member data in main
                     char[], char[], char[], char[]);
            void  copy(const course&);                        //Used for insert function, to hide data structure
            int   retrieveCourse (char []);                   //Finds a match based on title
            int   retrieveSection(char []);                   //Finds a match based on section
            void  displayCourse ();                           //Displays some info
            void  displaySection();                           //Displays full info

    private:
            char * crn;        //Info for all courses
            char * days;
            char * time;
            char * title;
            char * credit;
            char * subject;
            char * section;
            char * location;
            char * instructor;
};

//Used to traverse and hold courses for hash table
struct node
{
    course data; //Each node holds one course
    node * next; //Pointer to next node in chain
};

//Hash table that stores courses
class table
{
      public:
             table(int size=MAX); //Default contructor to set table size to 13
             ~table();
             int insert(char[], const course&);            //Insert into hash table using title as key
             int retrieveCourse(char[], course&);          //Finds course according to name
             int retrieveSection(char[], char[], course&); //Finds course according to section
             int hash(char[]) const;                       //Sums up all elements, modded by prime hash table size

             int remove(char[],char[]);                  //Wrapper function for remove
             int removeCourse(node * &, char[], char[]); //Remove according to title/section
             void display();                             //Display all courses in hash table
             void load();                                //Load courses from external file
             int hashTime(char[], char[]) const;
             int insertTime(char[], char[], const course&);
             void loadTime();
             void displayTime(char[], char[]);

      private:
              node ** hashTable;  //A dynamically allocated array of head pointers
              int tableSize;      //Maximum size of hashTable size

};

