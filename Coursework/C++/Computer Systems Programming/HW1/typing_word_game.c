/*
    Program:     Typing Speed Game
    Author:      Jason Custodio
    Class:       CS201
    Date:        10/13/2014
    Description: This program simulates a typing speed game
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

struct timeval before, after, result;
#define MAX 10                                                 //Max array size for user input

int main()
{
	int i, random;                                         //Values to increment and hold index of array of strings
        char input[MAX];                                       //Array of char to hold user input
        char * temp;                                           //Used to make sure each possible word is used once
	char * list[] = {"The", "quick", "brown", "fox",       //Array of strings used to hold word bank 
                         "jumps", "over", "the", "lazy", "dog"}; 
	
	printf("\n\nType the following words as fast as possible!\n\n");
	
	gettimeofday(&before, NULL);                           //Call function for timeval struct
	srand(before.tv_usec);                                 //Seed srand to get time values
	
	for (i=0; i<9; ++i)
	{
		random = rand()%(9-i);                         //Used to  make sure words are randomized and used once
		
		printf("Word #%d is %s: ", i+1, list[random]); //Displays word to spell
		scanf("%29s", input);                          //User tries to spell word
		
		                                               //Error catch to make sure user inputs correct word
		while (strncmp(list[random], input, strlen(list[random])) || strlen(list[random]) < strlen(input))
		{
			printf("\n\nIncorrect!\n\n");
			printf("Word #%d is %s: ", i+1, list[random]);
			scanf("%29s", input);
		}
		
		temp = list[8-i];                              //Hold last element used
		list[8-i] = list[random];                      //Random word
		list[random] = temp;                           //Swap
	}

	gettimeofday(&after, NULL);                            //Call function for timeval struct
	timersub(&after, &before, &result);                    //Result = after - before
	
	printf("\n\nFINISHED! Your time is: %ld sec %ld usec\n\n", result.tv_sec, result.tv_usec);
	
	return 0;
}
