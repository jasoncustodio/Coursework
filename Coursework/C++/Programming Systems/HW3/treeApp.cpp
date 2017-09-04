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

//Message
//****************************************************************//
//Default constructor
message::message():timeSent(0){}

//Message constructor
message::message(char * temp,int i):body(temp),timeSent(i){}

//Copy constructor
message::message(const message& temp)
{
    timeSent = temp.timeSent;
    body     = temp.body;
}

//Destructor
message::~message(){}

//Sets data
void message::setBody(char * temp)
{
    body.setInfo(temp);
}

//Return time sent
int message::getTimeSent()
{
    return timeSent;
}

//Display data, virtual to practice dynamic binding
void message::display() const
{
    cout << "Time: " << timeSent << endl
         << "Body: " << body     << endl;
}

//Copy data from another info
void message::copyMessage(const message& temp)
{
    timeSent = temp.timeSent;
    body = temp.body;
}

//Compare to see if the data is the same
//bool compare(const char*) const
//****************************************************************//



//Text
//****************************************************************//
//Default constructor
text::text(){}

//Text constructor
text::text(char * p,char * b, int i):phone(p),message(b,i){}

//Copy constructor
text::text(const text& temp)
{
    phone    = temp.phone;
    timeSent = temp.timeSent;
    body     = temp.body;
}

//Destructor
text::~text(){}

//Sets phone number
void text::setPhone(char * temp)
{
    phone.setInfo(temp);
}

//Display data, virtual to practice dynamic binding
void text::display() const
{
    cout << "Phone: "<< phone    << endl
         << "Time: " << timeSent << endl
         << "Body: " << body     << endl;
}

//Copy data from another info
void text::copyText(const text& temp)
{
    phone    = temp.phone;
    timeSent = temp.timeSent;
    body     = temp.body;
}

void text::setText(char * p, char * b, int t)
{
    phone.setInfo(p);
    body.setInfo(b);
    timeSent = t;
}

//Compare to see if the phone number is the same
//bool compare(const char*) const;
//****************************************************************//



//Facebook
//****************************************************************//
//Default constructor
facebook::facebook(){}

//Facebook constructor
facebook::facebook(char * u, char * b, int i):username(u),message(b,i){}

//Copy constructor
facebook::facebook(const facebook& temp)
{
    username = temp.username;
    timeSent = temp.timeSent;
    body     = temp.body;
}

 //Destructor
facebook::~facebook(){}

//Sets username
void facebook::setUsername(char * temp)
{
    username.setInfo(temp);
}

//Display data, virtual to practice dynamic binding
void facebook::display() const
{
    cout << "Username: " << username << endl
         << "Time: "     << timeSent << endl
         << "Body: "     << body     << endl;
}

//Copy data from another info
void facebook::copyFacebook(const facebook& temp)
{
    username = temp.username;
    timeSent = temp.timeSent;
    body     = temp.body;
}

void facebook::setFacebook(char * u, char * b, int t)
{
    username.setInfo(u);
    body.setInfo(b);
    timeSent = t;
}
//Compare to see if the username is the same
//bool compare(const char*) const;
//****************************************************************//



//Email
//****************************************************************//
//Default constructor
email::email(){}

//Email constructor
email::email(char * a,char * b, int i):address(a),message(b,i){}

//Copy constructor
email::email(const email& temp)
{
    address  = temp.address;
    timeSent = temp.timeSent;
    body     = temp.body;
}

//Destructor
email::~email(){}

//Sets email address
void email::setAddress(char * temp)
{
    address.setInfo(temp);
}

//Display data, virtual to practice dynamic binding
void email::display() const
{
    cout << "Email Address: " << address  << endl
         << "Time: "          << timeSent << endl
         << "Body: "          << body     << endl;
}

//Copy data from another info
void email::copyEmail(const email& temp)
{
    address  = temp.address;
    timeSent = temp.timeSent;
    body     = temp.body;
}

void email::setEmail(char * a, char * b, int t)
{
    address.setInfo(a);
    body.setInfo(b);
    timeSent = t;
}
//Compare to see if the address is the same
//bool compare(const char*) const;
//****************************************************************//



//TreeNode
//****************************************************************//
//Default constructor
treeNode::treeNode():data(0),left(0),right(0){}

//Destructor
treeNode::~treeNode()
{
    if(data)
    {
        delete data;
        data = NULL;
    }
}

//Displays all data in node
void treeNode::display() const
{
    data->display();
}

//Return the left child
treeNode*& treeNode::goLeft()
{
    return left;
}

//Return the right child
treeNode*& treeNode::goRight()
{
    return right;
}

//Connect left child
void treeNode::connectLeft(treeNode * temp)
{
    left = temp;
}

//Connect right child
void treeNode::connectRight(treeNode * temp)
{
    right = temp;
}

//Return time sent
int treeNode::getTimeSent()
{
    data->getTimeSent();
}

//Dynamic cast
void treeNode::castMessage(const message& add)
{
    const text * tPtr = dynamic_cast<const text*>(&add);
    if(tPtr)
    {
        data = new text(*tPtr);
        return;
    }

    const facebook * fPtr = dynamic_cast<const facebook*>(&add);
    if(fPtr)
    {
        data = new facebook(*fPtr);
        return;
    }

    const email * ePtr = dynamic_cast<const email*>(&add);
    if(ePtr)
    {
        data = new email(*ePtr);
        return;
    }
}
//****************************************************************//



//TreeApp
//****************************************************************//
//Default constructor
treeApp::treeApp():root(0){}

//Destructor
treeApp::~treeApp()
{
    remove(root);
}

//Display All in BST
void treeApp::display()
{
    display(root);
}

//Add message to the tree
void treeApp::insert(int key, const message& addMessage)
{
    insert(root, key, addMessage);
}

int treeApp::count()
{
    count(root);
}

int treeApp::leftHeight()
{
    count(root->goLeft());
}

int treeApp::rightHeight()
{
     count(root->goRight());
}

void treeApp::remove(treeNode*& root)
{
    if(!root) return;

    remove(root->goLeft());
    remove(root->goRight());

    delete root;
    root = NULL;
}

void treeApp::display(treeNode*& root)
{
    if(!root) return;

    display(root->goLeft());
    root->display();
    cout << endl;
    display(root->goRight());
}

//Insert into binary search tree already in sorted order
void treeApp::insert( treeNode*& root, int key, const message& add)
{
    if(!root)
    {
        root = new treeNode();
        root->castMessage(add);
        return;
    }

    if(root->getTimeSent() > key)
        insert(root->goLeft(), key, add);
    else
        insert(root->goRight(), key, add);
}

//Load mail from text file
void treeApp::load(char * treeText)
{
    ifstream inFile;

    int  tag = 0;
    int  timeSent = 0;
    char extra [SIZE];
    char body  [SIZE];
    text myText;
    facebook myFacebook;
    email myEmail;

    inFile.open(treeText);
    if(inFile)
    {
        inFile.ignore(SIZE, ' ');
        inFile >> tag;
        inFile.ignore(SIZE, '\n');

        while(inFile && !inFile.eof())
        {
            inFile.ignore(SIZE, ' ');
            inFile.get(extra, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile.get(body, SIZE, '~');
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ' ');
            inFile >> timeSent;
            inFile.ignore(SIZE, '\n');

            if(tag == TEXTID)
            {
                myText.setText(extra,body,timeSent);
                insert(timeSent,myText);
            }

            else if(tag == FACEBOOKID)
            {
                myFacebook.setFacebook(extra,body,timeSent);
                insert(timeSent,myFacebook);
            }

            else if(tag == EMAILID)
            {
                myEmail.setEmail(extra,body,timeSent);
                insert(timeSent,myEmail);
            }

            inFile.ignore(SIZE, ' ');
            inFile >> tag;
            inFile.ignore(SIZE, '\n');
        }
    }
    inFile.close();
}

int treeApp::count(treeNode*& root)
{
    if(!root) return 0;
    return (count(root->goLeft()) + count(root->goRight()) + 1);
}

//****************************************************************//





