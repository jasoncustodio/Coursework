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

#include "menu.h"

//info
//****************************************************************//
//Default constructor
info::info():data(0){}

//info constructor
info::info(char * copy)
{
    data = new char[strlen(copy)+1];
    strcpy(data, copy);
}

//Copy constructor
info::info(const info& copy)
{
    data = new char[strlen(copy.data)+1];
    strcpy(data, copy.data);
}

//Destructor
info::~info()
{
    if(data)
    {
        delete [] data;
        data = NULL;
    }
}

//Sets data
void info::setInfo(char * copy)
{
    if(data) delete [] data;
    data = new char[strlen(copy)+1];
    strcpy(data, copy);
}

//Display data
void info::display() const
{
    cout << data << endl;
}

//Copy info from another info
void info::copyInfo(const info& copy)
{
    if(data) delete [] data;
    data = new char[strlen(copy.data)+1];
    strcpy(data, copy.data);
}

//Compare to see if the data is the same
bool info::compare(const char * temp) const
{
    if(!strcmp(data, temp)) return 1;
    return 0;
}

//Operator overloading <<
ostream& operator << (ostream& out, const info& temp)
{
    out << temp.data;
    return out;
}

//Operator overloading ==
bool info::operator == (const info& temp) const
{
    if(!strcmp(data,temp.data)) return true;
    else return false;
}

//Operator overloading =
info& info::operator = (const info& temp)
{
    if(!(this == &temp)) copyInfo(temp);
    return *this;
}
//****************************************************************//



//Account
//****************************************************************//
//Default Constructor
account::account():tag(0){}

//Constructor setting all members of account
account::account(int t, char*n,char*p,char*u,char*a):tag(t),name(n),phone(p),username(u),address(a){}

 //Copy Constructor
account::account(const account& temp)
{
    copy(temp);
}

//Destructor
account::~account(){}

void account::copy(const account& temp)
{
    tag = temp.tag;

    name     = temp.name;
    phone    = temp.phone;
    username = temp.username;
    address  = temp.address;
}

//Return tag
int  account::getTag()
{
    return tag;
}

//Displays all info
void account::display()
{
    cout << name     << endl;
    cout << phone    << endl;
    cout << username << endl;
    cout << address  << endl;
}

//Display name
void account::displayName()
{
    cout << name;
}

//Display phone number
void account::displayPhone()
{
    cout << phone;
}

//Display username
void account::displayUsername()
{
    cout << username;
}

//Display address
void account::displayAddress()
{
    cout << address;
}

//Compares tag with arguemnt, returns true is same
bool account::compareTag(int temp)
{
    if(tag == temp) return true;
    else return false;
}

//Compares name with arguement, returns true if same
bool account::compareName(char * temp)
{
    return name.compare(temp);
}

//Compares phone with arguement, return true if same
bool account::comparePhone(char * temp)
{
    return phone.compare(temp);
}

//Compares username with arguement, returns true if same
bool account::compareUsername(char * temp)
{
    return username.compare(temp);
}

//Compares Address with arguement, returns true is same
bool account::compareAddress(char * temp)
{
    return address.compare(temp);
}

//Sets tag to argument
void account::set(int t, char * n, char * p, char * u, char * a)
{
    tag = t;
    name.setInfo(n);
    phone.setInfo(p);
    username.setInfo(u);
    address.setInfo(a);
}

//****************************************************************//



//Person
//****************************************************************//
//Default Constructor
person::person(){}

//Constructor
person::person(int t,char * n, char * p,char * u, char * a):account(t,n,p,u,a){}

//Copy Constructor
person::person(const person& temp)
{
    copy(temp);
}

//Destructor
person::~person(){}
//****************************************************************//



//ContactNode
//****************************************************************//
//Default Constructor
contactNode::contactNode():next(0){}

 //Constructor
contactNode::contactNode(const person& tempPerson, contactNode * tempContactNode)
{
    data.copy(tempPerson);
    connectNext(tempContactNode);
}

//Copy Constructor
contactNode::contactNode(const contactNode& temp)
{
    data.copy(temp.data);
}

//Destructor
contactNode::~contactNode()
{
    if(next) delete next;
}

//Display person's info
void contactNode::display()
{
    data.display();
}

//Return the next node
contactNode*& contactNode::goNext()
{
    return next;
}

//Connect node to next node
void contactNode::connectNext(contactNode * temp)
{
    next = temp;
}

bool contactNode::compareName(char * temp)
{
    return data.compareName(temp);
}
//****************************************************************//



//ContactList
//****************************************************************//
contactList::contactList():head(0){}

//Destructor
contactList::~contactList()
{
    if(head)
    {
        delete head;
        head = NULL;
    }
}

//Add a contact node to LLL
void contactList::add(person& addPerson)
{
    contactNode * temp = new contactNode(addPerson,head);
    head = temp;
}

//Removes contact node from LLL
void contactList::remove(char * name)
{
    remove(name,head);
}

//Removes contact node from LLL
void contactList::remove(char * name, contactNode*& head)
{
    if(!head) return;
    if(head->compareName(name))
    {
        contactNode * temp = head;
        head = head->goNext();
        delete temp;
    }
    remove(name,head->goNext());
}

//Display all contacts in LLL
void contactList::display()
{
    for(contactNode * temp = head; temp; temp=temp->goNext())
    {
        temp->display();
        cout << endl;
    }
}

//Load contacts from text file
void contactList::load(char * contactText)
{
    ifstream inFile;

    int  tag = 0;
    char name     [SIZE];
    char phone    [SIZE];
    char username [SIZE];
    char address  [SIZE];
    person myPerson;

    inFile.open(contactText);
    if(inFile)
    {
        inFile.ignore(SIZE, ' ');
        inFile >> tag;
        inFile.ignore(SIZE, '\n');

        while(inFile && !inFile.eof())
        {
            inFile.ignore(SIZE, ' ');
            inFile.get(name, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(phone, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(username, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(address, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            myPerson.set(tag,name,phone,username,address);
            add(myPerson);

            inFile.ignore(SIZE, ' ');
            inFile >> tag;
            inFile.ignore(SIZE, '\n');
        }
    }
    inFile.close();
}
//****************************************************************//
