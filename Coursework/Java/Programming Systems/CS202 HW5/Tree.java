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

public class Tree 
{
	protected TreeNode root; //Root for BST
	protected int total;     //Total of sum of debit+credit in LLL
	
	
	
	//Default Constructor
	Tree()
	{
		root = null;
		total = 0;
	}
	
	
	
	
	//Add item to BST wrapper function
	public void add(int i, int d, int c, String l)
	{
		root = add(root, i, d ,c, l);
	}
	
	
	
	//Add item to BST
	private TreeNode add(TreeNode root, int i, int d, int c, String l)
	{
		if(root == null)            //If BST is empty or label doesn't exist
		{
			root = new TreeNode(l); //Make a new tree node if label doesn't exist
			root.add(i, d, c, l);   //Add item to LLL
			total += d + c;         //Increment total of debit+credit
			return root;
		}
		
		if(l.compareToIgnoreCase(root.getLabel()) == 0) //If there is a match according to label
		{
			root.add(i, d, c, l);                       //Add to LLL 
			total += d + c;                             //Increment total of debit+credit
			return root;
		}
		
		if((l.compareToIgnoreCase(root.getLabel()) > 0))     //If new item is greater than existing go right
			root.setRight(add(root.getRight(), i, d, c, l));
		else
			root.setLeft(add(root.getLeft(), i, d, c, l));   //Otherwise go left
		return root;
	}
	
	
	
	//Return total amount used for interface
	public int getTotal()
	{
		return total;
	}
	
	
	
	//Display all items in BST wrapper function
	public void displayAll()
	{
		displayAll(root);
	}
	
	
	
	//Display all items in BST in order traversal
	private void displayAll(TreeNode root)
	{
		if(root == null) return;
		
		displayAll(root.getLeft());  
		root.displayAll();
		displayAll(root.getRight());
	}
	
	
	
	//Display all items with same label wrapper function
	public void display(String l)
	{
		display(root, l);
	}
	
	
	
	//Display all items with same label
	private void display(TreeNode root, String l)
	{
		if(root == null) return;
		
		if(l.compareToIgnoreCase(root.getLabel()) == 0)  //Check if label is same, then display
			root.displayAll();
		
		if((l.compareToIgnoreCase(root.getLabel()) > 0)) //Check to see to go left or right
			display(root.getRight(),l);
		else
			display(root.getLeft(),l);
	}
	
	
	
	//Remove TreeNode according to label wrapper function
	public void remove(String l)
	{
		root = remove(root,l);
	}
	
	
	
	//Remove TreeNode according to label 
	private TreeNode remove(TreeNode root, String l)
	{
		if(root == null) return root;
		
		if(l.compareToIgnoreCase(root.getLabel())==0)       //If there is a match
	    {
	        if(!root.checkLeft() && !root.checkRight())     //Remove leaf
	        {
	        	total -= root.getTotal();
	            root = null;
	            return root;
	        }
	        else if(root.checkLeft() && !root.checkRight()) //Remove root with left child
	        {
	        	total -= root.getTotal();
	            TreeNode temp = root.getLeft();
	            root = null;
	            root = temp;
	            return root;
	        }
	        else if(!root.checkLeft() && root.checkRight()) //Remove root with right child
	        {
	        	total -= root.getTotal();
	            TreeNode temp = root.getRight();
	            root = null;
	            root = temp;
	            return root;
	        }
	        else if(!root.getRight().checkLeft() && root.getRight().checkRight()) //Remove root with 2 children
	        {
	        	total -= root.getTotal();
	            TreeNode temp = root.getRight().getRight(); //In order successor is right child's right child
	            root.copy(root.getRight());
	            root.setRight(null);
	            root.setRight(temp);
	            return root;
	        }
	        else //Remove root with 2 children
	        {
	        	total -= root.getTotal();
	            TreeNode current;
	            TreeNode previous = root;

	            for(current=root.getRight(); current.checkLeft(); current=current.getLeft()) //Go right twice, then spin all the way left
	                previous = current;

	            previous.setLeft(current.getRight()); //Connect in order successor's right child/tree
	            root.copy(current);

	            current = null;
	            return root;
	        }
	    }
		if((l.compareToIgnoreCase(root.getLabel()) > 0))
			root.setRight(remove(root.getRight(),l));
		else
			root.setLeft(remove(root.getLeft(),l));
		return root;
	}
}
