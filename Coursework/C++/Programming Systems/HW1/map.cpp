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

#include "menu.h"

//Node
//****************************************************************//
//Node default constuctor
node::node():next(0), answer(0),index(0){}

//Node Destructor
node::~node()
{
    if(next) delete next;
}

//Node constructor
node::node(int a, int i, node* n):answer(a),index(i)
{
    connectNext(n);
}

//Go to next node
node*& node::goNext()
{
    return next;
}

//Connect next node
void node::connectNext(node* connect)
{
    next = connect;
}

//Return Answer
int node::getAnswer()
{
    return answer;
}

//Return index for direction
int node::getIndex()
{
    return index;
}

//Compares user's input to answer in edge
int node::compare(int check)
{
    if(answer == check) return 1;
    else return 0;
}
//****************************************************************//



//Vertex
//****************************************************************//
//Vertex defualt constructor
vertex::vertex():visit(0), head(0){}

//Item constructor
vertex::vertex(char * q):question(q),visit(0),head(0){}

//Vertex Destructor
vertex::~vertex()
{
    if(head) delete head;
}

//Wrapper function for compare
int vertex::compare(int answer)
{
    visit = 1;
    compare(getHead(), answer);
}

//Compares the answer in the vertex
int vertex::compare(node *& head, int answer)
{
    if(!head) return 0;

    if(head->compare(answer)) return head->getIndex();

    compare(head->goNext(), answer);
}

//Displays all in the vertex
void vertex::display()
{
    question.display();
    location.display();
    object.display();
}

//Displays question
void vertex::displayQuestion()
{
    question.display();
}

//Displays location
void vertex::displayLocation()
{
    location.display();
}

//Displays the object in vertex
void vertex::displayObject()
{
    object.display();
}

//Getter for the head node pointer
node*& vertex::getHead()
{
    return head;
}

//Used to connect the head
void vertex::connectHead(node* connect)
{
    head = connect;
}

//Resets all visit flags
void vertex::reset()
{
    visit = 0;
}

//Getter for head's index
int vertex::getIndex()
{
    return head->getIndex();
}

//Used to find the index to be used as an argument
void vertex::retrieveItem(info& myInfo)
{
    myInfo.copyInfo(object);
}

//Setter for all of vertex's data members
void vertex::setVertex(char * q, char * l, char * o)
{
    question.setInfo(q);
    location.setInfo(l);
    object.setInfo(o);
}
//****************************************************************//



//Map
//****************************************************************//
//Map default constructor
map::map():numVertex(0)
{
    list = new vertex[MAX];
}

//Destructor
map::~map()
{
	if(list) delete [] list;
}

//Compares answer to certain vertex
int map::compare(int i, int answer)
{
    return list[i].compare(answer);
}

//Displays Vertex
void map::displayVertex(int i)
{
    list[i].display();
}

//Displays edge and the index they hold
void map::displayEdge(int i)
{
    node * current;

    for(current = list[i].getHead(); current; current=current->goNext())
        cout << "(" << current->getIndex() << ") " << current->getAnswer() << endl;
}

//Display all
void map::displayMap()
{
    for(int i = 0; i < MAX; ++i)
    {
        displayVertex(i);
        displayEdge(i);
    }
}

//Insert a vertex into the map
void map::insertVertex(char * question, char * location, char * object)
{
    if(numVertex < MAX) //Keep inserting as long as array is not max
    {
        list[numVertex].setVertex(question, location, object);
        ++numVertex;
    }
}

//Used to communiate a reference object
void map::retrieveItem(info& myInfo, int i)
{
    list[i].retrieveItem(myInfo);
}

//Displays location of a vertex
void map::displayLocation(int i)
{
    list[i].displayLocation();
}

//Displays question of a vertex
void map::displayQuestion(int i)
{
    list[i].displayQuestion();
}

//Attach an edge to a vertex
void map::insertEdge(int answer, int current, int attach)
{
    node * temp = new node(answer, attach, list[current].getHead());
    list[current].connectHead(temp);
}

//Resets all visit flags
void map::reset()
{
    for(int i = 0; i < MAX; ++i)
        list[i].reset();
}

//Load vertex and edges from external file
void map::load(char vertexText[], char edgeText[])
{
    ifstream inFile;

    char question [SIZE];
    char location [SIZE];
    char object   [SIZE];

    int answer  = 0;
    int current = 0;
    int attach  = 0;

    //Load vertex into adjacency list
    inFile.open(vertexText);
    if(inFile)
    {
        inFile.ignore(SIZE, ' ');
        inFile.get(question, SIZE, '~');
        inFile.ignore(SIZE, '\n');

        while(inFile && !inFile.eof())
        {
            inFile.ignore(SIZE, ' ');
            inFile.get(location, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(object, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            insertVertex(question, location, object);

            inFile.ignore(SIZE, ' ');
            inFile.get(question, SIZE, '~');
            inFile.ignore(SIZE, '\n');
        }
    }
    inFile.close();

    //Now load edges into vertex
    inFile.open(edgeText);
    if(inFile)
    {
        inFile.ignore(SIZE, ' ');
        inFile >> answer;
        inFile.ignore(SIZE, '\n');

        while(inFile && !inFile.eof())
        {
            inFile.ignore(SIZE, ' ');
            inFile >> current;
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile >> attach;
            inFile.ignore(SIZE, '\n');

            insertEdge(answer, current, attach);

            inFile.ignore(SIZE, ' ');
            inFile >> answer;
            inFile.ignore(SIZE, '\n');
        }
    }
    inFile.close();
}
//****************************************************************//



