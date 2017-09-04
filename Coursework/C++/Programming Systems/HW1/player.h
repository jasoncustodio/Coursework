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

//Holds any kind of data
class info
{
      public:
             info();                          //Default constructor
             info(char*);                     //Info constructor
             info(const info&);               //Copy constructor
             ~info();                         //Destructor

             void setInfo(char*);             //Sets data
             void display() const;            //Display data
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
