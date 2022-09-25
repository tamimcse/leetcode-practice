/*
https://www.geeksforgeeks.org/merge-sort/
*/
#include <stdio.h>


void merge_sort (int arr[], int start, int end)
{
  int i, j, k, tmp, to_insert;
  if (start == end)
    return;
  int mid = (start + end) >> 1;
  merge_sort (arr, start, mid);
  merge_sort (arr, mid + 1, end);
  //now merge two arrays in place!!!!
  for (i = end; i >= mid + 1; i--) {
    if (arr[i] < arr[mid]) {
      tmp = arr[i];
      arr[i] = arr[mid];
      arr[mid] = tmp;
      //insert arr[mid] in sorted manner like insertion sort
      to_insert = arr[mid];
      for (j = mid - 1; j >= start; j--) {
        if (arr[j] > to_insert) {
          arr[j + 1] = arr[j];
        } else {
          break;
        }
      }
      arr[j+1] = to_insert;
    }
  }
}

void main ()
{
  int arr[] = {10, 13, 2, 4, 5, 1, 3, 12, 14, 16, 17, 2};
  int len = sizeof (arr) /sizeof (arr[0]);

  merge_sort (arr, 0, len - 1);

  for (int i = 0; i < len; i++) {
    printf ("%d ", arr[i]);
  }
  printf ("\n");
}
