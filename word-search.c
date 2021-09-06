/*
https://leetcode.com/problems/word-search/
*/

int adj[][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool dfs (char** board, int num_row, int num_col, int row, int col, char *word, int **visit)
{
  int i, j, adj_row, adj_col;
  bool res;  

  if (!word[1])
    return true;
  
  visit[row][col] = 1;
  for (i = 0; i < 4; i++) {
    adj_row = row + adj[i][0];
    adj_col = col + adj[i][1];
    if (adj_row >= num_row || adj_row < 0 || adj_col >= num_col || adj_col < 0 || 
        visit[adj_row][adj_col])
      continue;
    if (board[adj_row][adj_col] == word[1]) {
      res = dfs (board, num_row, num_col, adj_row, adj_col, word + 1, visit);
      if (res)
        return true;
    }
  }
  visit[row][col] = 0;
  return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
  int num_row = boardSize, num_col = boardColSize[0], i, j;
  int **visit = (int **) malloc (num_row * sizeof (*visit));
    
  for (i = 0; i < num_row; i++)
    visit[i] = (int *) calloc (num_col, sizeof (int));  
    
  for (i = 0; i < num_row; i++) {
    for (j = 0; j < num_col; j++) { 
      if (board[i][j] == word[0]) {
        if (dfs (board, num_row, num_col, i, j, word, visit))
          return true;
      }
    }
  }
  return false;
}
