#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int SIZE = 100;

struct node
{
       char * data;
       node * next;

       ~node();
};

class list
{
    public: list       ();     //constructor - initializes data members
            ~list      ();    //destructor - deallocate all dynamic memory
            void add   ();
            void move  ();
            int  count ();
            void check (); //Checkpoint pause

            void remove    ();
            void display   ();
            void welcome   (); //Welcome user
            int  interface (); //Display user interface
            void removeAll ();
            void space     (int); //Provides clean output buffer

    private: node * head;                 //The head of a linear linked list
};
