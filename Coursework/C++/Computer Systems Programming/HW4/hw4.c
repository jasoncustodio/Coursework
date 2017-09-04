/*
    Program:     Decryption
    Author:      Jason Custodio
    Class:       CS201
    Date:        11/24/2014
    Description: Decrypts a hidden message from a file
              
*/

#include <stdio.h>
#include <stdlib.h>

void step2(char * a);
void step1(char * a, char * b);

int main(int argc, char * argv[])
{
    int i = 0;                                        //Main iterator through array
    int j = 0;                                        //Secondary iterator for step 1
    long size = 0;                                    //Buffer size
    size_t check = 0;                                 //File Error Check
    char * array = NULL;                              //Dynamic array for file input
    FILE * fp = fopen(argv[argc-1], "r");             //File to open "cus" or "cus2"
    
    
    
    if(!fp)                                           //Error Check
    {   
        fprintf(stderr,"\nError\n");
        return -1;                                
    }
    
    if (fseek(fp, 0L, SEEK_END) == 0)                 //Go to end of file
    {
        size = ftell(fp);                             //Get size of file
        
        if(size == -1)                                //Error Check
        {
            fprintf(stderr,"\nError\n");
            return -2;   
        }

        array = malloc(sizeof(char) * (size + 1));    //Allocate buffer to size

        if(fseek(fp, 0L, SEEK_SET) != 0)              //Error check
        {
            fprintf(stderr,"\nError\n");
            return -3; 
        }
        
        check = fread(array, sizeof(char), size, fp); //Read whole file into memory.
        
        if(check == 0)                                //Error Check
        {
            fprintf(stderr,"\nError\n");
            return -4;
        }
        else array[++check] = '\0';                   //For safety 
        fclose(fp);
    }
    
    for(i=0, j=3; i < size && j < size; i+=4, j+=4)   //Step 1, swap 1st and 4th byte
        step1(&array[i], &array[j]);                  //Swap every 4 byte blocks
    
    for(i = 0; i < size; ++i)                         //Step 2, swap bits 1,3 and 0,2
        step2(&array[i]);                             //Swap for every byte
        
    for(i = 2; i < size; i+=4)                        //Step 3 Exlusive or every 4 bytes
    {
        array[i] ^= 's';                              //Exclusive or with key 's' 3rd byte
        array[i+1] ^= 's';                            //Exclusive or with key 's' 4th byte
    }
        
    printf("\n\n");
    for(i = 0; i < size; ++i)                         //Print secret message
        printf("%c", array[i]);
    printf("\n\n");
    
    free(array);                                      //Deallocate dynamic array
    return 0;  
}

void step1(char * a, char * b)                        //Swap bytes
{
    char temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

void step2(char * a)                                  //Swap bits
{
    int i;                                               
    char temp;
    temp = *a;
    
    for(i = 0; i < 4; ++i)                            
    {
        if(i < 2)                                    //Check for which arithmetic
        {
            if(temp &  (1<<i))                       //Check if bit is 0 or 1
                 *a |= (1<<(i+2));                   //Set compared bit to 1
            else *a &= (~(1<<(i+2)));                //Set compared bit to 0
        }
        else
        {
            if(temp &  (1<<i))                       //Check if bit is 0 or 1
                 *a |= (1<<(i-2));                   //Set compared bit to 1
            else *a &= (~(1<<(i-2)));                //Set compared bit to 0
        }
    }
}
