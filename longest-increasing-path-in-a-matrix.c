/*
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
*/

int neigh[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize){
  int i, j, k, row, col;
  int num_row = matrixSize, num_col = matrixColSize[0]; 
  char *visit = (char *) calloc (num_row * num_col, sizeof (*visit));
  int *stack = (int *) malloc (num_row * num_col * 2 * sizeof (*stack));
  int *path_len = (int *) calloc (num_row * num_col, sizeof (*path_len));
  int s_idx = 0, curr, curr_row, curr_col, curr_level, last_level, max, res = 0;
  bool max_level_found;
  
  for (i = 0; i < num_row; i++) {
    for (j = 0; j < num_col; j++) {
      if (path_len[i * num_col + j])
        continue;
      stack[s_idx] = i * num_col + j;
      s_idx++;
      curr_level = 0;
      max_level_found = false;
      printf ("starting at %d \n", i * num_col + j);
      while (s_idx) {
        curr = stack[s_idx - 1];
        printf ("Visiting %d \n", curr);
        if (visit[curr]) {
          if (!max_level_found) {
            last_level = curr_level;
            printf ("last level = %d \n", last_level);
            max_level_found = true;
          }
          printf ("Setting path_len[%d] = %d \n", curr, curr_level);
          if (!path_len[curr]) {
            path_len[curr] = last_level - curr_level + 1;  
          }

          visit[curr] = 0;
          --s_idx;
          curr_level--;
          continue;
        }
        if (path_len[curr]) {
          if (!max_level_found) {
            last_level = curr_level + path_len[curr];
            printf ("last level = %d \n", last_level);
            max_level_found = true;
          }
          curr_level--;
          --s_idx;
          continue;
        }
        curr_level++;
        curr_row = curr / num_col;
        curr_col = curr % num_col;
        for (k = 0; k < 4; k++) {
          row = curr_row + neigh[k][0];
          col = curr_col + neigh[k][1];
          if (col >= 0 && row >= 0 && col < num_col && row < num_row &&
             matrix[row][col] > matrix[curr_row][curr_col]) {
            stack[s_idx] = row * num_col + col;
            s_idx++;
          }
        }
        visit[curr] = 1;
      }
    }
  }
  
  res = path_len[0];
  for (i = 0; i < num_row; i++) {
    for (j = 0; j < num_col; j++) {
      if (path_len[i * num_col + j] > res)
        res = path_len[i * num_col + j];
    }
  }
  return res;
}
