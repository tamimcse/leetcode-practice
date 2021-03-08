/*
Count all possible paths from top left to bottom right:

The task is to count all the possible paths from top left to bottom right of a m X n matrix with the constraints that from each cell you can either move only to right or down.

Input: m = 2, n = 2
Output: 2 
Explanation: Two possible ways are
RD and DR. 

Input: m = 3, R = 3
Output: 6
Explanation: Six possible ways are
RRDD, DDRR, RDDR, DRRD, RDRD, DRDR. 
*/
#include <stdio.h>

int count_paths (int n, int m)
{
  if (n == 1 && m == 1)
    return 0;
  if (n > 2 && m > 2)
    return count_paths (n - 1, m - 1) + 2;
  else if (n > 1)
    return count_paths (n - 1, m) + 1;
  else if (m > 1)
    return count_paths (n, m - 1) + 1;
  else
    printf ("Shouldn't come here");
}

void main ()
{
  int n = 3, m = 3;

  int count = count_paths (n, m);
  printf ("Number of paths for %d x %d rectangle is %d\n", n, m, count);
}
