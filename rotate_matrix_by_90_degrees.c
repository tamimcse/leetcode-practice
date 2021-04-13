/*
https://www.geeksforgeeks.org/turn-an-image-by-90-degree/

https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/
*/
#include <stdio.h>

int* rotate (int *mat, int N)
{
  int i, j, m, n, extra;
  int *res = (int *) calloc (N * N, sizeof (*res));

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      extra = (i + N - 1) % N;
      m = (i + N - 1) >= N ? (i + N - 1);
      n = j + extra;
      res [m * N + n] = mat[i * N + j]; 
    }
  }
  return res;
}

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
  int *res;

  print (mat, 4);
  res = rotate (mat, 4);
  print (res, 4);
}

