/*
Program to print patterns

For n=3 (so I had to write code for general n)
    *
  *    *
*        * 
  *    *
    *

Asked at berrucuda network
*/
#include <stdio.h>
#include <stdlib.h>

enum dir {BOTTOM_RIGHT, BOTTOM_LEFT, TOP_LEFT, TOP_RIGHT};

void pyramid (int n)
{
  int row = 0, col = n - 1, arr_size = (n << 1) - 1;
  int *arr = (int *) calloc (arr_size * arr_size, sizeof (*arr));
  enum dir d = BOTTOM_RIGHT;
  
  do {
    arr[row * arr_size + col] = 1;
    if (d == BOTTOM_RIGHT) {
      row++;
      if (col == arr_size - 1) {
        col--;
        d = BOTTOM_LEFT;
      } else {
        col++;
      }
    } else if (d == BOTTOM_LEFT) {
      col--;
      if (row == arr_size - 1) {
        row--;
        d = TOP_LEFT;
      } else {
        row++;
      }
    } else if (d == TOP_LEFT) {
      row--;
      if (col == 0) {
        col++;
        d = TOP_RIGHT;
      } else {
        col--;
      }
    } else if (d == TOP_RIGHT) {
      row--;
      col++;
    }
  } while (row != 0);

  for (row = 0; row < arr_size; row++) {
    for (col = 0; col < arr_size; col++) {
      printf ("%c", arr[row * arr_size + col] ? '*' : ' ');
    }
    printf ("\n");
  }
}

void main ()
{
  int n = 5;
  pyramid (n);
}
