#include <stdio.h>

void convertToHex(unsigned int x);

void recover()
{	
	int start;                           //Starting place of args to previous foo stack frame
	int i, x;                            //Iterator for loop, placeholders for args a,b,c
	int count = 1;                       //Labels nmber of foo stack frames
	int fooFS = 16;                      //Foo stack frame size
	int recoverFS = 21;                  //Recover strack frame size
	int countUp = *(&start+40);          //Value of Countup from preceding foo stack frame
	
	for(i = countUp+1; i ; --i, ++count) //Start from first foo stack called
	{
		x = ((i*fooFS)+recoverFS);       //Byte offset from stack to stack

		printf("\nFoo Arguments Stack Frame: %d\n", count);
		
		printf("a: ");                   
		convertToHex(*(&start+x));		 //Takes value from foo stack address for arg a, convert to Hex
		
		printf("b: ");                   
		convertToHex(*(&start+x+1));     //Takes value from foo stack address for arg b, convert to Hex
		
		printf("c: ");                  
		convertToHex(*(&start+x+2));     //Takes value from foo stack address for arg c, convert to Hex
	}
}

void convertToHex(unsigned int x)
{
	int i;                               //Iterator for loop
	int n[10];                           //Array to hold hex values
	char c = '0';                        //Used to output with putchar
	int count = 0;                       //Counting number of hex values
	
	if(!x) putchar(c);                   //If 0, outputs 0
	
	for(x; x > 0; ++count)               //Starting from start of array, input hex values
	{
		n[count] = x%16;                 //Sets the remainder for hex value
		x = x/16;                        //Prepares for next hex value
	}
	
	for(i=count-1; i >= 0; --i)          //Start at end of array to output
	{
		if(n[i] > 9)                     //If value > 9, add 7 to go to letters
			c = ((char)'0'+n[i]+7);      //Cast int to char for putchar
		else                             //If value <= 9 use number given
			c = ((char)'0'+n[i]);        //Cast int to char for putchar
		putchar (c);                     //Output using char value
	}
	printf("\n");                        //CS201, HW3, Jason Custodio
}