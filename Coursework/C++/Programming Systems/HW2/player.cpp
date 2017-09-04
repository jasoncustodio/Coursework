/*
    Program:     Adventure Map
    Author:      Jason Custodio
    Class:       CS202
    Date:        05/07/2014
    Description: This program simulates a math riddle game
                 There will be a menu class that acts as an interface
                 Menu has a roster and has a map
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

//Info
//****************************************************************//
//Info default constructor
info::info():data(0){}

//Info constructor
info::info(char* newData)
{
    data = new char[strlen(newData)+1];
    strcpy(data, newData);
}

//Info copy constructor
info::info(const info& newInfo)
{
    data = new char[strlen(newInfo.data)+1];
    strcpy(data, newInfo.data);
}

//Info destructor
info::~info()
{
    if(data)
    {
        delete [] data;
        data = NULL;
    }
}

//Info data setter
void info::setInfo(char* newData)
{
    if(data) delete [] data;
    data = new char[strlen(newData)+1];
    strcpy(data, newData);
}

//Info data copier
void info::copyInfo(const info& newInfo)
{
    if(data) delete [] data;

    data = new char[strlen(newInfo.data)+1];
    strcpy(data, newInfo.data);
}

//Info compares another data
bool info::compare(const char* newData) const
{
    if(!strcmp(data, newData)) return 1;
    return 0;
}

//Display data
void info::display() const
{
    cout << data << endl;
}
//****************************************************************//



//Item
//****************************************************************//
//Item default constructor
item::item():next(0),previous(0){}

//Item destructor
item::~item()
{
    if(next) delete next;
}

//Item constructor
item::item(const info& n):info(n),next(0),previous(0){}

//Go to next item
item*& item::goNext()
{
    return next;
}

//Go to previous item
item*& item::goPrevious()
{
    return previous;
}

//Connect next item
void item::connectNext(item* connect)
{
    next = connect;
}

//Connect previous item
void item::connectPrevious(item* connect)
{
    previous = connect;
}

//Used for dynamic binding
void item::display() const
{
    cout << data << endl;
}
//****************************************************************//



//Player
//****************************************************************//
//Player default constructor
player::player():score(0),location(0),inventory(0)
{
    char * name = new char[7];
    strcpy(name,"Player");
    setInfo(name);
    delete [] name;
}

//Player destructor
player::~player()
{
	if(inventory) delete inventory;
}

//Add to player score
void player::addScore(int add)
{
    score+=add;
}

//Insert item into DLL
void player::addItem(info& object)
{
    item * temp = new item(object);

    temp->connectNext(inventory);
    if(inventory)
        inventory->connectPrevious(temp);
    inventory = temp;
}

//Display Score
void player::displayScore()
{
    cout << "\nScore: " << score << endl;
}

//Getter for returning the index of player's location
int player::getLocation()
{
    return location;
}

//Wrapper fucntion for displayInventory
void player::displayInventory()
{
    displayInventory(inventory);
}

//Display all items in DLL
void player::displayInventory(item*&head)
{
    if(!head) return;

    head->display();
    displayInventory(head->goNext());
}

//Sets player's location
void player::setLocation(int i)
{
    location = i;
}

//Remove item wrapper function
void player::removeItem(char * name)
{
    removeItem(inventory, name);
}

//Removes item
void player::removeItem(item*& head, char * name)
{
    if(!head) return;

    if(head->compare(name))
    {
        item * empty = NULL;
        item * temp = head;
        head = head->goNext();
        head->connectPrevious(empty);

        delete temp;
    }
    removeItem(head->goNext(),name);
}

void player::display() const
{
    cout << "\nName:  " << data;
}
//****************************************************************//



//pNode
//****************************************************************//
//pNode default constructor
pNode::pNode()
{
    list = new info*[MAXLIST];
    next = NULL;

    for(int i = 0; i < MAXLIST; ++i)
        list[i] = NULL;
}

//pNode destructor
pNode::~pNode()
{
    for(int i = 0; list[i]; ++i)
        delete list[i];
    if(list)
    {
        delete [] list;
        list = NULL;
    }

    if(next) delete next;
}

//Point to a player class
void pNode::add(int i)
{
    list[i] = new player();
}

void pNode::remove(int i)
{
    if(list[i])
    {
        delete list[i];
        list[i] = NULL;
    }
}

//Return the next pNode
pNode*& pNode::goNext()
{
    return next;
}

//Connect next to next pNode in list
void pNode::connectNext(pNode* connect)
{
    next = connect;
}

//Displays all players in the list
void pNode::display()
{
    for(int i = 0; list[i]; ++i)
        list[i]->display();
}

//Returns player pointed by info
player* pNode::getPlayer(int i)
{
    player * ptr = dynamic_cast<player*>(list[i]);
    return ptr;
}
//****************************************************************//



//Roster
//****************************************************************//
//Roster default constructor
roster::roster()
{
    head = NULL;
    tail = NULL;
    currentPlayer = NULL;
    id = 0;
    numPlayer = 0;
}

//Roster destructor
roster::~roster()
{
    if(head)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
}

//Add player to roster
void roster::add()
{
    int i = numPlayer%MAXLIST;

    if(!i)
    {
        pNode * temp = new pNode;

        if(!head)
        {
            head = temp;
            tail = temp;
            tail->add(i);
            setCurrentPlayer(i);
        }
        else
        {
            tail->connectNext(temp);
            tail = tail->goNext();
            tail->add(i);
        }
    }
    else tail->add(i);
    ++numPlayer;
}

//Removes player according to id
void roster::remove(int num)
{
    pNode * current = head;

    if(num > MAXLIST)
    {
        for(int i = 0; i < num/MAXLIST; ++i)
            current = current->goNext();
    }
    current->remove(num%MAXLIST);
}

//Change current player
void roster::setCurrentPlayer(int setCP)
{
    id = setCP;
    pNode * current = head;

    if(id > MAXLIST)
    {
        for(int i = 0; i < id/MAXLIST; ++i)
            current = current->goNext();
    }
    currentPlayer = current->getPlayer(id%MAXLIST);
}

//Displays all players in roster
void roster::displayAll()
{
    pNode * current = head;
    for(current;current;current = current->goNext())
        current->display();
}

//Display current player's id
void roster::displayId()
{
    cout << " " << id;
}

//Display all player's id
void roster::displayAllId()
{
    for(int i = 0; i < numPlayer; ++i)
        cout << i << "  ";
}

//Return number of players in roster
int roster::getNumPlayer()
{
    return numPlayer;
}

//Add to player score
void roster::addScore(int add)
{
    currentPlayer->addScore(add);
}

//Insert item into DLL
void roster::addItem(info& object)
{
   currentPlayer->addItem(object);
}

//Display Score
void roster::displayScore()
{
    currentPlayer->displayScore();
}

//Getter for returning the index of player's location
int roster::getLocation()
{
    currentPlayer->getLocation();
}

//Wrapper fucntion for displayInventory
void roster::displayInventory()
{
    currentPlayer->displayInventory();
}

//Sets player's location
void roster::setLocation(int i)
{
    currentPlayer->setLocation(i);
}

//Remove item wrapper function
void roster::removeItem(char * name)
{
    currentPlayer->removeItem(name);
}

//Wrapper function for player's display
void roster::display() const
{
    currentPlayer->display();
}
//****************************************************************//

