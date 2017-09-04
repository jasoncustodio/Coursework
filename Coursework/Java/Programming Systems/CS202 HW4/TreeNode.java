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

public class TreeNode
{
	private int total;      //Total of credit+debit in LLL
	private String label;   //Description of type of item
	private Node head;      //Head of LLL
	private TreeNode left;  //Left child
	private TreeNode right; //Right child
	
	
	
	//Default Constructor
	TreeNode()
	{
		total = 0;
		label = null;
		head  = null;
		left  = null;
		right = null;
	}
	
	
	
	//Constructor with specified label
	TreeNode(String l)
	{
		total = 0;
		label = l;
		head  = null;
		left  = null;
		right = null;
	}

	
	
    //Add item to LLL for mathcing labels
	public void add(int i, int d, int c, String l)
	{
		Node temp = new Node(i,d,c,l);
		total += d + c; //Increment total with sum of debit+credit
		if(head == null)
		{
			label = l;
			head = temp;
		}
		else
		{
			temp.setNext(head);
			head = temp;
		}
	}
	
	
	
	//Display all items in LLL wrapper function
	public void displayAll()
	{
		displayAll(head);
	}
	
	
	
	//Display all items in LLL
	private void displayAll(Node head)
	{
		if(head == null) return;
		head.display();
		displayAll(head.getNext());
	}
	
	
	
	//Return total, used to decrement Tree's total
	public int getTotal()
	{
		return total;
	}
	
	
	
	//Getter for head
	public Node getHead() 
	{
		return head;
	}
	
	
	
	//Getter for label
	public String getLabel() 
	{
		return label;
	}

	
	
	//Points head to another node
	public void setHead(Node head) 
	{
		this.head = head;
	}
	
	
	
	//Sets left to another node
	public void setLeft(TreeNode left) 
	{
		this.left = left;
	}
	
	
	
	//Sets right to another node
	public void setRight(TreeNode right) 
	{
		this.right = right;
	}
	
	
	
	//Getter for left child
	public TreeNode getLeft() 
	{
		return left;
	}
	
	
	
	//Getter for right child
	public TreeNode getRight() 
	{
		return right;
	}
	
	
	
	//Checks if left is null
	public boolean checkLeft()
	{
		if(left == null) return false;
		else return true;
	}
	
	
	
	//Checks if right is null
	public boolean checkRight()
	{
		if(right == null) return false;
		else return true;
	}
	
	
	
	//Points head to another LLL
	public void copy(TreeNode root)
	{
		this.head = root.getHead();
	}
}
