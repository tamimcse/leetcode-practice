/*
Reverse array in-place
*/

#include <stdio.h>

#define SIZE 11

void swap (int *a, int *b)
{
  int tmp;
  
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void inplace (int a[], int size)
{
  int i;

  for (i = 0; i < size/2; i++) {
    swap (&a[i], &a[size - 1 - i]);
  }
}

void print (int a[], int size)
{
  int i;

  for (i = 0; i < size; i++) {
    printf ("%d ", a[i]);
  }
  printf ("\n");
}

void main () {
  int a[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

  print (a, SIZE);
  inplace (a, SIZE);
  print (a, SIZE);
}
