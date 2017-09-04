/*
    Program:     Graph
    Author:      Jason Custodio
    Class:       CS163
    Date:        03/20/2014
    Description: This program will simulates a quiz for computers
                 A list of vertices are used with edges that connect to adjacent vertices
                 The vertices and edges are loaded from an external file
                 Each node node holds an answer, a pointer to the next node, and index
                 The vertices hold a question, a visit flag, and a head pointer to a LLL
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

const int SIZE = 100; //Used to create arrays in main function
const int MAX  = 5;

using namespace std;

//Used to hold index/answers for vertex
struct node
{
    char * answer;   //Answer to question
    int index;       //Index of adjacent vertex
    node * next;     //Pointer to next adjacent vertex
};

//Holds questions and edge list
struct vertex
{
    char * question; //Quiz question
    int visit;       //Visit flag, 0=false, 1=true
    node * head;     //Edge list
};

//Graph of quiz questions
class table
{
      public:
             table();                             //Constructor sets root to NULL
             ~table();                            //Calls destructor


             int displayEdge(int);
             int takeQuiz(int);
             int displayVertex(int);              //Wrapper function for displayVertex
             int displayQuiz();                   //Wrapper function for in depth
             int insertVertex(char[]);            //Wrapper function for insert
             int insertEdge(char[], int, int);    //Wrapper function for insert
             int traverse(int);

             void reset();
             void load(char[], char[]);            //Load courses from external file

      private:
              vertex * list;                       //Vertex pointer to adjacency list
	          int num;                             //Number of vertices

              int displayVertex(node*&);              //Displays vertex
             // int displayQuiz(node*&);             //Displays using in depth traversal
              int insertVertex(char*, char[]);     //Inserts Vertex
              int insertEdge(node*&, char[], int); //Inserts edge

};

