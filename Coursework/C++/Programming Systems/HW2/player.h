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

//Holds any kind of data
class info
{
    public:
            info();                          //Default constructor
            info(char*);                     //Info constructor
            info(const info&);               //Copy constructor
            virtual ~info();                 //Destructor

            void setInfo(char*);             //Sets data
            virtual void display() const;    //Display data, virtual to practice dynamic binding
            void copyInfo(const info&);      //Copy data from another info
            bool compare(const char*) const; //Compare to see if the data is the same

    protected:
            char * data; //Holds any kind of data (In this case, names, location, etc)
};

//Item that is put into inventory
class item: public info
{
    public:
            item();                      //Default constructor
            item(const info&);           //Copy constructor
            ~item();                     //Destructor

            void display() const;        //Displays item's name using dynamic binding
            item*& goNext();             //Return the next node in the DLL
            item*& goPrevious();         //Return the previous node in the DLL
            void connectNext(item*);     //Connect item to next item
            void connectPrevious(item*); //Connect item to previous item

    private:
            item * next;     //Item pointer to the next pointer in the inventory
            item * previous; //Item pointer to the next pointer in the inventory
};

//Player that plays the game, holds name, score, inventory, and location index of map
class player: public info
{
    public:
            player(); //Default constructor
            ~player();//Destructor

            void display() const;    //Displays player's name using dynamic binding
            int  getLocation();      //Return location
            void addScore(int);      //Add item to the inventory
            void addItem(info&);     //Add to the score
            void displayScore();     //Display player score
            void setLocation(int);   //Sets player's location
            void removeItem(char*);  //Remove item wrapper function
            void displayLocation();  //Display location
            void displayInventory(); //Display Inventory wrapper function

    private:
            int score;                     //Player's score, increments by 100
            int location;                  //Player's location index
            item * inventory;              //Head DLL pointer to list of items
            void displayInventory(item*&); //Displays all items in the inventory
            void removeItem(item*&,char*); //Removes item
};

//Used to practice dynamic binding, base class pointer (info) will point to a player object
class pNode
{
    public:
             pNode(); //pNode default constructor
            ~pNode(); //Destructor

            void add(int);            //Adds a player to the list
            void remove(int);         //Removes a player according to id
            void display();           //Displays all players in list
            player* getPlayer(int);   //Dynamic cast from info to player
            pNode*& goNext();         //Returns the next pNode in the LLL
            void connectNext(pNode*); //Connects pNode's next to another pNode

    private:
            info ** list;  //Base class pointer to point to derived player
            pNode * next; //Points to next dynamic array of players
};

//Linear Linked List of Arrays, holds pNodes to act as a player roster
class roster
{
    public:
            roster();  //Default constructor
            ~roster(); //Destructor

            void add();                 //Adds a player
            void remove(int);           //Removes a player according to id
            void displayId();           //Display id of current player
            void displayAll();          //Display all players in the roster
            void displayAllId();        //Display all Id
            int  getNumPlayer();        //Return number of players
            void setCurrentPlayer(int); //Changes current player

            void display() const;       //Wrapper Displays player's name
            int  getLocation();         //Wrapper return location
            void addScore(int);         //Wrapper add item to the inventory
            void addItem(info&);        //Wrapper add to the score
            void displayScore();        //Wrapper display player score
            void setLocation(int);      //Wrapper sets player's location
            void removeItem(char*);     //Wrapper remove item wrapper function
            void displayLocation();     //Wrapper display location
            void displayInventory();    //Wrapper display Inventory wrapper function

    private:
            pNode * head;           //Holds a list of info base pointers
            pNode * tail;           //Holds end of list
            player * currentPlayer; //Current player playing
            int id;                 //Current id of player playing
            int numPlayer;          //Number of players
};
