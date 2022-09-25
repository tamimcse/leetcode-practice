/*
https://leetcode.com/problems/island-perimeter/

Interesting problem
*/
int neigh[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int islandPerimeter(int** grid, int gridSize, int* gridColSize){
  int num_row = gridSize, num_col = gridColSize[0], i, j, k, sum = 0, row, col;
  
  for (i = 0; i < num_row; i++) {
    for (j = 0; j < num_col; j++) {
      if (!grid[i][j])
        continue;
      for (k = 0; k < 4; k++) {
        row = i + neigh[k][0];
        col = j + neigh[k][1];
        if (row < 0 || col < 0 || row >= num_row || col >= num_col || !grid[row][col])
          sum++;
      }
    }
  }
  return sum;
}
