/*
    Program: Blogs
    Author:  Jason Custodio
    Class:   CS163
    Date:    01/23/2014
    Description: Contains all structs and classes necessary for this program.
                 Two structs are used as nodes, each containing a class.
                 Class Blog will be a LLL using these nodes.
*/

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

//Each thread has a LLL of posts
class post
{
    public:
            post();  //Sets char pointers to NULL
            ~post(); //Deallocates dynamic char arrays

            void set(char[], char[]); //Sets the private member data
            void copy(const post&);   //Used for add function
            int display();            //Displays title, comment, rating
            int find(char[], int);    //Used for rate function
            int find(char[]);         //Overloaded to find sepcific post

    private:
            char * title;   //Title of post
            char * comment; //Post's comments
            int rating;     //Rating of post
};

//Used to traverse and hold posts for thread
struct nodeP
{
    post data;    //Each nodeP holds a post
    nodeP * next; //Pointer to next nodeP for LLL

    ~nodeP();     //Destructor for nodeP, makes next point to NULL
};

//Used to hold LLL posts for blog
class thread
{
    public:
            thread();  //Creates thread, sets pointers to NULL
            ~thread(); //Deallocates pointers that are !NULL

            void copyTopic(char[]);    //Used to communicate with application
            int addPost(const post&);  //Adds post to LLL
            int display();             //Displays all posts in thread
            int ratePost(char[], int); //Changes rating of a post
            int find(char[]);          //Used to locate specific posts

    private:
            char * topic; //Title of thread

            nodeP * head; //Head pointer for post LLL
            nodeP * tail; //Tail pointer for post LLL
};

//Used to create LLL of threads for blog
struct nodeT
{
    thread data;  //Each nodeT holds a thread
    nodeT * next; //Pointer to next Thread

    ~nodeT();     //Deallocates pointer memory
};

//Holds LLL of threads
class blog
{
    public:
            blog();  //Sets nodeT pointers to NULL
            ~blog(); //Deallocates pointers

            void addThread(char[], post&); //Helper function for add
            int add(char[], post&);        //Adds thread to LLL
            int display();                 //Display all threads and posts
            int display(char[]);           //Display a particular thread
            int rate(char[], char[], int); //Rate a comment

    private:
            nodeT * head; //this is for the LLL of topics
            nodeT * tail; //Points to end of LLL of threads
};
