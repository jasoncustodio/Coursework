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

#include "contactList.h"

//Message to be sent with a body and time sent
class message
{
    public:
            message();                        //Default constructor
            message(char*,int);               //Info constructor
            message(const message&);          //Copy constructor
            virtual ~message();               //Destructor

            void setBody(char*);              //Sets data
            int  getTimeSent();               //Return timeSent
            virtual void display() const;     //Display data, virtual to practice dynamic binding
            void copyMessage(const message&); //Copy data from another info
          //bool compare(const char*) const;  //Compare to see if the data is the same

    protected:
            int timeSent;                     //Military time when message was sent to be used to sort
            info body;                        //The body of the message
};

//Text from phone
class text: public message
{
    public:
            text();                          //Default constructor
            text(char*,char*,int);           //Text constructor
            text(const text&);               //Copy constructor
            ~text();                         //Destructor

            void setText(char*,char*,int);   //Set members of text
            void setPhone(char*);            //Sets phone number
            void display() const;            //Display data, virtual to practice dynamic binding
            void copyText(const text&);      //Copy data from another info
            bool compare(const char*) const; //Compare to see if the phone number is the same

    private:
            info phone;                      //Phone number of sender
};

//Message through facebook
class facebook: public message
{
    public:
            facebook();                         //Default constructor
            facebook(char*,char*,int);          //Facebook constructor
            facebook(const facebook&);          //Copy constructor
            ~facebook();                        //Destructor

            void setFacebook(char*,char*,int);  //Sets members of facebook
            void setUsername(char*);            //Sets phone number
            void display() const;               //Display data, virtual to practice dynamic binding
            void copyFacebook(const facebook&); //Copy data from another info
            bool compare(const char*) const;    //Compare to see if the username is the same

    private:
            info username;                      //Username of sender
};

//Send message through email
class email: public message
{
    public:
            email();                         //Default constructor
            email(char*,char*,int);          //Email constructor
            email(const email&);             //Copy constructor
            ~email();                        //Destructor

            void setEmail(char*,char*,int);  //Sets members of email
            void setAddress(char*);          //Sets phone number
            void display() const;            //Display data, virtual to practice dynamic binding
            void copyEmail(const email&);    //Copy data from another info
            bool compare(const char*) const; //Compare to see if the address is the same

    private:
            info address;                    //Phone number of sender
};

//Holds a messaage and two pointer to left/right child
class treeNode
{
    public:
            treeNode();  //Default constructor
            ~treeNode(); //Destructor

            void display() const;             //Displays item's name using dynamic binding
            treeNode*& goLeft();              //Return the next node in the DLL
            treeNode*& goRight();             //Return the previous node in the DLL
            void connectLeft(treeNode*);      //Connect item to next item
            void connectRight(treeNode*);     //Connect item to previous item
            void castMessage(const message&); //Dynamic cast message
            int getTimeSent();

    private:
            message  * data;  //Message in node to point to any kind of message
            treeNode * left;  //Item pointer to the next pointer in the inventory
            treeNode * right; //Item pointer to the next pointer in the inventory
};

//Holds all messages
class treeApp
{
    public:
            treeApp();  //Default constructor
            ~treeApp(); //Destructor

            void display();                  //Display All in BST
            void insert(int,const message&); //Add message to the tree
            void load(char*);                //Load messages from txt file
            int count();                     //Checks height
            int leftHeight();                //Checks height on the left of tree
            int rightHeight();               //Checks heigh on the right of tree

    private:
            treeNode * root;                            //Root of BST
            void insert(treeNode*&,int,const message&); //Insert message into BST
            void remove(treeNode*&);                    //Used for destructor
            void display(treeNode*&);                   //Display All
            int count(treeNode*&);                      //Checks height
};

