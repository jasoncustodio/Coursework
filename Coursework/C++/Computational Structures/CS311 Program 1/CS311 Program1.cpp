#include "DFA.h"

int main()
{
    DFA myDFA;
    string input = "102";

    myDFA.load();
    myDFA.display();

    //cout << "Enter input string: ";
    //cin  >> input;
    //cout << endl;

    if(myDFA.checkString(input))
        cout << input << " (IS) part of the language!    " << endl;
    else
        cout << input << " (IS NOT) part of the language!" << endl;

	return 0;
}
