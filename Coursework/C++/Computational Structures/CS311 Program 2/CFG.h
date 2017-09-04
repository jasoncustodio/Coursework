/*
    Program:     CFG
    Author:      Jason Custodio
    Class:       CS311
    Date:        12/4/2015
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int SIZE = 100;

class variable                                   //A nonterminal that holds rules
{
      public:
             variable();                         //Default constructor
             variable(char);                     //Constructor with nonterminal argument

             int  match(char);                   //Checks if input buffer has a nonterminal
             void display() const;               //Displays all rules of nonterminal
             int  getRule(char, string&);        //Used to supply rule to stack
             void addRule(string);               //Adds a rule to a nonterminal

      private:
              char letter;                       //Nonterminal value
              vector <string>rule;               //List of all rules for nonterminal
};

class CFG                                        //Holds stack, terminals, nontermials, start, and rules of CFG
{
      public:
             CFG();                              //Default constructor

             void load();                        //Load all data from external txt file
             void prompt();                      //Prompt user to input txt file
             void display() const;               //Displays CFG 4-tuple
             int  checkString(string);           //Check to see if string is part of grammar
             int  checkTerminal(string);         //Checks if all chars in input grammar is appropriate
             void addRule(char, string);         //Adds a rule to a nonterminal
             void addNonterminal(string);        //Adds a nonterminal to the CFG
             int  checkTop(char, char, string&); //Checks to see if top of stack is a nonterminal

      private:
              char start;                        //Start nonterminal
              string terminal;                   //Holds all appropriate terminals
              vector <char>stackPDA;             //Stack for pushing/popping rules
              vector <variable>nonterminal;      //Holds all nonterminals with their rules

};




