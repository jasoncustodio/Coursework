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

public class Node extends Item
{
	private Node next; //Next node in LLL
	
	
	
	//Default constructor calling base class default constructor
	Node()
	{
		super();
		next =  null;
	}
	
	
	
	//Constructor that sets data members, uses base class constructor
	Node(int i, int d, int c, String l)
	{
		super(i,d,c,l);
		setNext(null);
	}
	
	
	
	//Display was already inherited, but wanted to test out super with non constructors and try not overriding
	public void display()
	{
		super.display();
	}
	
	
	
	//Getter for next
	public Node getNext() 
	{
		return next;
	}
	
	
	
	//Sets next to another node
	public void setNext(Node next) 
	{
		this.next = next;
	}
	
	//To test out function overloading
	public void display(String x, String y)
	{
		System.out.println("You typed: " + x);
		System.out.println("You typed: " + y);
	}
}
