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

void rotate_inplace (int *mat, int N)
{
  int i, j, m, n, extra, start = 1, end = N - 1, circle = 0, tmp, tmp1, row, col;

  while (end >= start) {
    for (i = start; i <= end; i++) {
      row = circle;
      col = i;
      tmp = mat[row * N + col];
      while (1) {
        m = N - 1 - col;
        n = row;
        tmp1 = mat[m * N + n];
        mat[m * N + n] = tmp;
        tmp = tmp1;
        row = m;
        col = n;
        //circle finished
        if (row == circle && col == i)
          break;
      }
    }
    start++;
    end--;
    circle++;
  }
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
  int N = 6;
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

  rotate_inplace (mat, N);
  printf ("Result of rotate inplace = \n");
  print (mat, N);
}

