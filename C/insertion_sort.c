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

  for (i = 1; i < len; i++) {
    if (arr[i] < arr[i - 1]) {
      int to_insert = arr[i];
      for (j = i - 1; j >= 0 && (arr[j] > to_insert); j--) {
        arr[j + 1] = arr[j];
      }
      arr[j + 1] = to_insert;
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
