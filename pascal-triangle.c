/*
https://www.geeksforgeeks.org/pascal-triangle/
See Method 2 for problem statement
*/
#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize){
  int arr[30][30] = {0};
  int i, j, k, m;
  for (i = 0; i < numRows; i++)
    arr[0][i] = 1;
  for (i = 0; i < numRows; i++)
    arr[i][0] = 1;
  for (i = 1; i < numRows; i++) {
    for (j = 1; j < numRows; j++) {
      arr[i][j] = arr[i-1][j] + arr[i][j-1];
    }
  }
  int **res = (int **) calloc (numRows, sizeof (*res));
  *returnSize = numRows;
  
  for (i = 0; i < numRows; i++) {
    int row = i, col = 0;
    k = 0;
    res[i] = (int *) calloc (i + 1, sizeof (int));
    while (row >= 0) {
      res[i][k++] = arr[row][col];
      row--;
      col++;
    }
  }
  return res;
}

void main ()
{
  int n = 5;
  int paslen, i, j;

  int** res = generate (n, &paslen);
  for (i = 0; i < paslen; i++) {
    printf ("[");
    for (j = 0; j <= i; j++) {
      printf ("%d ", res[i][j]);  
    }
    printf ("]  ");
  }
  printf ("\n");
}
