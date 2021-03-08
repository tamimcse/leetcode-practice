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
#include <stdlib.h>

int count_paths (int n, int m)
{
  if (m == 1 || n == 1) 
    return 1;
  return count_paths(m - 1, n) + count_paths(m, n - 1); 
}

int count_paths_iterative (int n, int m)
{
  int i, j, res;
  int *arr = (int *) calloc (n * m, sizeof (*arr));

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (i == 0 || j == 0)
        arr [i * n + j] = 1;
      else
        arr [i * n + j] = arr [(i - 1) * n + j] + arr [i * n + (j - 1)];
    }
  }
  res = arr [(n - 1) * n + (m - 1)];
  free (arr);
  return res;
}

void main ()
{
  int n = 6, m = 5;

  int count = count_paths (n, m);
  int count1 = count_paths_iterative (n, m);
  printf ("Number of paths for %d x %d rectangle is %d DP result %d\n", n, m, count, count1);
}
