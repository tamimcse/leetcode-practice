/*
https://www.geeksforgeeks.org/maximum-minimum-values-algebraic-expression/

Here, we assume that 1 <= n,m <= 10. 1 <= X_i, Y_i <= 10

Note that, this is not a DP problem. You can use backtracking to fill up the array. Then use the prescribed method to calculate the maximum.
*/
#include <stdio.h>

#define MAX 5

#define TOTAL_SUM (MAX*(MAX+1)>>1)

int max_algebric_expr (int arr[], int m, int n)
{
  int i, j, sum = 0;

  for (i = 0; i < m + n; i++)
    sum += arr[i];

  //precomputed 2D array.
  char *arr = (char *) calloc (MAX * TOTAL_SUM, sizeof (*arr));

  for (i = 0; i < MAX; i++)
    arr[i] = 1;

  for () {

  }
}

void main ()
{
  int m = 3, n = 2;
  int arr[] = {1, 2, 3, 4, 5};
  int res = 
}

