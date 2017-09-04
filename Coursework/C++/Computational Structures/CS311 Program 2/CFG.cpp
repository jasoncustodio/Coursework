/*
    Program:     CFG
    Author:      Jason Custodio
    Class:       CS311
    Date:        12/4/2015
*/

#include "CFG.h"

variable::variable():letter(0){}

variable::variable(char c):letter(c){}

void variable::addRule(string i)
{
    rule.push_back(i);
}

int variable::getRule(char input, string& supply)
{
    for(unsigned int i = 0; i<rule.size(); ++i)
    {
        if(rule[i][0] == input)
        {
            supply = rule[i];
            return 1;
        }
    }
    return 0;
}

int variable::match(char c)
{
    if(letter == c)
        return 1;
    return 0;
}

void variable::display() const
{
    cout << "Variable: " << letter << endl;
    for(unsigned int i=0; i<rule.size(); ++i)
        cout << rule[i] << endl;
}
//
CFG::CFG():start(0){}

int CFG::checkTerminal(string s)
{
    for(unsigned int i = 0; i<s.size(); ++i)
    {
        if(terminal.find(s[i])==string::npos)
            return 0;
    }
    return 1;
}

void CFG::addNonterminal(string s)
{
    for(unsigned int i = 0; i<s.size(); ++i)
        nonterminal.push_back(variable(s[i]));
}

void CFG::addRule(char c, string s)
{
    unsigned int i = 0;

    for(i = 0; i<nonterminal.size(); ++i)
        if(nonterminal[i].match(c))
            nonterminal[i].addRule(s);
}

void CFG::display() const
{
    cout << "\nStart:      " << start << endl;
    cout << "\nTerminals:  " << terminal << endl;

    for(unsigned int i = 0; i < nonterminal.size(); ++i)
        nonterminal[i].display();
}

int CFG::checkString(string s)
{
    if(!checkTerminal(s))              //If input string contains incorrect terminal, reject
        return 0;

    char top;                          //Holds top of stack
    char input;                        //Holds next input in buffer
    unsigned int i = 0;                //Iterator
    string temp;                       //Supply rules to stack
    stackPDA.clear();                  //Reset stack
    stackPDA.push_back(start);         //Push starting nonterminal onto stack

    while(!stackPDA.empty())           //Loop until stack is empty
    {
        input = s[i];                  //Holds next char in input buffer
        top = stackPDA.back();         //Holds top of stack
        stackPDA.pop_back();           //Pop top of stack

        if(checkTop(top, input, temp)) //Finds terminal, push rule onto stack
        {
            for(int j = temp.size()-1; j>=0; --j)
                stackPDA.push_back(temp[j]);
        }
        else if(top == input)
            ++i;                       //Increment to next input
        else
            return 0;
    }
     if(i!=s.size())                   //Checks to see if input buffer is empty
        return 0;
    else
        return 1;
}

int CFG::checkTop(char top, char input, string& supply)
{
    for(unsigned int i = 0; i<nonterminal.size(); ++i)
        if(nonterminal[i].match(top))
            return nonterminal[i].getRule(input, supply);
    return 0;
}

void CFG::prompt()
{
     cout << "CFG1.txt    {a^n#b^n|n>0}             \n\n"
          << "CFG2.txt    {w#w^R|wE{0,1}*}          \n\n"
          << "CFG3.txt    {a^i#b^j#c^k#|i=j;i,j,k>0}\n\n"
          << "CFG4.txt    {0^i#1^j|i-j=1|i,j>0}     \n\n"
          << "INPUT TXT FILE NAME:   ";
}

void CFG::load()
{
    ifstream inFile;

    string temp;
    char text[SIZE];
    char c;

    prompt();
    cin >> text;
    cin.ignore();

    inFile.open(text);
    if(inFile)
    {
        inFile.ignore(SIZE, ':');
        inFile >> start;
        inFile.ignore(SIZE, '\n');

        inFile.ignore(SIZE, ':');
        inFile >> terminal;
        inFile.ignore(SIZE, '\n');

        inFile.ignore(SIZE, ':');
        inFile >> temp;
        inFile.ignore(SIZE, '\n');
        addNonterminal(temp);

        inFile.ignore(SIZE, ':');
        inFile >> c;
        inFile.ignore(SIZE, '\n');

        while(inFile && !inFile.eof())
        {
            inFile.ignore(SIZE, ':');
            inFile >> temp;
            inFile.ignore(SIZE, '\n');

            addRule(c, temp);

            inFile.ignore(SIZE, ':');
            inFile >> c;
            inFile.ignore(SIZE, '\n');
        }
    }
    inFile.close();
}




