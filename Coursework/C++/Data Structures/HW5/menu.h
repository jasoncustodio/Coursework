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

//Organizes output
class menu
{
    public: menu();           //constructor
            void check ();    //Checkpoint pause
            void welcome();   //Welcome user
            int  interface(); //Display user interface
            void space (int); //Provides clean output buffer
};
