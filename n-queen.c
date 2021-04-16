/*
https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/
*/
#include <stdio.h>
#include <stdlib.h>

int is_valid_location (int *arr, int n, int row, int col)
{
  int i, j;
  
  if (arr[row * n + col])
    return 0;

  for (j = 0; j < n; j++) {
    if (arr[row * n + j])
      return 0;
  }

  for (i = 0; i < n; i++) {
    if (arr[i * n + col])
      return 0;
  }

  //right-down diagonal
  i = row + 1;
  j = col + 1;
  while (i < n && j < n) {
    if (arr[i * n + j])
      return 0;
    i++;
    j++;
  }

  //left-up diagonal
  i = row - 1;
  j = col - 1;
  while (i >= 0 && j >= 0) {
    if (arr[i * n + j])
      return 0;
    i--;
    j--;
  }

  //right-up diagonal
  i = row - 1;
  j = col + 1;
  while (i >= 0 && j < n) {
    if (arr[i * n + j])
      return 0;
    i--;
    j++;
  }

  //left-down diagonal
  i = row + 1;
  j = col - 1;
  while (i < n && j >= 0) {
    if (arr[i * n + j])
      return 0;
    i++;
    j--;
  }

  return 1;
}

int n_queen_inner (int *arr, int n, int col)
{
  int row, idx, i, j, res;

  if (col == n) {
    printf ("Chess box = \n");
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        printf ("%d ", arr[i * n + j]);
      }
      printf ("\n");
    }
    return 0;
  }

  for (row = 0; row < n; row++) {
    if (!is_valid_location(arr, n, row, col))
      continue;
    arr[row * n + col] = 1;
    res = n_queen_inner (arr, n, col + 1);
    if (!res)
      return 0;
    arr[row * n + col] = 0;
  }
  return -1;
}

void n_queen (int n)
{
  int *res = (int *)calloc (n * n, sizeof (*res));
  n_queen_inner (res, n, 0);
}

void main ()
{
  int n = 8;

  n_queen (n);
}
