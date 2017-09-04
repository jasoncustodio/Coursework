/*
    Program:     CFG
    Author:      Jason Custodio
    Class:       CS311
    Date:        12/4/2015
*/

#include "CFG.h"

int again();

int main()
{
    CFG myCFG;
    string input;

    myCFG.load();

    while(again())
    {
        cout << "\nINPUT STRING TO PARSE: ";
        cin  >> input;
        cin.ignore();

        if(myCFG.checkString(input))
            cout << "\nPART OF GRAMMER!\n";
        else
            cout << "\nNOT PART OF GRAMMAR!\n";
    }
    return 0;
}

int again()
{
    char check;
    cout << "\nREADY TO PARSE? (Y/N)\n";
    cin >> check;
    cin.ignore();

    if(toupper(check) == 'Y')
        return 1;
    return 0;
}
