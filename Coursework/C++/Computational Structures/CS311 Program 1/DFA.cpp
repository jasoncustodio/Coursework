/*
    Program:     DFA
    Author:      Jason Custodio
    Class:       CS311
    Date:        10/23/2015
*/

#include "DFA.h"

transition::transition():output(0), input(0){}

transition::transition(int o, char i):output(o), input(i){}

int transition::matchInput(char c)
{
    if(input==c)
        return 1;
    else
        return 0;
}

int transition::getOutput()
{
    return output;
}

void transition::display() const
{
    cout << "Output: " << output << endl;
    cout << "Input:  " << input  << endl;
}
//
state::state(){}

void state::addTransition(int o, char i)
{
    edge.push_back(transition(o,i));
}

int state::getTransition(char c)
{
    for(unsigned int i=0; i<edge.size(); ++i)
    {
        if(edge[i].matchInput(c))
            return edge[i].getOutput();
    }
    return 0;
}

void state::display() const
{
    for(unsigned int i=0; i<edge.size(); ++i)
        edge[i].display();
}
//
DFA::DFA():startState(0){}

int DFA::checkAlphabet(string s)
{
    for(unsigned int i = 0; i<s.size(); ++i)
    {
        if(alphabet.find(s[i])==string::npos)
            return 0;
    }
    return 1;
}

void DFA::addState(int n)
{
    for(int i=0; i<n; ++i)
        stateList.push_back(state());
}

void DFA::addTransition(int index, int o, char i)
{
    stateList[index].addTransition(o,i);
}

void DFA::addFinalState(int i)
{
    finalState.push_back(i);
}

int DFA::checkString(string s)
{
    if(!checkAlphabet(s))
        return 0;

    int flag;
    flag = stateList[startState].getTransition(s[0]);

    for(unsigned int i=1; i<s.size(); ++i)
        flag = stateList[flag].getTransition(s[i]);

    for(unsigned int j=0; j<finalState.size(); ++j)
        if(flag == finalState[j])
            return 1;
    return 0;
}

void DFA::display() const
{
    cout << "\nAlphabet:     " << alphabet   << endl;
    cout << "\nStart State:  " << startState << endl;
    cout << "\nFinal States: ";

    for(unsigned int i = 0; i < finalState.size(); ++i)
        cout << finalState[i] << " ";
    cout << endl << endl << endl;
}

void DFA::load()
{
    ifstream inFile;

    char input     = 0;
    int index      = 0;
    int output     = 0;
    int numFinal   = 0;
    int numState   = 0;
    int numFStates = 0;

    inFile.open("transition.txt");
    if(inFile)
    {
        inFile.ignore(SIZE, ':');
        inFile >> numState;
        inFile.ignore(SIZE, '\n');
        addState(numState);

        inFile.ignore(SIZE, ':');
        inFile >> numFStates;
        inFile.ignore(SIZE, '\n');

        inFile.ignore(SIZE, ':');
        inFile >> alphabet;
        inFile.ignore(SIZE, '\n');

        inFile.ignore(SIZE, ':');
        inFile >> startState;
        inFile.ignore(SIZE, '\n');

        for(int i=0; i<numFStates; ++i)
        {
          inFile.ignore(SIZE, ':');
          inFile >> numFinal;
          finalState.push_back(numFinal);
        }
        inFile.ignore(SIZE, '\n');

        inFile.ignore(SIZE, ':');
        inFile >> index;
        inFile.ignore(SIZE, '\n');

        while(inFile && !inFile.eof())
        {
            inFile.ignore(SIZE, ':');
            inFile >> output;
            inFile.ignore(SIZE, '\n');

            inFile.ignore(SIZE, ':');
            inFile >> input;
            inFile.ignore(SIZE, '\n');

            addTransition(index, output, input);

            inFile.ignore(SIZE, ':');
            inFile >> index;
            inFile.ignore(SIZE, '\n');
        }
    }
    inFile.close();
}




