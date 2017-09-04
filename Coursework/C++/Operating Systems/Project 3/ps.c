#include "types.h"
#include "user.h"
#include "uproc.h"

int main (int argc, char *argv[])
{
  
  int i;
  int count = 0;
  int MAX = 65;
  struct uproc table[MAX];
  count = getprocs(MAX,table);
  
  if(count < 0)
  {
    printf(2, "getprocs failed \n" );
    exit();
  }
  
  for(i = 0; i < count; ++i)
  {
    printf(0, "PID:%d  UID:%d  GID:%d  PPID:%d  STATE:%s  SIZE:%d  NAME:%s\n",
		table[i].pid, table[i].uid, table[i].gid, table[i].ppid, table[i].STATE, table[i].size, table[i].name);
  }
  
  exit();
}
