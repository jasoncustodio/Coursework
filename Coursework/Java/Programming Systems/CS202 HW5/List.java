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

public class List
{
	private NodeD head;    //Head for DLL
	private int total;     //Total of sum of Expenses
	private NodeD current; //Current expense to manage
	
	
	
	//Default Constructor
	List()
	{
		head = null;
		total = 0;
		current = null;
	}
	
	
	
	//Add item to current expense
	public void add(int i, int d, int c, String l)
	{
		current.add(i,d,c,l);
	}
	
	
	
	//Remove item in current expense
	public void removeNode(String l)
	{
		current.remove(l);
	}
	
	
	
	//Display items with same label for current
	public void display(String l)
	{
		current.display(l);
	}
	
	
	
	//Add expense to DLL
	public void add(String n)
	{
		NodeD temp = new NodeD(n);
		
		temp.setNext(head);
		
		if(head != null) head.setPrevious(temp);
		head = temp;
		current = temp;
	}
	
	
	
	//Switch current expense to manage
	public void setCurrent(String n)
	{
		NodeD temp;
		for(temp = head; temp != null; temp = temp.getNext())
			if(n.compareToIgnoreCase(temp.getName())==0)
				current = temp;
	}
	
	
	
	//Get current expense name
	public String getCurrent()
	{
		return current.getName();
	}
	
	
	
	//Return total amount used for interface
	public int getTotal()
	{
		return total;
	}
	
	
	
	//Display all expenses in DLL
	public void displayAll()
	{
		displayAll(head);
	}
	
	
	
	//Display all expenses in DLL
	private void displayAll(NodeD head)
	{
		if(head == null) return;
		 
		head.displayName();
		System.out.println();
		displayAll(head.getNext());
	}
	
	
	
	//Display all items in current's BST
	public void displayAllItem()
	{
		current.displayAll();
	}

	
	
	//Remove expense according to name wrapper function
	public void remove(String n)
	{
		head = remove(head,n);
	}
	
	
	
	//Remove expense according to name
	private NodeD remove(NodeD head, String n)
	{
		if(head == null) return head;
		
		if(n.compareToIgnoreCase(head.getName())==0)       //If there is a match
	    {
			NodeD temp = head.getNext();
			head = null;
			head = temp;
			return head;
	    }
		head.setNext(remove(head.getNext(),n));
		return head;
	}
}
