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

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

const int SIZE = 100; //Used to create arrays in main function

using namespace std;

//The object that is manipulated in the binary tree
class course
{
    public:
            course();                            //Sets char pointers to NULL
            ~course();                           //Deallocates dynamic char arrays

            void  set(char[], char[], char[],    //Sets private member data in main
                      char[], char[], char[],
                      char[], char[], char[]);
            void  display ();                    //Display course info
            int   retrieve(char []);             //Match based on title/section
            void  copy    (const course&);       //Used for insert function

    private:
            char * crn;                          //Info for all courses
            char * days;
            char * time;
            char * title;
            char * credit;
            char * subject;
            char * section;
            char * location;
            char * instructor;
};

//Used to traverse and hold courses for binary tree
struct node
{
    course data;  //Each node holds one course
    node * left;  //Pointer to left child
    node * right; //Pointer to right child
};

//Binary tree that sorts courses depending on name and section
class table
{
      public:
             table();                                //Constructor sets root to NULL
             ~table();                               //Calls removeAll

             int display  ();                        //Wrapper function for display
             int removeAll();                        //Wrapper function for removeAll
             int remove   (char[], char[]);          //Wrapper function for remove
             int retrieve (char[], char[], course&); //Wrapper function for retrieve
             int insert   (char[], const course&);   //Wrapper function for insert

             void load(char[]);                      //Load courses from external file

      private:
              node * root;                                   //Node pointer to root of binary tree

              int display  (node *&);                        //Display all courses in tree
              int removeAll(node *&);                        //Removes all nodes in binary tree
              int remove   (node *&, char[]);                //Remove course based on title/section
              int retrieve (node *&, char[], course&);       //Retrieve course based on title/section
              int insert   (node *&, char[], const course&); //Insert into binary tree using external file

};

