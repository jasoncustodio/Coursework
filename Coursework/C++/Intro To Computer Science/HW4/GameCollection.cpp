#include "GameCollection.h"

//Constructor
GameCollection::GameCollection()
{
    newGame  = NULL;
    usedGame = NULL;
    saleGame = NULL;

    numNew  = 0;
    numUsed = 0;
    numSale = 0;
}

//Destructor
GameCollection::~GameCollection()
{
    delete [] newGame;
    newGame = NULL;

    delete [] usedGame;
    usedGame  = NULL;

    delete [] saleGame;
    saleGame  = NULL;
}

//Sets newGame array size
void GameCollection::setNew(int size)
{
    newGame = new game[size*2];
    space(2);
}

//Sets usedGame array size
void GameCollection::setUsed(int size)
{
    usedGame = new game[size*2];
    space(2);
}

//Sets saleGame array size
void GameCollection::setSale(int size)
{
    saleGame = new game[size*2];
    space(2);
}

//Display all games from all three types
void GameCollection::displayAll()
{
    display(newGame,  numNew);
    display(usedGame, numUsed);
    display(saleGame, numSale);
    check();
}

//Support function for displaying all games
void GameCollection::display(game gameArray[], int gameNum)
{
    if( gameNum > 0)
    {
        for(int i = 0; i < gameNum; ++i)
        {
            cout << "(*) Name:      " << gameArray[i].name     << endl
                 << "    Email:     " << gameArray[i].email    << endl
                 << "    Rating:    " << gameArray[i].rating   << endl
                 << "    Summary:   " << gameArray[i].summary  << endl
                 << "    Platform:  " << gameArray[i].platform << endl
                 << "    Comments:  " << gameArray[i].comments << endl;

            if(gameArray[i].type == 1)
                cout << "    Type:      New\n         " << endl;
            else if(gameArray[i].type == 2)
                cout << "    Type:      Used\n        " << endl;
            else if(gameArray[i].type == 3)
                cout << "    Type:      For Sale\n    " << endl;
        }
    }
}

//Add a game to the collection
void GameCollection::addGame()
{
    int type = 0;

    cout << "(1) New\n"
         << "(2) Used\n"
         << "(3) For Sale\n\n"
         << "Input type of game to add: ";
    cin >> type;
    cin.ignore();

    space(100);

    if(type == 1)
    {
        newGame[numNew].type = 1;
        add(newGame, numNew);
    }
    else if(type == 2)
    {
        usedGame[numUsed].type = 2;
        add(usedGame, numUsed);
    }
    else if(type == 3)
    {
        saleGame[numSale].type = 3;
        add(saleGame, numSale);
    }
}

//Support function to add game to collection
void GameCollection::add(game gameArray[], int& gameNum)
{
    cout << "Input name:     ";
    cin.get(gameArray[gameNum].name,     SIZE, '\n');
    gameArray[gameNum].name[0] = toupper(gameArray[gameNum].name[0]);
    cin.ignore(100, '\n');

    cout << "Input email:    ";
    cin.get(gameArray[gameNum].email,    SIZE, '\n');
    cin.ignore(100, '\n');

    cout << "Input rating:   ";
    cin.get(gameArray[gameNum].rating,   SIZE, '\n');
    cin.ignore(100, '\n');

    cout << "Input summary:  ";
    cin.get(gameArray[gameNum].summary,  SIZE, '\n');
    cin.ignore(100, '\n');

    cout << "Input platform: ";
    cin.get(gameArray[gameNum].platform, SIZE, '\n');
    cin.ignore(100, '\n');

    cout << "Input comments: ";
    cin.get(gameArray[gameNum].comments, SIZE, '\n');
    cin.ignore(100, '\n');

    ++gameNum;
}

//Add comments for a game
void GameCollection::comment()
{
    char name[SIZE];

    displayName(newGame,  numNew);
    displayName(usedGame, numUsed);
    displayName(saleGame, numSale);

    cout <<"Input name of game to add comments: ";
    cin.get(name, SIZE, '\n');
    cin.ignore(100, '\n');

     if(!findComment(newGame,  numNew,  name)&&
      !findComment(usedGame, numUsed, name)&&
      !findComment(saleGame, numSale, name))
        cout << name << " is not in the collection.\n";

    check();
}

//Support function for displaying all games
void GameCollection::displayName(game gameArray[], int gameNum)
{
    if( gameNum > 0)
    {
        for(int i = 0; i < gameNum; ++i)
        {
            cout << "(*) Name: " << gameArray[i].name;
            space(2);
        }
    }
}

//Support function for finding game function
bool GameCollection::findComment(game gameArray[], int gameNum, char match[])
{
    space(100);
    match[0] = toupper(match[0]);
    char change[SIZE];

    for(int i = 0; i < gameNum; ++i)
    {
        if(strcmp(gameArray[i].name, match) == 0)
        {
            cout << "Input comments for " << match << ": ";
            cin.get(change, SIZE, '\n');
            cin.ignore(100, '\n');
            strcpy(gameArray[i].comments, change);
            return true;
        }
    }
    return false;
}

//Find game, if found, return game info
void GameCollection::findGame()
{
    char name[SIZE];

    cout << "Input name of game to find: ";
    cin.get(name, SIZE, '\n');
    cin.ignore(100, '\n');
    space(100);

   if(!find(newGame,  numNew,  name)&&
      !find(usedGame, numUsed, name)&&
      !find(saleGame, numSale, name))
        cout << name << " is not in the collection.\n";

    check();
}

//Support function for finding game function
bool GameCollection::find(game gameArray[], int gameNum, char match[])
{
    match[0] = toupper(match[0]);

    for(int i = 0; i < gameNum; ++i)
    {
        if(strcmp(gameArray[i].name, match) == 0)
        {
            cout << "(*) Name:      " << gameArray[i].name     << endl
                 << "    Email:     " << gameArray[i].email    << endl
                 << "    Rating:    " << gameArray[i].rating   << endl
                 << "    Summary:   " << gameArray[i].summary  << endl
                 << "    Platform:  " << gameArray[i].platform << endl
                 << "    Comments:  " << gameArray[i].comments << endl;

            if(gameArray[i].type == 1)
                cout << "    Type:      New\n         " << endl;
            else if(gameArray[i].type == 2)
                cout << "    Type:      Used\n        " << endl;
            else if(gameArray[i].type == 3)
                cout << "    Type:      For Sale\n    " << endl;
            return true;
        }
    }
    return false;
}

//Welcomes user and explains rules
void GameCollection::welcome()
{
    space(100);
    cout << "******* GAME COLLECTION ******* " << endl
         << "------------------------------- " << endl
         << "* Add games to collection.     |" << endl
         << "* Find a game.                 |" << endl
         << "* Display all games.           |" << endl
         << "* Add comments to a game.      |" << endl
         << "* Have fun!                    |" << endl
         << "------------------------------- " << endl
         << endl;
    check();
    space(100);
}

//Displays User Interface with multiple commands using a switch statement
int GameCollection::interface()
{
    int choice = 0;

    cout << "** GAME COLLECTION **" << endl << endl
         << "---------------------" << endl
         << "(1) Add             |" << endl
         << "                    |" << endl
         << "(2) Find            |" << endl
         << "                    |" << endl
         << "(3) Display         |" << endl
         << "                    |" << endl
         << "(4) Add Comments    |" << endl
         << "                    |" << endl
         << "(5) Exit            |" << endl
         << "---------------------" << endl;

    cout << "\n\nInput number to choose option: ";
    cin  >> choice;
    cin.ignore();
    return choice;
}

//Pause checkpoint function
void GameCollection::check()
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
void GameCollection::space(int num)
{
    for (int i = 0; i < num; i++)
        cout << endl;
}



