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

//****************************************************************//

//Constructor sets root to NULL
table::table()
{
    root = NULL;
}

//Destructor calls removeALL
table::~table()
{
    removeAll(root);
}

//****************************************************************//

//Wrapper function for display
int table::display()
{
    return display(root);
}

//Wrapper function for removeAll
int table::removeAll()
{
    return removeAll(root);
}

//Wrapper function for remove
int table::remove(char title[], char section[])
{
    char key [SIZE];

    strcpy(key, title);
    strcat(key, section);

    return remove(root, key);
}

//Wrapper function for retrieve
int table::retrieve(char title[], char section[], course& find)
{
    char key [SIZE];

    strcpy(key, title);
    strcat(key, section);

    return retrieve(root, key, find);
}

//Wrapper function for insert
int table::insert(char key[], const course& add)
{
    return insert(root, key, add);
}

//****************************************************************//

//Display all courses in binary tree
int table::display(node * &root)
{
    if(!root) return 0;

    display(root->left); //In order traversal
    root->data.display();
    display(root->right);
}

//Removes all nodes in binary tree
int table::removeAll(node * &root)
{
    if(!root) return 0;

    removeAll(root->left); //Post order traversal
    removeAll(root->right);

    delete root;
    root = NULL;
}

//Removes course recursively using title and section
int table::remove(node * &root, char key[])
{
    if(!root) return 0;

    if(!root->data.retrieve(key))
    {
        if(!root->left && !root->right)     //Remove leaf
        {
            delete root;
            root = NULL;
            return 1;
        }
        else if(root->left && !root->right) //Remove root with left child
        {
            node * temp = root->left;
            delete root;
            root = temp;
            return 1;
        }
        else if(!root->left && root->right) //Remove root with right child
        {
            node * temp = root->right;
            delete root;
            root = temp;
            return 1;
        }
        else if(!root->right->left && root->right->right) //Remove root with 2 children
        {
            node * temp = root->right->right;             //In order successor is right child's right child
            root->data.copy(root->right->data);
            delete root->right;
            root->right = temp;
            return 1;
        }
        else //Remove root with 2 children
        {
            node * current;
            node * previous;

            for(current=root->right; current->left; current=current->left) //Go right twice, then spin all the way left
                previous = current;

            previous->left = current->right;                               //Connect in order successor's right child/tree
            root->data.copy(current->data);

            delete current;
            return 1;
        }
    }
    if(root->data.retrieve(key) < 0)
        remove(root->left, key);
    else
        remove(root->right, key);
}

//Finds course according to title and section
int table::retrieve(node * &root, char key[], course &find)
{
    if(!root) return 0;

    if(!root->data.retrieve(key))
    {
        find.copy(root->data);
        return 1;
    }

    if(root->data.retrieve(key) < 0)
        retrieve(root->left, key, find);  //Go left of tree is less than
    else
        retrieve(root->right, key, find); //Go right of right if greather than
}

//Insert into binary search tree already in sorted order
int table::insert(node * &root, char key[], const course &add)
{
    if(!root)
    {
        root = new node;
        root->data.copy(add);
        root->left = root->right = NULL;
        return 1;
    }

    if(root->data.retrieve(key) < 0)
        insert(root->left, key, add);
    else
        insert(root->right, key, add);
}

//****************************************************************//

//Load courses info from a text file
void table::load(char text[])
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

    char key [SIZE];

    inFile.open(text);

    if(inFile)
    {
        inFile.ignore(SIZE, ' ');
        inFile.get(crn, SIZE, '\n');
        inFile.ignore(SIZE, '\n');

        while(inFile && !inFile.eof())
        {
            inFile.ignore(SIZE, ' ');
            inFile.get(days, SIZE, '\n');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(time, SIZE, '\n');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(title, SIZE, '.');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(credit, SIZE, '\n');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(subject, SIZE, '\n');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(section, SIZE, '.');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(location, SIZE, '\n');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(instructor, SIZE, '\n');
            inFile.ignore(SIZE, '\n');

            myCourse.set(crn, days, time, title, credit, subject,  //Sets a course's member data
                         section, location, instructor);

            strcpy(key, title);
            strcat(key, section);

            insert(key, myCourse);                                 //Insert course into hash table

            inFile.ignore(SIZE, ' ');
            inFile.get(crn, SIZE, '\n');
            inFile.ignore(SIZE, '\n');
        }
    }
    inFile.close();
}

//****************************************************************//
