/*
    Program:     Accounting Software
    Author:      Jason Custodio
    Class:       CS202
    Date:        06/04/2014
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
*/

abstract class Info 
{
	protected int id;     //Acts as a reference number to differ within label group
	protected int debit;  //Amount of debit used
	protected int credit; //Amount of credit used
	
	
	
	//Default constructor
	Info()
	{
		id     = 0;
		debit  = 0;
		credit = 0;
	}
	
	
	
	//Constructor that sets all data members
	Info(int i, int d, int c)
	{
		id     = i;
		debit  = d;
		credit = c;
	}
	
	
	
	//Display Id
	public void displayId()
	{
		System.out.println("Id:     " + id);
	}
	
	
	
	//Display Debit
	public void displayDebit()
	{
		System.out.println("Debit:  " + debit);
	}
	
	
	
	//Display Credit
	public void displayCredit()
	{
		System.out.println("Crebit: " + credit);
	}
	
	
	
	//Only used for testing dynamic binding
	public void displayTest()
	{
		System.out.println("This is a test");
	}
	
	
	
	//Abstract method used for dynamic binding
	public abstract void display();
}
