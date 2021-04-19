/*
https://www.geeksforgeeks.org/quick-sort/
*/
#include <stdio.h>

void print (int *arr, int len)
{
  for (int i = 0; i < len; i++)
    printf ("%d ", arr[i]);
  printf ("\n");
}

int partition (int *arr, int start, int end)
{
  int i, leftmost_greater_idx = -1, tmp;
  int pivot = arr[end];

  for (i = 0; i < end; i++) {
    if (arr[i] < pivot) {
      if (leftmost_greater_idx == -1)
        continue;
      tmp = arr[leftmost_greater_idx];
      arr[leftmost_greater_idx] = arr[i];
      arr[i] = tmp;
      leftmost_greater_idx++;
    } else {
      if (leftmost_greater_idx == -1)
        leftmost_greater_idx = i;
    }
  }

  //pivot is already in the right position
  if (leftmost_greater_idx < 0) {
    return end;
  } else {
    tmp = arr[leftmost_greater_idx];
    arr[leftmost_greater_idx] = pivot;
    arr[end] = tmp;
    return leftmost_greater_idx;
  } 
}

void qsort (int *arr, int start, int end)
{
  int pivot_idx = partition (arr, start, end);

  if (pivot_idx - 1 > start)
    qsort (arr, start, pivot_idx - 1);
  if (pivot_idx + 1 < end)
    qsort (arr, pivot_idx + 1, end);
}

void main ()
{
  int arr[] = {20, 1, 3, 4, 8, 7, 12, 2, 14, 25};
  int len = sizeof (arr) / sizeof (arr[0]);

  qsort (arr, 0, len - 1);

  print (arr, len);
}
