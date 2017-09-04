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

public class Item extends Info
{
	protected String label; //Description of item
	
	
	
	//Default constructor that calls base class constructor
	Item()
	{
		super();
	}
	
	
	
	//Constructor that sets all data members, uses base class constructor
	Item(int i, int d, int c, String l)
	{
		super(i,d,c);
		label = l;
	}
	
	
	
	//Getter for label
	public String getLabel()
	{
		return label;
	}
	
	
	
	//To test out function overloading
	public void display(String l)
	{
		System.out.print("You typed: " + l);
	}
	
	
	
	//To test out function overloading
	public void displayId(String x, int y)
	{
		System.out.println("Id:     " + id);
		System.out.println("New Id:     " + x + y);
	}
		
	
	public void display()
	{
		Info temp = this;
		temp.displayTest();
	}
	
	//Must implement display for dynamic binding, test purposes for dynamic binding
	public void displayTest()
	{
		System.out.println();
		System.out.println("Label:  " + label);
		displayId();
		displayDebit();
		displayCredit();
	}
}
