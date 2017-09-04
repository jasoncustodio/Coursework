/*
    Program:     Adventure Map
    Author:      Jason Custodio
    Class:       CS202
    Date:        04/16/2014
    Description: This program simulates a math riddle game
                 There will be a menu class that acts as an interface
                 A player roster will be implemented in the future
                 The info class acts as any kind of simple data
                 A player is derived from the info class
                 A player has a score, a name, a location, and inventory
                 The score is only an int, the name is info, the location
                 is the index of where it is in the map
                 Inventory is a DLL that holds items found in the map
                 An item is an info
                 Info only has a name and points to the next and previous items
                 The map is implemented using a graph
                 Each vertex holds a question, location, object, a visit flag, and
                 a head pointer to a LLL of edges
                 Each edge holds an answer, index of where it points to, and a pointer
                 to the next edge
                 To win the game, you must get to the end
                 Whoever gets the highest score at the end wins with multiplayer
*/

const int MAX   = 18;   //Max number of vertices
const int SPACE = 100;  //Used to clear output buffer
const int EXIT  = 3;    //Used to exit the program
const int SIZE  = 2000; //Used to create arrays in main function
const int TRUE  = 100;  //Used to add to score if answer is correct
const int FALSE = 1337; //Used if answer is false

#include "player.h"

//Node holds index for direction
class node
{
    public:
            node();                  //Default Constructor
            node(int,int, node*);    //Constructor
            ~node();                 //Destructor

            node*& goNext();         //Return the next node
            int getIndex();          //Return index
            int getAnswer();         //Return answer
            int compare(int);        //Compare user answer
            void connectNext(node*); //Connect node to next node

    private:
            int answer;              //Answer to question
            int index;               //Index of next vertex
            node * next;             //Pointer to next node
};

//Holds question, location, object, and edge list
class vertex
{
    public:
            vertex();                           //Default Constructor
            vertex(char*);                      //Constructor
	        ~vertex();                          //Destructor

            int compare(int);                   //Compare wrapper function
            int getIndex();                     //Return index of an edge
            node*& getHead();                   //Return head pointer
            void reset();                       //Resets all visit flags
            void display();                     //Displays all data members
            void displayObject();               //Displays object name
            void displayQuestion();             //Displays math question
            void displayLocation();             //Displays location
            void connectHead(node*);            //Connects head to edge
            void retrieveItem(info&);           //Retrieve item name in edge
            void setVertex(char*,char*,char*);  //Sets a vertex's data members

    private:
            info question; //Math question
            info location; //Location of the vertex
            info object;   //Object name in the vertex
            int visit;     //Visit flag, 0=false, 1=true
            node * head;   //Edge list

            int compare(node*&,int); //Compares the answer in the edge list
};

//Graph of adventure map
class map
{
      public:
             map();                                //Default constructor
             ~map();                               //Destructor

             void reset();                         //Resets visit flags
             int  compare(int,int);                 //Compares the answer in an edge
             void displayMap();                    //Display all vertices and edges
             void displayEdge(int);                //Displays all edges
             void displayVertex(int);              //Display all vertices
             void displayLocation(int);            //Display location
             void displayQuestion(int);            //Display question
             void load(char[], char[]);            //Load courses from external file
             void retrieveItem(info&,int);         //Gets object name in edge
             void insertEdge(int,int,int);         //Insert edge into a vertex
             void insertVertex(char*,char*,char*); //Insert vertex into graph

      private:
              vertex * list; //Vertex pointer to adjacency list
              int numVertex; //Number oof vertices in graph
};

