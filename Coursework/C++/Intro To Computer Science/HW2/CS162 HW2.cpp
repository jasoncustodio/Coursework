/*
    Program: CS_Word_Find Program
    Author:  Jason Custodio
    Class:   CS162
    Date:    10/28/2013
    Description: First welcome and explain rules
                 Display Interface and display letters that can be used
                 Keep looping until user wants to exit.
                 Keep looping new lines to create clean screens after each command.
                 When a word is created, check if the letters are valid
                 Add points according to word length
                 Adding a vowel will cost 1 point
                 Displays if player wins/loses depending on points
                 Allow the player to reset the game anytime
*/

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

char doRand ();                      //Uses random function, made to create random array
void welcome();                      //Greets user and explains rules
void space  ();                      //Provides clean output buffer
void check  ();                      //Allows for a resting point
void letter   (char[]);              //Stores random letters
void addVowels(char[],int);          //Adds chosen vowels and subtracts points
void display    (char[], int);       //Displays what letters can be used
void checkLength(char[],int&);       //Checks length of word made, allocates points
int  interface(char[], int, int);    //Creates a user interface, displays points and letters
bool checking (char[],char[], int);  //Checks if letters used to make words are valid
void make(char[], char[],int&, int); //Creates words and adds points

const int SIZE = 20; //Size for all arrays
const int MIN  = 6;  //Minimum amount for random letter array

int main()
{
    srand(time(0));     //Seeds random generator

    char letters[SIZE]; //Random letter array
    char word   [SIZE]; //Words made from random letter array

    int points = 0;     //Points gained/spent
    int choice = 0;     //Used for switch statement
    int vowels = 0;     //Number of vowels

    letter(letters);
    welcome();

    do
    {
        choice = interface(letters, points, vowels); //Calls interface function to display user interface

        space();                                     //Creates a clean page after every command

        switch (choice)                              //Switch statement starts with 4 commands
        {
            case 1:
            {
                make(letters,word,points, vowels);   //Creates word and adds points
            }break;

            case 2:
            {
                addVowels(letters,vowels);           //Adds vowels, subtracts 1 point each time
                vowels++;
                --points;
            }break;

            case 3:
            {
                letter(letters);                     //Resets letters and sets points/vowels to 0
                points = 0;
                vowels = 0;
            }break;

            default:break;
        }

    }while (choice!=4);
    return 0;
}

//Uses rand function
char doRand()
{
    return ((rand()%26) + 'A');
}

//Welcomes user and explains rules
void welcome()
{
    cout << "*WELCOME TO THE WORD FIND PROGRAM*      " << endl
         << "----------------------------------      " << endl
         << "* Make words with 6 random letters      " << endl
         << "* Buying a vowel costs 1 point          " << endl
         << "* 2 or 3 letter words equals 2 points   " << endl
         << "* 4 or 5 letter words equals 3 points   " << endl
         << "* 6 or more letter words equals 4 points" << endl
         << "* 20 points are needed to win           " << endl
         << "* Have fun!                             " << endl;
         check();
}

//Creates blank page by looping new lines
void space()
{
    for (int i = 0; i < 100; i++)
        cout << endl;
}

//Allows for a resting point between commands
void check()
{
    char check;

    do
    {
        cout << "\nEnter any key to continue: ";
        cin  >> check;
        cin.ignore();
    }while (isblank(check) == 1);
}

//Creates array of random letters,
//makes sure there are no repeating letters
void letter(char letters[])
{
    int i = 0;
    int j = 0;

    for(i = 0; i < MIN; ++i)
        letters[i] = '0';

    for(i = 0; i < MIN; ++i)
    {
        letters[i] = doRand();
        for(j = 0; j < i; ++j)
        {
            while(letters[i] == letters[j])
                letters[i]= doRand();
        }
    }
}

//Adds vowels, costs one point
void addVowels(char letters[], int vowels)
{
    char vowel;

    cout << "A E I O U"    << endl
         << "Input Vowel: ";
    cin  >> vowel;
    cin.ignore();

    if(toupper(vowel) == 'A')
        letters[MIN+vowels] = 'A';
    else if(toupper(vowel) == 'E')
        letters[MIN+vowels] = 'E';
    else if(toupper(vowel) == 'I')
        letters[MIN+vowels] = 'I';
    else if(toupper(vowel) == 'O')
        letters[MIN+vowels] = 'O';
    else if(toupper(vowel) == 'U')
        letters[MIN+vowels] = 'U';
}

//Display random generated letter array with chosen vowels
void display(char letters[], int vowels)
{
    int i = 0;

    cout << "Letter Bank"  << endl
         << "-----------"  << endl;

    for(i = 0; i < (MIN+vowels); ++i)
        cout << letters[i] << "  ";

    for(i = 0; i < 3; ++i)
        cout << endl;
}

//Check length and assign points
void checkLength(char word[], int& points)
{
    int length = strlen(word);

    if(length == 2 || length == 3)
        points += 2;
    else if(length == 4 || length == 5)
        points += 3;
    else if (length >= 6)
        points += 4;
}

//Displays User Interface with multiple commands using a switch statement
int interface(char letters[], int points, int vowels)
{
    int choice = 0;

    space();

    if (points >= 20)
            cout << "YOU WIN!\n" << endl;
    else if(points < 0)
            cout << "YOU LOSE!\n"<< endl;

    display(letters, vowels);

    cout << "Points: " << points << endl

         << endl                 << endl
         << "1) Create Word\n"   << endl
         << "2) Buy A Vowel\n"   << endl
         << "3) Reset Game \n"   << endl
         << "4) Exit       \n"   << endl
         << "\nEnter number to choose option: ";

        cin >> choice;
        cin.ignore();
        return choice;
}

//Checks if the letters used are valid letters
bool checking(char letters[], char word[], int vowels)
{
    bool flag = false;
    int i = 0;
    int j = 0;

    do
    {
        flag = false;
        for(i = 0; i < MIN+vowels; ++i)
        {
            if(toupper(word[j]) == letters[i])
                flag = true;
        }

        if(flag == false)
            return false;
        ++j;
    }while(j < strlen(word));

    return true;
}

//Make a word, adds points according to number of letters
void make(char letters[], char word[], int& points, int vowels)
{
    bool valid = true;

    do
    {
        for (int i = 0; i < SIZE; ++i)
            word[i] = '0';

        cout << endl;
        display(letters, vowels);
        cout << "Input word: ";
        cin.get(word,SIZE, '\n');
        cin.ignore(100,'\n');

        if(checking(letters,word, vowels) == false)
        {
            space();
            cout << "\nInvalid Word" << endl;
            valid = false;
        }

        if(checking(letters,word, vowels) == true)
        {
            checkLength(word, points);
            valid = true;
        }

    }while(valid == false);
}


