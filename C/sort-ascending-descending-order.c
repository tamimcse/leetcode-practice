/*
https://www.geeksforgeeks.org/sort-first-half-in-ascending-and-second-half-in-descending-order/
*/
#include <stdio.h>
#include <stdlib.h>

int cmp (const void *a, const void *b)
{
  return *((int *)a) - *((int *)b);
}

int cmp_alt (const void *a, const void *b)
{
  return *((int *)b) - *((int *)a);
}


void sort_ascending_descing (int arr[], int len)
{
  int largest_idx, i, mid_idx = len >> 1, tmp;

  largest_idx = 0; 
  for (i = 1; i < len; i++) {
    if (arr[i] > arr[largest_idx]) {
      largest_idx = i;
    }
  }

  //swap mid point and largest_idx
  tmp = arr[mid_idx];
  arr[mid_idx] = arr[largest_idx];
  arr[largest_idx] = tmp;

  qsort (arr, mid_idx, sizeof (int), cmp);
  qsort (arr + mid_idx + 1, len - mid_idx - 1, sizeof (int), cmp_alt);
}

void main ()
{
  int arr[] = {5, 7, 15, 2, 4, 18, 20, 1, 9};
  int len = sizeof (arr) / sizeof (arr[0]);

  sort_ascending_descing (arr, len);

  for (int i = 0; i < len; i++) {
    printf ("%d ", arr[i]);
  }
  printf ("\n");
}
