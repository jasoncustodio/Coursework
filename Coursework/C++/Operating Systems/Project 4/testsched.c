// Test program for CS333 scheduler, project 4.

#include "types.h"
#include "user.h"

// We currently have 3 priority levels
#define PrioCount 3
#define numChildren 10

void
countForever(int p)
{
  int j;
  unsigned long count = 0;

  j = getpid();
  p = p%PrioCount;
  setPriority(j, p);
  printf(1, "%d: start prio %d\n", j, p);

  while (1) {
    count++;
    if ((count & 0xFFFFFFF) == 0) {
      p = (p+1) % PrioCount;
      setPriority(j, p);
      printf(1, "%d: new prio %d\n", j, p);
    }
  }
}

int
main(void)
{
  int i, rc;

  for (i=0; i<numChildren; i++) {
    rc = fork();
    if (!rc) { // child
      countForever(i);
    }
  }
  // what the heck, let's have the parent waste time as well!
  countForever(1);
  exit();
}
