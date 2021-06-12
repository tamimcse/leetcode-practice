/*
https://leetcode.com/problems/number-of-islands/
*/
int numIslands(char** grid, int gridSize, int* gridColSize){
  int num_row = gridSize, num_col = gridColSize[0];
  int *stack = (int *) malloc (num_row * num_col * 2 * sizeof (*stack));
  int s_idx, i, j, k, count = 0, curr, row, col;
  int *visit = (int *) calloc (num_row * num_col, sizeof (*visit));
  
  for (i = 0; i < num_row; i++) {
    for (j = 0; j < num_col; j++) {
      if (grid[i][j] != '1' || visit[i * num_col + j])
        continue;
      count++;
      s_idx = 0;
      stack[s_idx++] = i * num_col + j;
      visit[i * num_col + j] = 1;
      while (s_idx) {
        curr = stack[--s_idx];
        row = curr / num_col;
        col = curr % num_col;
        if (row + 1 < num_row && grid[row+1][col] == '1' && !visit[(row + 1) * num_col + col]) {
          stack[s_idx++] = (row + 1) * num_col + col;
          visit[(row + 1) * num_col + col] = 1;
        }
        if (col + 1 < num_col && grid[row][col+1] == '1' && !visit[row * num_col + col + 1]) {
          stack[s_idx++] = row * num_col + col + 1;
          visit[row * num_col + col + 1] = 1;
        }
        if (row >= 1 && grid[row-1][col] == '1' && !visit[(row - 1) * num_col + col]) {
          stack[s_idx++] = (row - 1) * num_col + col;
          visit[(row - 1) * num_col + col] = 1;
        }
        if (col >= 1 && grid[row][col-1] == '1' && !visit[row * num_col + col - 1]) {
          stack[s_idx++] = row * num_col + col - 1;
          visit[row * num_col + col - 1] = 1;
        }
      }
    }
  }
  return count;
}
