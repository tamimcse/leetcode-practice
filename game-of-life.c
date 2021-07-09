/*
https://leetcode.com/problems/game-of-life/
*/


void gameOfLife(int** board, int boardSize, int* boardColSize){
  int i, j, k, num_row = boardSize, num_col = boardColSize[0], adj_row, adj_col, count;
  int **next_state = (int **) calloc (num_row, sizeof (*next_state));
  int neigh [][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
  
  for (i = 0; i < num_row; i++) {
    next_state[i] = (int *) calloc (num_col, sizeof (int));
  }
  
  for (i = 0; i < num_row; i++) {
    for (j = 0; j < num_col; j++) {
      if (!board[i][j]) {
        //count # of live
        count = 0;
        for (k = 0; k < 8; k++) {
          adj_row = i + neigh[k][0];
          adj_col = j + neigh[k][1];
          if (adj_row >= 0 && adj_row < num_row && adj_col >= 0 &&
              adj_col < num_col && board[adj_row][adj_col]) {
            count++;
          }
        }
        if (count == 3)
          next_state[i][j] = 1;
      } else {
        //count # of live
        count = 0;
        for (k = 0; k < 8; k++) {
          adj_row = i + neigh[k][0];
          adj_col = j + neigh[k][1];
          if (adj_row >= 0 && adj_row < num_row && adj_col >= 0 && 
              adj_col < num_col && board[adj_row][adj_col]) {
            count++;
          }
        }
        if (count == 2 || count == 3)
          next_state[i][j] = 1;
        else
          next_state[i][j] = 0;
      }
    }
  }
  
  for (i = 0; i < num_row; i++) {
    for (j = 0; j < num_col; j++) {
      board[i][j] = next_state[i][j];
    }
  }
}
