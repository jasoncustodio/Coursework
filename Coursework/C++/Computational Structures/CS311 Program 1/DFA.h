/*
    Program:     DFA
    Author:      Jason Custodio
    Class:       CS311
    Date:        10/23/2015
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int SIZE = 100;

class transition                               //Holds transition functions
{
      public:
             transition();                     //Transition default constructor
             transition(int, char);            //Transition output/input args constructor

             int  getOutput();                 //Output Getter
             int  matchInput(char);            //Helps to search transition function
             void display() const;             //Display output/input
      private:
              int  output;                     //Holds number of state
              char input;                      //Holds input to go to output
};

class state                                    //Acts as a state with a vector of transitions
{
      public:
             state();                          //State default constructor

             void display() const;             //Displays all transition functions within state
             int  getTransition(char);         //Used to get next transition state
             void addTransition(int, char);    //Adds transition to vector

      private:
              vector <transition>edge;         //List of all transitions within state
};

class DFA                                      //Holds list of states
{
      public:
             DFA();                            //DFA default constructor

             void load();                      //Load all data from external "transitions.txt" file
             void addState(int);
             void display() const;             //Displays all states and transitions
             void addFinalState(int);          //Adds final states
             int  checkString(string);         //Check to see if string is part of language
             int  checkAlphabet(string);       //Checks if input is part of alphabet
             void addTransition(int,int,char); //Add transitions to states

      private:
              int startState;                  //One start state
              string alphabet;                 //Holds alphabet of DFA
              vector <int>finalState;          //Holds list of all final states
              vector <state>stateList;         //Holds all states
};




