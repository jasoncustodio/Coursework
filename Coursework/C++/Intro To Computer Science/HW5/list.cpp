#include "list.h"
//Implement the following functions

list::list()
{
    head = NULL;
}

list::~list()
{
    delete head;
    head = NULL;
}

node::~node()
{
    delete [] data;
    delete next;
    next = NULL;
}

void list::add()
{
    node * current;
    node * temp;
    char name [SIZE];

    temp = new node;
    temp->next = NULL;

    cout << "Input name of place: ";
    cin.get(name, SIZE, '\n');
    cin.ignore(SIZE, '\n');

    if(!head)
    {
        head = temp;

        temp->data = new char[strlen(name)+1];
        strcpy(temp->data, name);
    }

    else
    {
        for(current=head;current->next;current=current->next){}
            current->next = temp;

        temp->data = new char[strlen(name)+1];
        strcpy(temp->data, name);
    }
}

void list::display()
{
    node * current;

    int i = 1;

    for(current=head;current;current=current->next, ++i)
    {
        cout << "(" << i << ") "
             << current->data << endl << endl;
    }
    check();
}

int list::count()
{
	node * current;
	int count = 0;

	if(head)
	{
		for(current=head;current;current=current->next)
			count++;
	}
	return count;
}

void list::move()
{
    node * current;

    if(!head)
        return;
    else
    {
        cout << "(*) " << head->data << endl;
        for(current=head;current->next;current=current->next){}

        current->next = head;
        head          = head->next;
        current       = current->next;
        current->next = NULL;
    }
    check();
}

//Welcomes user and explains rules
void list::welcome()
{
    space(100);
    cout << "**** PORTLAND SIGHT SEEING **** " << endl
         << "------------------------------- " << endl
         << "* Add places to see.           |" << endl
         << "* Display first place.         |" << endl
         << "* Display all places.          |" << endl
         << "* Have fun!                    |" << endl
         << "------------------------------- " << endl
         << endl;
    check();
    space(100);
}

//Displays User Interface with multiple commands using a switch statement
int list::interface()
{
    int choice = 0;

    cout << "** PORTLAND PLACES **" << endl << endl
         << "---------------------" << endl
         << "(1) Add             |" << endl
         << "                    |" << endl
         << "(2) Show First      |" << endl
         << "                    |" << endl
         << "(3) Display All     |" << endl
         << "                    |" << endl
         << "(4) Exit            |" << endl
         << "---------------------" << endl;

    cout << "\n\nInput number to choose option: ";
    cin  >> choice;
    cin.ignore();
    return choice;
}

//Pause checkpoint function
void list::check()
{
    char check;

    do
    {
        cout << "\nEnter any key to continue: ";
        cin  >> check;
        cin.ignore();
    }while (isblank(check) == 1);
}

//Creates numerous new lines
void list::space(int num)
{
    for (int i = 0; i < num; i++)
        cout << endl;
}







