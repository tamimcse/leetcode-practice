/*
https://leetcode.com/problems/sudoku-solver/

Interesting problem!
*/

void get_valid_values(char** board, int num_row, int num_col, int row, int col, int *hash)
{
  int i, j, k, subbox_row, subbox_col, start_row, start_col, cur_row, cur_col;

  for (i = 0; i < num_row; i++) {
    if (board[i][col] == '.')
      continue;
    hash[board[i][col] - '0'] = 1;
  }
  
  for (i = 0; i < num_col; i++) {
    if (board[row][i] == '.')
      continue;
    hash[board[row][i] - '0'] = 1;
  }
  
  subbox_row = row/3;
  subbox_col = col/3;
  start_row = subbox_row * 3;
  start_col = subbox_col * 3;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      cur_row = start_row + i;
      cur_col = start_col + j;
      if (board[cur_row][cur_col] == '.')
        continue;
      hash[board[cur_row][cur_col] - '0'] = 1;
    }
  }
}

void solveSudoku_inner(char** board, int num_row, int num_col, int row, int col, bool *done)
{
  int i, j, k;
  
  for (i = 0; i < num_row; i++) {
    for (j = 0; j < num_col; j++) {
      if (board[i][j] != '.')
        continue;
      int hash[10] = {0};
      get_valid_values (board, num_row, num_col, i, j, hash);

      for (k = 1; k <= 9; k++) {
        if (!hash[k]) {
          board[i][j] = '0' + k;
          solveSudoku_inner (board, num_row, num_col, i, j, done);
          if (*done)
            return;
          board[i][j] = '.';
        }
      }
      return;
    }
  }
  *done = true;
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
  int num_row = boardSize, num_col = boardColSize[0];
  bool done = false;
  solveSudoku_inner (board, num_row, num_col, 0, 0, &done);
}
