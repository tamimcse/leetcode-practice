/*
https://leetcode.com/problems/pacific-atlantic-water-flow/

Initially, I thought I will do DFS starting from each (unvisited) node. But, if you look carefully, we need to start from the ocean. In other words, we need to do DFS startinhg from the nodes adjacent to ocean. 
*/
int adj [][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs_pacific (int** heights, char **res, int row, int col, int num_row, int num_col)
{
  int i, j, k, adj_row, adj_col;
  
  if (res[row][col])
    return;

  res[row][col] = 1;
  for (i = 0; i < 4; i++) {
    adj_row = row + adj[i][0];
    adj_col = col + adj[i][1];
    if (adj_row < 0 || adj_row >= num_row || adj_col < 0 || adj_col >= num_col)
      continue;
    if (res[adj_row][adj_col])
      continue;
    if (heights[adj_row][adj_col] >= heights[row][col]) {
      dfs_pacific (heights, res, adj_row, adj_col, num_row, num_col);
    }
  }
}

void dfs_atlantic (int** heights, char **res, int row, int col, int num_row, int num_col)
{
  int i, j, k, adj_row, adj_col;
  
  if (res[row][col] == 2)
    return;
  
  if (res[row][col] == 3)
    return;

  if (res[row][col] == 1)
    res[row][col] = 2;
  else
    res[row][col] = 3;
  for (i = 0; i < 4; i++) {
    adj_row = row + adj[i][0];
    adj_col = col + adj[i][1];
    if (adj_row < 0 || adj_row >= num_row || adj_col < 0 || adj_col >= num_col)
      continue;
    if (res[adj_row][adj_col] == 3 || res[adj_row][adj_col] == 2)
      continue;
    if (heights[adj_row][adj_col] >= heights[row][col]) {
      dfs_atlantic (heights, res, adj_row, adj_col, num_row, num_col);
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
  
  //visit first row
  for (i = 0; i < num_col; i++)
    dfs_pacific (heights, res, 0, i, num_row, num_col);
  
  //visit first column
  for (i = 1; i < num_row; i++)
    dfs_pacific (heights, res, i, 0, num_row, num_col);
  
  //visit last column
  for (i = 0; i < num_row; i++)
    dfs_atlantic (heights, res, i, num_col-1, num_row, num_col);
  
  //visit last row
  for (i = 0; i < num_col-1; i++)
    dfs_atlantic (heights, res, num_row-1, i, num_row, num_col);
  
  ret_cnt = 0;
  for (row = 0; row < num_row; row++) {
    for (col = 0; col < num_col; col++) {
      if (res[row][col] == 2)
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
      if (res[row][col] == 2) {
        ret[i][0] = row;
        ret[i][1] = col;
        i++;
      }
    }
  }
  
  return ret;
}
