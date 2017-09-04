#include "types.h"
#include "user.h"
#include "uproc.h"

int main (int argc, char *argv[])
{
  
  int i;
  int count = 0;
  int MAX = 65;
  struct uproc table[MAX];
  
  if(setPriority(1,2) < 0)
  {
    printf(2, "setPriority failed \n");
    exit();
  }
  
  count = getprocs(MAX,table);
  
  if(count < 0)
  {
    printf(2, "getprocs failed \n" );
    exit();
  }
  
  printf(0, "PID    UID    GID    PPID    STATE    SIZE    PRIORITY    NAME\n");
  printf(0, "---    ---    ---    ----    -----    ----    --------    ----\n");
  for(i = 0; i < count; ++i)
  {
    printf(0, "%d      %d      %d      %d       %s   %d   %d           %s\n",
    table[i].pid, table[i].uid, table[i].gid, table[i].ppid, table[i].STATE, 
    table[i].size, table[i].priority, table[i].name);
  }
  
  exit();
}
