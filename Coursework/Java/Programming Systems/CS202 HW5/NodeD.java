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

public class NodeD extends Expense
{
	private NodeD next;     //Next node in DLL
	private NodeD previous; //Previous node in DLL
	
	
	
	//Default constructor calling base class default constructor
	NodeD()
	{
		super();
		next =  null;
		previous = null;
	}
	
	
	
	//Constructor that sets data members, uses base class constructor
	NodeD(String n)
	{
		super(n);
		setNext(null);
		setPrevious(null);
	}
	
	

	//Getter for next
	public NodeD getNext() 
	{
		return next;
	}
	
	
	
	//Getter for previous
	public NodeD getPrevious() 
	{
		return previous;
	}
	
	
	
	//Sets next to another node
	public void setNext(NodeD next) 
	{
		this.next = next;
	}
	
	
	
	//Sets previous to another node
	public void setPrevious(NodeD previous) 
	{
		this.previous = previous;
	}
}
