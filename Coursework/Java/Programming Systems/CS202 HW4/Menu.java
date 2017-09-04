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

import java.util.Scanner;

public class Menu 
{
	static Scanner input = new Scanner(System.in); //Used for input
	
	public Tree BST;                               //Tree to hold items
	
	
	
	//Default Constructor
	Menu()
	{
		BST = new Tree();
	}
	
	
	
	//Welcomes user and explains rules
	public void welcome()
	{
	    space();
	    System.out.print("********** Accounting ********** \n" + 
	                     "-------------------------------- \n" +
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
	    		         "Total: " + BST.getTotal() + "\n" +
	                     "--------------------- \n" +
	                     "(1) Add Item        | \n" + //Add Item to tree according to label
	                     "                    | \n" +
	                     "(2) Remove Item     | \n" + //Remove Item from tree according to label
	                     "                    | \n" +
	                     "(3) Display Item    | \n" + //Display all items in tree
	                     "                    | \n" +
	                     "(4) Exit            | \n" + //Close program
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
	
	
	
	//Add item to BST
	public void add()
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
		
		BST.add(i,d,c,l);                        //Add to BST passing in user input
		check();
	}
	
	
	
	//Remove item according to label
	public void remove()
	{
		String l;
		System.out.print("Enter Description: "); //User input for label
		l = input.next();
		
		BST.remove(l);                           //Remove item in BST
		check();
	}
	
	
	
	//Display item according to label
	public void display()
	{
		String l;
		System.out.print("Enter Description: "); //User input for label
		l = input.next();
		
		BST.display(l);                          //Display all items with same label
		check();
	}
}
