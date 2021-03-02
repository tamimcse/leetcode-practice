/*
Insertion sort
*/
#include <stdio.h>

void swap (int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void bubble_sort (int arr[], int len)
{
  int i, j;

  for (j = len; j >= 1; j--) {
    for (i = 1; i < j; i++) {
      if (arr[i] < arr[i - 1])
        swap (&arr[i], &arr[i - 1]);
    }
  }
}

void print (int arr[], int len)
{
  int i;

  for (i = 0; i < len; i++) {
    printf ("%d ", arr[i]);
  }
  printf ("\n");
}

void main ()
{
  int arr [] = {10, 90, 85, 80, 70, 60, 40, 50, 30, 20};
  int len = sizeof (arr) / sizeof (arr[0]);

  bubble_sort (arr, len);
  print (arr, len);
}
