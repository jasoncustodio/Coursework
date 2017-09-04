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

public class CS202HW4 
{
	static final int EXIT = 4;                     //Used in switch statement to exit program
	static Scanner input = new Scanner(System.in); //Used for all input
	
	public static void main(String[] args) 
	{
		Menu myMenu = new Menu();                  //Help with interface
		int choice = 0;                            //Choice for interface
		
		myMenu.welcome();                          //Welcomes user
		do
		{
			myMenu.space();                        //Clean output buffer
		    choice = myMenu.displayInterface();    //Calls interface function to display user interface
		    myMenu.space();                        //Clean output buffer

            switch (choice)                        //Switch statement with 4 commands
	        {
            	case 1:                            //Add Item to BST
		        {
		        	myMenu.add();
		        }break;

		        case 2:                            //Remove Item from BST according to label
		        {
		        	myMenu.remove();
		        }break;
		            
                case 3:                            //Display Item from BST according to label
	            {
	            	myMenu.display(); 
	            }break;

		        default:break;
		     }
		}while (choice!=EXIT);                    //Exit program	  
	}
}
	