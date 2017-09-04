/*
    Program:     Accounting Software
    Author:      Jason Custodio
    Class:       CS202
    Date:        06/11/2014
    Description: This program will simulate a simple accounting software
    			 Info is an abstract base class that holds three ints
    			 Info has an id, debit, and credit
    			 Item extends Info which includes a String called label
    			 This label is used to to distinguish and search throughout the BST
    			 Next Node extends Item which includes a next pointer
    			 Node acts as a LLL for the list of items with the same label
    			 TreeNode holds a Node to act as the head of the Item LLL
    			 Each TreeNode holds a label and the total of the sum of debit and credit
    			 A Tree has a TreeNode that acts as the root
    			 Menu only acts as a way to organize output which holds a tree
    			 Added Expenses class which helps sort different trees used using DLL
*/

import java.util.Scanner;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Menu 
{
	static Scanner input = new Scanner(System.in); //Used for input
	
	public List DLL;                               //Tree to hold items
	
	
	
	//Default Constructor
	Menu()
	{
		DLL = new List();
	}
	
	
	
	//Welcomes user and explains rules
	public void welcome()
	{
	    space();
	    System.out.print("********** Accounting ********** \n" + 
	                     "-------------------------------- \n" +
	                     "* Add Expense                  | \n" +
	                     "* Remove Expense               | \n" +
	                     "* Change Expense               | \n" +
	                     "* Add Item                     | \n" +
	                     "* Remove Item                  | \n" +
	                     "* Display Item                 | \n" +
	                     "-------------------------------- \n");
	    check();
	    space();
	}
	
	
	
	//Displays User Interface with multiple commands using a switch statement
	public int displayInterface()
	{
	    int choice = 0;                               //Choice to use for interface (1-4)

	    System.out.print("**** Accounting ****  \n" +
	    		         "Current Expense: " + DLL.getCurrent() + "\n" +
	                     "--------------------- \n" +
	                     "(1) Add    Expense  | \n" + //Add Item to tree according to label
	                     "                    | \n" +
	                     "(2) Remove Expense  | \n" + //Remove Item from tree according to label
	                     "                    | \n" +
	                     "(3) Change Expense  | \n" + //Display all items in tree
	                     "                    | \n" +
	                     "                    | \n" +
	                     "(4) Add     Item    | \n" + //Add Item to tree according to label
	                     "                    | \n" +
	                     "(5) Remove  Item    | \n" + //Remove Item from tree according to label
	                     "                    | \n" +
	                     "(6) Display Item    | \n" + //Display all items in tree
	                     "                    | \n" +
	                     "(7) Display Items   | \n" + //Display all items in tree
	                     "                    | \n" +
	                     "(8) Exit            | \n" + //Close program
	                     "--------------------- \n");

	    System.out.print("\nInput number to choose option: ");
	    choice = input.nextInt();
	    return choice;
	}

	
	
	//Pause checkpoint function
	public void check()
	{
	    String check = new String();

	    do
	    {
	    	System.out.print("\nEnter any key to continue: ");
	    	check = input.next();
	    }while(check.length() == 0);
	}
	
	
	
	//Creates numerous new lines
	public void space()
	{
	    for (int i = 0; i < 100; i++)
	        System.out.println();
	}
	
	
	
	//Load expenses from text file
	public void load()
	{
		BufferedReader b = null;
		
		try
		{
			String s;
			
			b = new BufferedReader(new FileReader("expense.txt"));
			while ((s = b.readLine()) != null)
				DLL.add(s);
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}
	}
	
	
	
	//Displays all expenses
	public void displayAllExpenses()
	{
		System.out.println("EXPENSES");
		System.out.println("--------");
		DLL.displayAll();
		System.out.println();
	}
	

	
	//Add expense to DLL
	public void addExpense()
	{
		String l;
		
		System.out.print("Enter Expense name: "); //User input for name
		l = input.next();
		
		DLL.add(l);                               //Add to DLL passing in user input
		check();
	}
	
	
	
	//Remove expense according to name
	public void removeExpense()
	{
		displayAllExpenses();
		String l;
		System.out.print("Enter Expense name: "); //User input for name
		l = input.next();
		
		DLL.remove(l);                           //Remove expense in DLL
		check();
	}
	
	
	
	//Change current expense to manage
	public void changeExpense()
	{
		displayAllExpenses();
		String l;
		System.out.print("Enter Expense name: "); //User input for name
		l = input.next();
		
		DLL.setCurrent(l);                        //Switch current expense
		check();
	}

	
	
	//Add item to BST
	public void addItem()
	{
		String l;
		int c = 0;
		int d = 0;
		int i = 0;
		
		System.out.print("Enter Description: "); //User input for label
		l = input.next();
		System.out.println();
		
		System.out.print("Enter Credit:      "); //User input for credit
		c = input.nextInt();
		System.out.println();
		
		System.out.print("Enter Debit:       "); //User input for debit
		d = input.nextInt();
		System.out.println();
		
		System.out.print("Enter Id:          "); //User input for id
		i = input.nextInt();
		
		DLL.add(i,d,c,l);                        //Add to BST passing in user input
		check();
	}
	
	
	
	//Remove item according to label
	public void removeItem()
	{
		String l;
		System.out.print("Enter Description: "); //User input for label
		l = input.next();
		
		DLL.removeNode(l);                       //Remove item in BST
		check();
	}
	
	
	
	//Display item according to label
	public void displayItem()
	{
		String l;
		System.out.print("Enter Description: "); //User input for label
		l = input.next();
		
		DLL.display(l);                          //Display all items with same label
		check();
	}
	
	
	
	//Display all items in current expense
	public void displayAllItem()
	{		
		DLL.displayAllItem();                
		check();
	}
}
