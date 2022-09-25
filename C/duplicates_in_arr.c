/*
https://www.geeksforgeeks.org/find-duplicates-in-on-time-and-constant-extra-space/

One approach use to use hash. But, if not extra space is allowed, we can use the given array as hash
*/
#include <stdio.h>

#define ABS(X) (X >= 0) ? X : -X

void print (int *arr, int len)
{
  int i;

  for (i = 0; i < len; i++) {
    printf ("%d ", arr[i]);
  }
  printf ("\n");
}

void print_duplicates (int *arr, int len)
{
  int i;

  for (i = 0; i < len; i++) {
    //haven't seen
    if (arr[ABS(arr[i])] >= 0)
      arr[ABS(arr[i])] = -arr[ABS(arr[i])];
    else
      printf ("%d ", ABS(arr[i]));
  }
  printf ("\n");
}



void main ()
{
  int arr[] = {2, 3, 3, 1, 2, 5, 5};
  int arr_len = sizeof (arr) / sizeof (arr[0]);

  print_duplicates (arr, arr_len);

  print (arr, arr_len);
}
