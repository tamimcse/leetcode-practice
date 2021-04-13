/*
https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/
*/
#include <stdio.h>

void print (int *mat, int N)
{
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf ("%d ", mat[i * N + j]);
    }
    printf ("\n");
  }
}

void main ()
{
  int mat[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

  print (mat, 4);
}

