/*
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

This is DFS + Memorization. This cannot be solved using DFS iterative approach. Need to use recursive approach.
*/

int dfs (int** matrix, int num_row, int num_col, int **res, int row, int col)
{
  int i, adj_row, adj_col;
  int neigh[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int ret = 0, res1;
  
  for (i = 0; i < 4; i++) {
    adj_row = row + neigh[i][0];
    adj_col = col + neigh[i][1];
    if (adj_row >= 0 && adj_row < num_row && adj_col >= 0 && adj_col < num_col &&
       matrix[adj_row][adj_col] > matrix[row][col]) {
      res1 = res[adj_row][adj_col] ? 
        res[adj_row][adj_col] : dfs (matrix, num_row, num_col, res, adj_row, adj_col);
      if (res1 > ret)
        ret = res1;
    }
  }
  res[row][col] = ret + 1;
  return res[row][col];
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize){
  int i, j, k, num_row = matrixSize, num_col = matrixColSize[0], ret;
  int **res = (int *) calloc (num_row, sizeof (*res));
  
  for (i = 0; i < num_row; i++)
    res[i] = (int *) calloc (num_col, sizeof (int));
  
  for (i = 0; i < num_row; i++) {
    for (j = 0; j < num_col; j++) {
      if (!res[i][j]) {
        dfs (matrix, num_row, num_col, res, i, j);
      }
    }
  }

  ret = res[0][0];
  for (i = 0; i < num_row; i++) {
    for (j = 0; j < num_col; j++) {
      if (res[i][j] > ret)
        ret = res[i][j];
    }
  }
  return ret;
}
