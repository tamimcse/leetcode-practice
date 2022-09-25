/*
https://leetcode.com/problems/minesweeper/
*/
int adj[][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0},
                {-1, -1}, {0, -1}, {1, -1}};


int num_adj_mines (char** board, int num_row, int num_col, int row, int col)
{
  int i, adj_row, adj_col, count = 0;
  
  for (i = 0; i < 8; i++) {
    adj_row = row + adj[i][0];
    adj_col = col + adj[i][1];
    if (adj_row >= 0 && adj_col >= 0 && 
        adj_row < num_row && adj_col < num_col) {
      if (board[adj_row][adj_col] == 'M')
        count++;
    }
  }
  return count;
}

void reveal (char** board, int num_row, int num_col, int row, int col, int **visit)
{
  int i, adj_row, adj_col, count;
  
  if (visit[row][col])
    return;
  visit[row][col] = 1;
  
  for (i = 0; i < 8; i++) {
    adj_row = row + adj[i][0];
    adj_col = col + adj[i][1];
    if (adj_row >= 0 && adj_col >= 0 && 
        adj_row < num_row && adj_col < num_col) {
      count = num_adj_mines (board, num_row, num_col, adj_row, adj_col);
      if (!count) {
        board[adj_row][adj_col] = 'B';
        reveal (board, num_row, num_col, adj_row, adj_col, visit);
      } else {
        board[adj_row][adj_col] = '0' + count;
      }
    }
  }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes){
  int num_row = boardSize, num_col = boardColSize[0];
  int i, j, k, count;
  int row = click[0], col = click[1];
  int **visit = (int **) malloc (num_row * sizeof (*visit));
  
  for (i = 0; i < num_row; i++)
    visit[i] = (int *) calloc (num_col, sizeof (int)); 
  
  *returnSize = num_row;
  *returnColumnSizes = (int *) malloc (num_row * sizeof (int));
  
  for (i = 0; i < num_row; i++)
    (*returnColumnSizes)[i] = num_col;
  
  if (board[row][col] == 'M') {
    board[row][col] = 'X';
    return board;
  }
  
  count = num_adj_mines (board, num_row, num_col, row, col);
  if (!count) {
    board[row][col] = 'B';
    reveal (board, num_row, num_col, row, col, visit);    
  } else {
    board[row][col] = '0' + count;
  }
  return board;
}
