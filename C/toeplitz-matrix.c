/*
https://leetcode.com/problems/toeplitz-matrix/
*/


bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize){
  int num_row = matrixSize, num_col = matrixColSize[0];
  int row, col, num, tmp_row, tmp_col;
  for (row = 0, col = 0; col < num_col; col++) {
    num = matrix[row][col];
    tmp_row = row;
    tmp_col = col;
    while (tmp_row < num_row && tmp_col < num_col) {
      if (matrix[tmp_row][tmp_col] != num) {
        return false;
      }
      tmp_row++;
      tmp_col++;
    }    
  }

  
  for (row = 0, col = 0; row < num_row; row++) {
    num = matrix[row][col];
    tmp_row = row;
    tmp_col = col;
    while (tmp_row < num_row && tmp_col < num_col) {
      if (matrix[tmp_row][tmp_col] != num) {
        return false;
      }
      tmp_row++;
      tmp_col++;
    }    
  }
  
  return true;
}
