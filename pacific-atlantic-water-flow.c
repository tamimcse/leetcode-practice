/*
https://leetcode.com/problems/pacific-atlantic-water-flow/
*/
bool is_adj_pacific (int** heights, int row, int col)
{
  int i;
  
  if (row == 0 || col == 0)
    return true;
  for (i = col - 1; i >= 0; i--) {
    if (heights[row][i] > heights[row][i+1])
      break;
  }
  if (i < 0)
    return true;
  for (i = row - 1; i >= 0; i--) {
    if (heights[i][col] > heights[i+1][col])
      break;
  }
  return i < 0;
}

bool is_adj_atlanic (int** heights, int row, int col, int num_row, int num_col)
{
  int i;
  
  if (row == num_row - 1 || col == num_col - 1)
    return true;
  for (i = col + 1; i < num_col; i++) {
    if (heights[row][i] > heights[row][i-1])
      break;
  }
  if (i == num_col)
    return true;
  for (i = row + 1; i < num_row; i++) {
    if (heights[i][col] > heights[i-1][col])
      break;
  }
  return i == num_row;
}

int adj [][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs (int** heights, char **res, int row, int col, int num_row, int num_col)
{
  int i, j, k, adj_row, adj_col;
  
  res[row][col] = 1;
  for (i = 0; i < 4; i++) {
    adj_row = row + adj[i][0];
    adj_col = col + adj[i][1];
    if (adj_row < 0 || adj_row >= num_row || adj_col < 0 || adj_col >= num_col)
      continue;
    if (res[adj_row][adj_col])
      continue;
    if (heights[adj_row][adj_col] >= heights[row][col]) {
      dfs (heights, res, adj_row, adj_col, num_row, num_col);
    }
  }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes){
  int i, j, k, row, col;
  int num_row = heightsSize, num_col = heightsColSize[0];
  char **res = (char **) calloc (num_row, sizeof (*res));
  int ret_cnt;
  int** ret;
  
  for (i = 0; i < num_row; i++) {
    res[i] = (char *) calloc (num_col, sizeof (char));
  }
  
  for (row = 0; row < num_row; row++) {
    for (col = 0; col < num_col; col++) {
      if (!is_adj_pacific (heights, row, col))
        continue;
      if (!is_adj_atlanic (heights, row, col, num_row, num_col))
        continue;
      dfs (heights, res, row, col, num_row, num_col);
    }
  }
  
  ret_cnt = 0;
  for (row = 0; row < num_row; row++) {
    for (col = 0; col < num_col; col++) {
      if (res[row][col])
        ret_cnt++;
    }
  }
  
  *returnSize = ret_cnt;
  ret = (int **) malloc (ret_cnt * sizeof (*ret));
  *returnColumnSizes = (int *) malloc (ret_cnt * sizeof (int));
  for (i = 0; i < ret_cnt; i++) {
    ret[i] = (int *) malloc (2 * sizeof (int));
    (*returnColumnSizes)[i] = 2;
  }
  
  i = 0;
  for (row = 0; row < num_row; row++) {
    for (col = 0; col < num_col; col++) {
      if (res[row][col]) {
        ret[i][0] = row;
        ret[i][1] = col;
        i++;
      }
    }
  }
  
  return ret;
}
