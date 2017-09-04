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

class Expense extends Tree
{
	protected String name;
	
	
	
	//Default constructor
	Expense()
	{
		super();
		name = "Expense";
	}
	
	
	
	//Constructor that sets all data members
	Expense(String n)
	{
		super();
		name = n;
	}
	
	
	
	//Name Getter
	public String getName()
	{
		return name;
	}
	
	
	
	//Display Id
	public void displayName()
	{
		System.out.print(name);
	}
}
