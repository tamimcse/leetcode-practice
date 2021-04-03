/*
https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
*/
#include <stdio.h>
#include <stdlib.h>

void matrix_chain_multiplication (int arr[], int num_matrix)
{
  int i, j, row, col, res1, res2;
  int *dp_arr = (int *) calloc (num_matrix * num_matrix, sizeof (*dp_arr));

  for (i = 0; i < num_matrix; i++) {
    dp_arr[i * num_matrix + i] = 0;
  }

  for (i = 1; i < num_matrix; i++) {
    for (col = i, row = 0; col < num_matrix; col++, row++) {
      res1 = (arr[row] * arr[col] * arr[col + 1]) + dp_arr[row * num_matrix + col - 1];
      res2 = (arr[row] * arr[row + 1] * arr[col + 1]) + dp_arr[(row + 1) * num_matrix + col];
      dp_arr[row * num_matrix + col] = res1 < res2 ? res1 : res2;
      //printf ("(%d, %d) = %d ", row, col, dp_arr[row * num_matrix + col]);
    }
    //printf ("\n");
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
