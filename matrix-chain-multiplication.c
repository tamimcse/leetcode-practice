/*
https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void matrix_chain_multiplication (int arr[], int num_matrix)
{
  int i, j, row, col, res1, res2, res, k, min_res, m;
  int *dp_arr = (int *) calloc (num_matrix * num_matrix, sizeof (*dp_arr));

  for (i = 0; i < num_matrix; i++) {
    dp_arr[i * num_matrix + i] = 0;
  }

  for (i = 1; i < num_matrix; i++) {
    for (col = i, row = 0; col < num_matrix; col++, row++) {
      min_res = INT_MAX;
      for (k = row, m = 1; k < col; k++, m++) {
        res = dp_arr[row * num_matrix + k] + dp_arr[(row + m) * num_matrix + col] + arr[row] * arr[k + 1] * arr[col + 1];
        //printf ("res = %d\n", res);
        if (res < min_res)
          min_res = res;
      }
      dp_arr[row * num_matrix + col] = min_res;
      //printf ("(%d, %d) = %d ", row, col, dp_arr[row * num_matrix + col]);
    }
    printf ("\n");
  }

  printf ("Value of result is %d \n", dp_arr[num_matrix - 1]);
}

void main ()
{
  int arr[] = {40, 20, 30, 10, 30};
  //int arr[] = {10, 20, 30, 40, 30};
  //int arr[] = {10, 20, 30};
  int num_matrix = sizeof (arr) / sizeof (arr[0]) - 1;

  matrix_chain_multiplication (arr, num_matrix);
}
