/*
https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/
*/
#include <stdio.h>
#include <stdlib.h>

int cmp (const void *a, const void *b)
{
  return *((int *)a) - *((int *)b);
}

void duplet_sum (int *arr, int len, int target)
{
  int start = 0, end = len - 1;

  qsort (arr, len, sizeof (int), cmp);

  while (end > start) {
    if ((arr[start] + arr[end]) == target) {
      printf ("%d %d \n", arr[start], arr[end]);
      start++;
    } else if ((arr[start] + arr[end]) < target) {
      start++;
    } else {
      end--;
    }
  }
}

void main ()
{
  int arr[] = {-3, -5, 2, 3, 0, -1};
  int len = sizeof (arr) / sizeof (arr[0]);
  int target = -1;

  duplet_sum (arr, len, target);  
}
