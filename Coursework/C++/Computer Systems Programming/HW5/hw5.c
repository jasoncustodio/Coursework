/*
    Program:     Dork Math
    Author:      Jason Custodio
    Class:       CS201
    Date:        12/03/2014
    Description: Arithmetic calculator for Dork Math    
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node         //Used to manage DorkDigits
{
    char dork;              //DorkDigit
    int decimal;            //Int value
    struct node * next;     //Pointer to next node for LLL
    struct node * previous; //Pointer to next node for LLL
}   node; 

void fileCheck(FILE * fp);                                           //Checks for file errors
void print(node * head);                                             //Print all values in list 
int  input(FILE * fp, int * a, int * b, int * c, char * check);      //Reads from file
void insert(node ** head, node ** tail, int dork, int decimal);      //Insert at end of list
void insertFront(node ** head, node ** tail, int dork, int decimal); //Insert at front of list

int main(int argc, char * argv[])
{
    FILE * fp;             //File to open 
    char check = 0;        //Value to compare
    int option;            //For input
    int carryFlag = 0;     //Check for carries rom addition
    int a = 0;             //Hold odd DorkDigit              
    int b = 0;             //Hold first DorkDigit
    int c = 0;             //Hold second DorkDigit
    //int oddFlag = 0;      //Check for odd digit
    
    int sumDork;           //Sum list's dorkdigit
    int sumDecimal;        //Sum list's decimal
    
    node * temp1 = NULL;   //Used to manipulate list
    node * temp2 = NULL;   //Used to manipulate list
    
    node * head1 = NULL;   //Head pointer to first operand
    node * tail1 = NULL;   //Tail pointer to first operand
    
    node * head2 = NULL;   //Head pointer to second operand
    node * tail2 = NULL;   //Tail pointer to second operand
    
    node * sumHead = NULL; //Head pointer to sum
    node * sumTail = NULL; //Tail pointer to sum
    
    int array[32] = {[0 ... 31] = -1};     //Lookup array for decimals
    array[ 9] =  0;                        //01001
    array[14] =  1;                        //01110
    array[19] =  2;                        //10011
    array[15] =  3;                        //01111
    array[ 2] =  4;                        //00010
    array[31] =  5;                        //11111
    array[22] =  6;                        //10110
    array[27] =  7;                        //11011
    array[12] =  8;                        //01100
    array[ 4] =  9;                        //00100
    array[17] = 10;                        //10001
    array[ 6] = 11;                        //00110
    array[25] = 12;                        //11001
    
    int arrayDork[32] = {[0 ... 31] = -1}; //Lookup array for dorkdigits
    arrayDork[ 0] =  9;                    //01001
    arrayDork[ 1] = 14;                    //01110
    arrayDork[ 2] = 19;                    //10011
    arrayDork[ 3] = 15;                    //01111
    arrayDork[ 4] =  2;                    //00010
    arrayDork[ 5] = 31;                    //11111
    arrayDork[ 6] = 22;                    //10110
    arrayDork[ 7] = 27;                    //11011
    arrayDork[ 8] = 12;                    //01100
    arrayDork[ 9] =  4;                    //00100
    arrayDork[10] = 17;                    //10001
    arrayDork[11] =  6;                    //00110
    arrayDork[12] = 25;                    //11001
    
    //Look up table for adding decimals base 13
    int table[13][13] =  {{ 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12},
                          { 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12,  0},
                          { 2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12,  0,  1},
                          { 3,  4,  5,  6,  7,  8,  9, 10, 11, 12,  0,  1,  2},
                          { 4,  5,  6,  7,  8,  9, 10, 11, 12,  0,  1,  2,  3},
                          { 5,  6,  7,  8,  9, 10, 11, 12,  0,  1,  2,  3,  4},
                          { 6,  7,  8,  9, 10, 11, 12,  0,  1,  2,  3,  4,  5},
                          { 7,  8,  9, 10, 11, 12,  0,  1,  2,  3,  4,  5,  6},
                          { 8,  9, 10, 11, 12,  0,  1,  2,  3,  4,  5,  6,  7},
                          { 9, 10, 11, 12,  0,  1,  2,  3,  4,  5,  6,  7,  8},
                          {10, 11, 12,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9},
                          {11, 12,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10},
                          {12,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11}};
    
    //Look up table for adding decimals base 13 (WITH CARRY OVER)
    int table2[13][13] = {{ 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12,  0},
                          { 2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12,  0,  1},
                          { 3,  4,  5,  6,  7,  8,  9, 10, 11, 12,  0,  1,  2},
                          { 4,  5,  6,  7,  8,  9, 10, 11, 12,  0,  1,  2,  3},
                          { 5,  6,  7,  8,  9, 10, 11, 12,  0,  1,  2,  3,  4},
                          { 6,  7,  8,  9, 10, 11, 12,  0,  1,  2,  3,  4,  5},
                          { 7,  8,  9, 10, 11, 12,  0,  1,  2,  3,  4,  5,  6},
                          { 8,  9, 10, 11, 12,  0,  1,  2,  3,  4,  5,  6,  7},
                          { 9, 10, 11, 12,  0,  1,  2,  3,  4,  5,  6,  7,  8},
                          {10, 11, 12,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9},
                          {11, 12,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10},
                          {12,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11},
                          { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12}};
    
    //Lookup table for carries
    int carry[13][13] =   {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
                           {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
                           {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
                           {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
                           {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                           {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                           {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                           {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
     
    //Lookup table for carries (WITH CARRY OVER)    
    int carry2[13][13] =  {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
                           {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
                           {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
                           {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
                           {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                           {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                           {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                           {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                           {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    
    /*
    if (*argv[argc-2] == 'a')
        printf("\nADDITION\n");
    
    if (*argv[argc-2] == 's')
         printf("\nSUBTRACTIONn");
    
    if (*argv[argc-2] == 'm')
         printf("\nMULTIPLICATION\n");
    */
  
    fp = fopen(argv[argc-1], "r"); //File to open 
    fileCheck(fp);                 //File error checking
    
    while(check != -1)
    {
        ////////////////////////Input/////////////////////////
        do
        {
            option = input(fp, &a, &b, &c, &check);
            if(option == -4)
            {
                fprintf(stderr,"\nRead Error\n");
                //return -4;
            }
            if(option == 1)
                insert(&head1, &tail1, a, array[a]);
            if(option == 2)
            {
                insert(&head1, &tail1, b, array[b]);
                insert(&head1, &tail1, c, array[c]);
            }
            a = b = c = 0;
        }   while(check == ',');
    
        do
        {
            option = input(fp, &a, &b, &c, &check);
            if(option == -4)
            {
                fprintf(stderr,"\nRead Error\n");
                //return -4;
            }
            if(option == 1)
                insert(&head2, &tail2, a, array[a]);
            if(option == 2)
            {
                insert(&head2, &tail2, b, array[b]);
                insert(&head2, &tail2, c, array[c]);
            }
            a = b = c = 0;
        }   while(check == ',');
        ///////////////////////////Addition//////////////////////////
        temp1 = tail1; 
        temp2 = tail2;
        
        while(temp1 != NULL || temp2 != NULL) 
        {
            if(carryFlag == 0)
            {
                if(temp1 == NULL)
                {
                    sumDecimal = table[0][temp2->decimal];
                    carryFlag = carry[0][temp2->decimal];
                    //oddFlag = 1;
                }
                else if(temp2 == NULL)
                {
                    sumDecimal = table[temp1->decimal][0];
                    carryFlag = carry[temp1->decimal][0];
                    //oddFlag = 1;
                }
                else
                {
                    sumDecimal = table[temp1->decimal][temp2->decimal];
                    carryFlag = carry[temp1->decimal][temp2->decimal];
                }   
                sumDork = arrayDork[sumDecimal];
                insertFront(&sumHead, &sumTail, sumDork, sumDecimal);    
            }
            else if(carryFlag == 1)
            {
                if(temp1 == NULL)
                {
                    sumDecimal = table2[0][temp2->decimal];
                    carryFlag = carry2[0][temp2->decimal];
                    //oddFlag = 1;             
                }
                else if(temp2 == NULL)
                {
                    sumDecimal = table2[temp1->decimal][0];
                    carryFlag = carry2[temp1->decimal][0];
                    //oddFlag = 1;
                }
                else
                {
                    sumDecimal = table2[temp1->decimal][temp2->decimal];
                    carryFlag = carry2[temp1->decimal][temp2->decimal];
                }

                sumDork = arrayDork[sumDecimal];
                insertFront(&sumHead, &sumTail, sumDork, sumDecimal);
            }
            
            if(temp1 != NULL)
                temp1 = temp1->previous;
            if(temp2 != NULL)
                temp2 = temp2->previous;
        }
        ///////////////////////Output////////////////////////////
        temp1 = sumHead;
        temp2 = sumHead->next;
        printf("\n\n");
  
        while(temp1 != NULL || temp2->next != NULL)
        {   
        /*  if(oddFlag == 1)
            {
                if(temp1->dork &  (1<<4))
                    printf("1");
                else printf("0");
                if(temp1->dork &  (1<<3))
                    printf("1");
                else printf("0");
                if(temp1->dork &  (1<<2))
                    printf("1");
                else printf("0");
                if(temp1->dork &  (1<<1))
                    printf("1");
                else printf("0");
                if(temp1->dork &  (1<<0))
                    printf("1");
                else printf("0");
                oddFlag = 2;
                temp1=temp1->next;
                temp2=temp2->next;
            }
         */
            if(temp1->dork &  (1<<4))
                printf("1");
            else printf("0");
        
            if(temp2->dork &  (1<<4))
                printf("1");
            else printf("0");
        
            if(temp1->dork &  (1<<3))
                printf("1");
            else printf("0");
        
            if(temp2->dork &  (1<<3))
                printf("1");
            else printf("0");
        
            if(temp1->dork &  (1<<2))
                printf("1");
            else printf("0");
        
            if(temp2->dork &  (1<<2))
                printf("1");
            else printf("0");
        
            if(temp1->dork &  (1<<1))
                printf("1");
            else printf("0");
        
            if(temp2->dork &  (1<<1))
                printf("1");
            else printf("0");
        
            if(temp1->dork &  (1<<0))
                printf("1");
            else printf("0");
        
            if(temp2->dork &  (1<<0))
                printf("1");
            else printf("0");
            
            if(temp2->next != NULL)
                printf(",");
                
           if(temp1->next != NULL)
                temp1 = temp1->next->next;
            if(temp2->next != NULL)
                temp2 = temp2->next->next;
        }
        head1   = NULL;
        tail1   = NULL;
        head2   = NULL;
        tail2   = NULL;
        sumHead = NULL;
        sumTail = NULL;
        printf("\n\n");
    }  
    printf("\n\n");
    fclose(fp);
    return 0;
}

void fileCheck(FILE * fp)
{
    long size = 0;                       //Buffer size
    
    if(!fp)                              //Error Check
    {   
        fprintf(stderr,"\nError\n");
        exit(-1);                                
    }
    if (fseek(fp, 0L, SEEK_END) == 0)    //Go to end of file
    {
        size = ftell(fp);                //Get size of file
        if(size == -1)                   //Error Check
        {
            fprintf(stderr,"\nError\n");
            exit(-2);   
        }
        if(fseek(fp, 0L, SEEK_SET) != 0) //Error check
        {
            fprintf(stderr,"\nError\n");
            exit(-3); 
        }
    }    
}

void insert(node ** head, node ** tail, int dork, int decimal)
{
    node * temp;
    temp = (node *)malloc(sizeof(node));
    
    temp->dork = dork;
    temp->decimal = decimal;
    temp->next = NULL;
    temp->previous = *tail;

    if(*head == NULL)
    {
        *head = temp;
        *tail = temp;
    }
    else
    {
        (*tail)->next = temp;
        *tail = (*tail)->next;
    }
}

void insertFront(node ** head, node ** tail, int dork, int decimal)
{
    node * temp;
    temp = (node *)malloc(sizeof(node));
    
    temp->dork = dork;
    temp->decimal = decimal;
    temp->next = *head;
    temp->previous = NULL;

    if(*head == NULL)
    {
        *head = temp;
        *tail = temp;
    }
    else
    {
        (*head)->previous = temp;
        *head = (*head)->previous;
    }
}

void print(node * head)
{
    node * temp;
    
    for(temp = head; temp != NULL; temp = temp->next)
    {
        printf("\nDork:    %d", temp->dork);
        printf("\nDecimal: %d \n", temp->decimal);
    }
}

int input(FILE * fp, int * a, int * b, int * c, char * check)
{
    //////////////////////////////////(1) 
    *check = fgetc(fp);         
    if(*check == '1')
    {
        *a |= (1<<4);
        *b |= (1<<4);
    }
    else if(*check == '0'){}
    else return -4;
    //////////////////////////////////(2)
    *check = fgetc(fp);
    if(*check == '1')
    {
        *a |= (1<<3);
        *c |= (1<<4);
    }
    else if(*check == '0'){}
    else return -4;
    //////////////////////////////////(3)
    *check = fgetc(fp);
    if(*check == '1')
    {
        *a |= (1<<2);
        *b |= (1<<3);
    }
    else if(*check == '0'){}
    else return -4;
    //////////////////////////////////(4)
    *check = fgetc(fp);
    if(*check == '1')
    {
        *a |= (1<<1);
        *c |= (1<<3);
    }
    else if(*check == '0'){}
    else return -4;
    //////////////////////////////////(5)
    *check = fgetc(fp);
    if(*check == '1')
    {
        *a |= (1<<0);
        *b |= (1<<2);
    }
    else if(*check == '0'){}
    else return -4;
    //////////////////////////////////(6)
    *check = fgetc(fp);
    if(*check == ',' || *check == '\n')
        return 1;
    if(*check == '1')
        *c |= (1<<2);
    else if(*check == '0'){}
    else return -4;
    //////////////////////////////////(7)
    *check = fgetc(fp);
    if(*check == '1')
        *b |= (1<<1);
    else if(*check == '0'){}
    else return -4;
    //////////////////////////////////(8)
    *check = fgetc(fp);
    if(*check == '1')
        *c |= (1<<1);
    else if(*check == '0'){}
    else return -4;
    //////////////////////////////////(9)
    *check = fgetc(fp);
    if(*check == '1')
        *b |= (1<<0);
    else if(*check == '0'){}
    else return -4;
    /////////////////////////////////(10)
    *check = fgetc(fp);
    if(*check == '1')
        *c |= (1<<0);       
    else if(*check == '0'){}
    else return -4;

    *check = fgetc(fp);
    return 2;
}
