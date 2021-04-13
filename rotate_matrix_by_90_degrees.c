/*
https://www.geeksforgeeks.org/turn-an-image-by-90-degree/

https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/
*/
#include <stdio.h>
#include <stdlib.h>

int* rotate (int *mat, int N)
{
  int i, j, m, n, extra;
  int *res = (int *) calloc (N * N, sizeof (*res));

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      m = N - 1 - j;
      n = i;
      res[m * N + n] = mat[i * N + j];
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
  int N = 4;
  int *mat = (int *)malloc(N * N * sizeof (*mat));
  int *res;
  int i, j, cur;

  for (i = 0, cur = 1; i < N; i++) {
    for (j = 0; j < N; j++) {
      mat[i * N + j] = cur++;
    }
  }  

  printf ("Original matrix = \n");
  print (mat, N);

  res = rotate (mat, N);

  printf ("Result matrix = \n");
  print (res, N);
}

