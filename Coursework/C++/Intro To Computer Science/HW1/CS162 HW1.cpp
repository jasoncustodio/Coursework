/*
    Program: Income Evaluation
    Author:  Jason Custodio
    Class:   CS162
    Date:    10/14/2013
    Description: First welcome and instruct user how to use the program.
                 Display Interface that allows user to freely modify values.
                 Keep looping until user wants to exit.
                 Keep looping new lines to create clean screens after each command.
                 Give the user the option to display any value
                 Find largest expenditure by searching through an array and recommend them to decrease it.
                 Show final report that consists of resulting balance between expenses and income.
                 Give recommendations based on balance, encouraging for a higher balance.
*/

#include <iostream>
using namespace std;

void  space();                             //Clear screens
void  check();                             //Allow resting point
void  report      (float&);                //All expenses have same report calculation
float expenseTotal(float[]);               //Uses array to sum up all expenses
void  maxExpense  (float[]);               //Finds largest expense, recommends to decrease it
int   interface   (float[], float, float); //Displays user friendly interface
void  finalReport (float[], float, float); //Shows ending balance and recommendations

const int SIZE  = 7;                       //Array Size that holds expenses

int main()
{
    float expense[SIZE] = {}; //Each corresponding expense holds a value in an array cell

    float savings = 0.0;      //Value that holds savings
    float income  = 0.0;      //Value that holds monthly income

    int i      = 0;           //Iterator for "for statements"
    int choice = 0;           //Value used for choosing in switch statement

    cout << "*WELCOME TO THE INCOME EVALUATION PROGRAM*" << endl //User Greetings and Instructions
         << "------------------------------------------" << endl
         << "Once you enter the user interface, enter  " << endl
         << "the corresponding number to each command. " << endl
         << "Inputing numbers from the Expense and     " << endl
         << "Income Report will allow you to modify    " << endl
         << "them. Inputing numbers from the Other     " << endl
         << "Options will allow you to reset and view  " << endl
         << "results. Have fun!"                         << endl;
         check();

    do
    {
        choice = interface(expense,savings,income); //Calls interface function to display user interface

        space();                                    //Creates a clean page after every command

        switch (choice)                             //Switch statement starts with 14 commands
        {
            case 1:
            {
                cout << "\nReport Entertainment Expenses: "; //Expense[0] holds Entertainment Expenses
                report(expense[0]);                          //Report Function modifies Entertainment
            }break;

            case 2:
            {
                cout << "\nReport Utilities Expenses: ";     //Expense[1] holds Utilities Expenses
                report(expense[1]);                          //Report Function modifies Utilities
            }break;

            case 3:
            {
                cout << "\nReport Repair Expenses: ";        //Expense[2] holds Repair Expenses
                report(expense[2]);                          //Report Function modifies Repair
            }break;

            case 4:
            {
                cout << "\nReport Rent Expenses: ";          //Expense[3] holds Rent Expenses
                report(expense[3]);                          //Report function modifies Rent
            }break;

            case 5:
            {
                cout << "\nReport Food Expenses: ";          //Expense[4] holds Food Expenses
                report(expense[4]);                          //Report function modifies Food
            }break;

            case 6:
            {
                cout << "\nReport Gas Expenses: ";           //Expense[5] holds Gas Expenses
                report(expense[5]);                          //Report function modifies Gas
            }break;

            case 7:
            {
                cout << "\nReport Monthly Income: ";         //Report function modifies income
                report(income);
            }break;

            case 8:
            {
                cout << "\nReport Savings: ";                //Report function modifies savings
                report(savings);
            }break;

            case 9:
            {
                for (i = 0; i < SIZE; i++)                   //Resets all expenses to 0
                    expense[i] = 0.0;
            }break;

            case 10:
            {
                savings = 0.0;                               //Resets savings/income to 0
                income  = 0.0;
            }break;

            case 11:
            {
                cout << "\nTotal Expenses: $"                //Displays sum of all expenses
                     << expenseTotal(expense)
                     << endl;
                     check();
            }break;

            case 12:
            {
                cout << "\nTotal Income: $"                  //Displays sum of savings and income
                     << savings + income
                     << endl;
                     check();
            }break;

            case 13:
            {
                finalReport(expense,savings,income);        //Displays ending balance and recommendations
            }break;

            default:break;
     }

    }while (choice!=14);                                    //Loops or exits program
    return 0;
}

//Creates blank page by looping new lines
void space()
{
    for (int i = 0; i < 70; i++)
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
    }while (isblank(check) == 1);
}

//Modifies each expense/income and calls space function
void report(float& value)
{
    float amount = 0.0;

    cin >> amount;
    value += amount;
    space();
}

//Loops through whole array, adding all values along the way, returns the sum of all expenses
float expenseTotal(float expense[])
{
    float total = 0.0;
    int i = 0;

    for (i = 0; i < SIZE; i++)
        total += expense[i];

    return total;
}

//Loops through whole array, storing the largest value, loops again to find correct array cell
//If all the values are 0, there will be no max value, finally display largest expense
void maxExpense(float expense[])
{
    int i      = 0;
    int choice = 0;
    float max  = 0.0;

    for (i = 0; i < SIZE; i++)
    {
        if (max <= expense[i])
            max = expense[i];
    }
    if (max <= 0)
        cout << endl;
    else
    {
        for (i = 0; i < SIZE; i++)
        {
            if (max == expense[i])
                choice = i+1;
        }
        cout << "\nFocus On Decreasing ";

        switch (choice)
        {
            case 1:
            {
                cout << "Entertainment Expenses!";
            }break;

            case 2:
            {
                cout << "Utilities Expenses!";
            }break;

            case 3:
            {
                cout << "Repairs Expenses!";
            }break;

            case 4:
            {
                cout << "Rent Expenses!";
            }break;

            case 5:
            {
                cout << "Food Expenses!";
            }break;

            case 6:
            {
                cout << "Gas Expenses!";
            }break;

            default:break;
        }
    }
}

//Displays User Interface with multiple commands using a switch statement
int interface(float expense[], float savings, float income)
{
    int choice = 0;

    space();

    cout << "Expense Report     Total"           << endl
         << "--------------     -----"           << endl
         << "1) Entertainment   $" << expense[0] << endl
         << "2) Utilities       $" << expense[1] << endl
         << "3) Repairs         $" << expense[2] << endl
         << "4) Rent            $" << expense[3] << endl
         << "5) Food            $" << expense[4] << endl
         << "6) Gas             $" << expense[5] << endl

         << endl

         << "Income Report       " << endl
         << "-------------       " << endl
         << "7) Monthly Income  $" << income     << endl
         << "8) Savings         $" << savings    << endl

         << endl

         << "Other Options            " << endl
         << "-------------            " << endl
         << "9)  Reset Expenses       " << endl
         << "10) Reset Income         " << endl
         << "11) Display Total Expense" << endl
         << "12) Display Total Income " << endl
         << "13) Display Final Report " << endl
         << "14) Exit"                  << endl
         << "\nEnter number to choose option: ";

        cin  >> choice;
        return choice;
}

//Displays final balance and recommends based on balance, higher balance is better
void finalReport(float expense[], float savings, float income)
{
    double balance = (savings + income) - expenseTotal(expense);

    cout << "Ending Balance: $" << balance;

    if (balance <= 1000)
    {
        cout << "\nHire An Accountant "
             << "To Create A Budget Plan!";
    }
    else if (balance < 100000 && balance >= 10000)
    {
        cout << "\nKeep Saving!";
    }
    else if (balance < 1000000 && balance >= 100000)
    {
        cout << "\nGood Job!";
    }
    else if (balance >= 1000000)
    {
        cout << "\nPlease Share!";
    }

    maxExpense(expense);
    check();
}






