/*
https://www.geeksforgeeks.org/backtracking-to-find-all-subsets/
*/
#include <stdio.h>

void subset (int *arr, int len)
{
  int i, count;
  
  for (i = 0, count = 0; i < len; i++) {
    if (arr[i] != -1) {
      printf ("%d ", arr[i]);
      count++;
    }
  }
  printf ("\n");

  if (count == 1)
    return;

  for (i = 0; i < len; i++) {
    if (arr[i] != -1) {
      int tmp = arr[i];
      arr[i] = -1;
      subset (arr, len);
      arr[i] = tmp;
    }
  }
}

void main ()
{
  int arr[] = {1, 2, 3}; 
  int len = sizeof (arr) / sizeof (arr[0]);

  subset (arr, len);
}
