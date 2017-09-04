/*
    Program:     Text Application
    Author:      Jason Custodio
    Class:       CS202
    Date:        05/20/2014
    Description: This program simulates a text application
                 Info class acts as a string class
                 A message has an info and timeSent
                 A text is a message
                 A facebook is a message
                 An email is a message
                 Messages are stored in tree nodes
                 Tree nodes make up the tree BST app
                 Class account holds 5 strings
                 A person is an account
                 A contact node holds a person
                 The contact List is made up of LLL
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
#include <cstdlib>

const int TEXTID     = 1;   //ID for text
const int FACEBOOKID = 2;   //ID for facebook
const int EMAILID    = 3;   //ID for email
const int EXIT       = 3;   //When to exit
const int SIZE       = 100; //Size for array

using namespace std;

//A info class that holds data
class info
{
    public:
            info();                                              //Default constructor
            info(char*);                                         //Info constructor
            info(const info&);                                   //Copy constructor
            ~info();                                             //Destructor

            void setInfo(char*);                                 //Sets data
            void display() const;                                //Display data, virtual to practice dynamic binding
            void copyInfo(const info&);                          //Copy data from another info
            bool compare(const char*) const;                     //Compare to see if the data is the same

            friend ostream& operator << (ostream&, const info&); //Operator overloading <<
            bool operator == (const info&) const;                //Operator overloading ==
            info& operator = (const info&);                      //Operator overloading =

    protected:
            char * data; //Holds any kind of data (In this case:names, usernames, phone number)
};

//Holds information of a person
class account
{
    public:
            account();                   //Default Constructor
            account(int,char*,char*,char*,char*); //Constructor setting all members of account
            account(const account&);     //Copy Constructor
            ~account();                  //Destructor
            void copy(const account&);   //Copies the info of another account

            int  getTag();               //Return tag
            void display();              //Displays all info
            void displayName();          //Return index
            void displayPhone();         //Return answer
            void displayUsername();      //Compare user answer, 0 is false, 1 is true
            void displayAddress();       //Connect node to next node

            bool compareTag(int);        //Compares tag with arguemnt, returns true is same
            bool compareName(char*);     //Compares name with arguement, returns true if same
            bool comparePhone(char*);    //Compares phone with arguement, return true if same
            bool compareUsername(char*); //Compares username with arguement, returns true if same
            bool compareAddress(char*);  //Compares Address with arguement, returns true is same

            void set(int,char*,char*,char*,char*); //Sets all data members

    private:
            int  tag;                    //Preferred message
            info name;                   //Name of person
            info phone;                  //Phone number
            info username;               //Facebook username
            info address;                //Email address
};

//A person that is in the contact list, has an account and a treeApp
class person: public account
{
    public:
            person();                            //Default Constructor
            person(int,char*,char*,char*,char*); //Constructor
            person(const person&);               //Copy Constructor
	        ~person();                           //Destructor
};

//Node to to manage contacts in a LLL
class contactNode
{
    public:
            contactNode();                     //Default Constructor
            contactNode(const person&, contactNode*); //Constructor
            contactNode(const contactNode&);   //Copy Constructor
            ~contactNode();                    //Destructor

            void display();                    //Display account of person
            contactNode*& goNext();            //Return the next node
            void connectNext(contactNode*);    //Connect node to next node
            bool compareName(char*);

    private:
            person data;                       //Person in the contact node that holds an account
            contactNode * next;                //Pointer to next node

};

//LLL on contactNodes
class contactList
{
    public:
            contactList();      //Default Constructor
            ~contactList();     //Destructor

            void add(person&);  //Add a contact node to LLL
            void remove(char*); //Remove a contact node from LLL
            void display();     //Display all contacts in LLL
            void load(char*);   //Load contacts from a text file

    private:
            contactNode * head;
            void remove(char*,contactNode*&);
};
