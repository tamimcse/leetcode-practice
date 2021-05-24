/*
https://leetcode.com/problems/set-matrix-zeroes/

https://www.geeksforgeeks.org/a-boolean-matrix-question/
*/



void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
  int i, j, col_num = matrixColSize[0];
  int *row = (int *) calloc (matrixSize, sizeof (*row));
  int *col = (int *) calloc (col_num, sizeof (*col));
  
  for (i = 0; i < matrixSize; i++) {
    for (j = 0; j < col_num; j++) {
      if (!matrix[i][j]) {
        row[i] = 1;
        col[j] = 1;
      }
    }
  }
  
  for (i = 0; i < matrixSize; i++) {
    if (row[i]) {
      for (j = 0; j < col_num; j++) {
        matrix[i][j] = 0;
      }
    }
  }
  
  for (i = 0; i < col_num; i++) {
    if (col[i]) {
      for (j = 0; j < matrixSize; j++) {
        matrix[j][i] = 0;
      }
    }
  }
}
