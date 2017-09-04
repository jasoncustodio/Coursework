#include "types.h"
#include "user.h"
#include "date.h"

int main (int argc, char *argv[])
{
    struct rtcdate r1;
    struct rtcdate r2;
    int pid = 0;
    int hour = 0;
    int minute = 0;
    int second = 0;

    if(date(&r1))           //Get time start
    {
        printf(2, "date failed \n" ) ;
        exit();
    }
    
    pid = fork();
    if(pid > 0)             //parent exits and waits for child process to exit
    {
        pid = wait();
        if(date(&r2))       //Get time finish
        {
            printf(2, "date failed \n" ) ;
            exit();
        }
    } 
    else if(pid == 0)   //child exits
    {
        exec(argv[1], argv+2); //run the process with name located in argv[1] then pass in args
        if(date(&r2))       //Get time finish
        {
            printf(2, "date failed \n" ) ;
            exit();
        }
    } 
    else 
    {
        printf(0, "fork error\n");
    }
    
    hour = r2.hour - r1.hour;
    minute = r2.minute - r1.minute;
    
    if(r2.second > r1.second)
        second = r2.second - r1.second;
    else
        second = r1.second - r2.second;
    
    //Print elapsed time
    printf(1, "Elapsed Time: %d hours %d minutes %d seconds\n", hour, minute, second);
    exit();
}
