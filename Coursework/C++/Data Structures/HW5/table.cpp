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


#include "table.h"

//****************************************************************//

//Constructor
table::table()
{
    list = new vertex [MAX];
    num = 0;

    for(int i = 0; i < MAX; ++i)
    {
        list[i].question = NULL;
        list[i].visit    = 0;
        list[i].head     = NULL;
    }
}

//Destructor
table::~table()
{
    node * current;
    node * temp;

    for(int i = 0; i < MAX; ++i)
    {
        if(list[i].head)
        {
            for(current=list[i].head; current; current=temp)
            {
                temp = current->next;
                delete [] current->answer;
                current->answer = NULL;
                delete current;
            }
        list[i].head = NULL;
        }
        if(list[i].question)
        {
            delete [] list[i].question;
            list[i].question = NULL;
        }
    }
    delete [] list;
    list = NULL;
}

//****************************************************************//

//Wrapper function for displayVertex
int table::displayVertex(int i)
{
    return displayVertex(list[i].head);
}

/*
//Wrapper function for displayQuiz
int table::displayQuiz()
{
    return displayQuiz(list[0].head);
} */

//Wrapper function for insertVertex
int table::insertVertex(char key[])
{
    return insertVertex(list[num].question, key);
}

//Wrapper function for insertEdge
int table::insertEdge(char key[], int current, int attach)
{
    return insertEdge(list[current].head, key, attach);
}

//****************************************************************//

//Display all vertices adjacent to the one specified
int table::displayVertex(node*&head)
{
    if(!head) return 0;

    cout << list[head->index].question << endl;

    displayVertex(head->next);
}

//Displays all edges of a vertex
int table::displayEdge(int i)
{
    node * current;

    for(current = list[i].head; current; current=current->next)
        cout << "(" << current->index << ") " << current->answer << endl;
}

int table::takeQuiz(int i)
{
    int option = 0;
    if(!list[i].head || list[i].visit) return 0;

    list[i].visit = 1;
    cout << list[i].question <<endl;
    displayEdge(i);

    cin >> option;
    takeQuiz(option);
}

//Display all
int table::displayQuiz()
{
    for(int i = 0; i < MAX; ++i)
    {
        cout << list[i].question << endl;
        displayEdge(i);
    }
}

int table::traverse(int i)
{
    if(!list[i].head || list[i].visit) return 0;

    list[i].visit = 1;
    cout << list[i].question << endl;

    traverse(list[i].head->index);
}

//Insert into binary search tree already in sorted order
int table::insertVertex(char * question, char key[])
{
    list[num].question = new char[strlen(key)+1];
    strcpy(list[num].question, key);
    ++num;
    return 1;
}

//Attach an edge to a vertex
int table::insertEdge(node *&head, char key[], int attach)
{
    node * temp = new node;

    temp->answer = new char[strlen(key)+1];
    strcpy(temp->answer, key);
    temp->index = attach;
    temp->next =  head;

    head = temp;
}

//****************************************************************//

void table::reset()
{
    for(int i = 0; i < MAX; ++i)
        list[i].visit = 0;
}

//Load vertex and edges from external file
void table::load(char vertexText[], char edgeText[])
{
    ifstream inFile;

    char key [SIZE];
    int current = 0;
    int attach  = 0;

    //Load vertex into adjacency list
    inFile.open(vertexText);
    if(inFile)
    {
        inFile.ignore(SIZE, ' ');
        inFile.get(key, SIZE, '~');
        inFile.ignore(SIZE, '\n');

        while(inFile && !inFile.eof())
        {
            insertVertex(key);

            inFile.ignore(SIZE, ' ');
            inFile.get(key, SIZE, '~');
            inFile.ignore(SIZE, '\n');
        }
    }
    inFile.close();

    //Now load edges into vertex
    inFile.open(edgeText);
    if(inFile)
    {
        inFile.ignore(SIZE, ' ');
        inFile.get(key, SIZE, '~');
        inFile.ignore(SIZE, '\n');

        while(inFile && !inFile.eof())
        {
            inFile.ignore(SIZE, ' ');
            inFile >> current;
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile >> attach;
            inFile.ignore(SIZE, '\n');

            insertEdge(key, current, attach);

            inFile.ignore(SIZE, ' ');
            inFile.get(key, SIZE, '~');
            inFile.ignore(SIZE, '\n');
        }
    }
    inFile.close();
}

//****************************************************************//
