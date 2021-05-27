/*
https://leetcode.com/problems/word-search/
*/

struct node {
  int row;
  int col;
};


bool dfs (char** board, int num_row, int num_col, int row, int col, char * word)
{
  int i;
  struct node *stack = (struct node *) malloc (num_row * num_col * 1000 * sizeof (*stack));
  int s_idx = 0;
  struct node curr;
  char **visit = (char **) calloc (num_row, sizeof (*visit));
  for (i = 0; i < num_row; i++)
    visit[i] = (char *) calloc (num_col, sizeof (char));
  int len = strlen (word);
  int word_idx = 0;

  stack[s_idx].row = row;
  stack[s_idx].col = col;
  s_idx++;

  while (s_idx) {
    curr = stack[s_idx - 1];
   // printf ("Got %c from stack. Looking for %c \n", board[curr.row][curr.col], word[word_idx]);
    if (visit[curr.row][curr.col]) {
      visit[curr.row][curr.col] = 0;
      word_idx--;
      s_idx--;
      continue;
    }
    if (board[curr.row][curr.col] != word[word_idx]) {
      s_idx--;
      continue;
    }
    visit[curr.row][curr.col] = 1;
    word_idx++;
    if (word_idx == len)
      return true;
    if (curr.row + 1 < num_row && !visit[curr.row + 1][curr.col]) {
      stack[s_idx].row = curr.row + 1;
      stack[s_idx].col = curr.col;
      s_idx++;
    }
    if (curr.col + 1 < num_col && !visit[curr.row][curr.col + 1]) {
      stack[s_idx].row = curr.row;
      stack[s_idx].col = curr.col + 1;
      s_idx++;
    }
    if (curr.row - 1 >= 0 && !visit[curr.row - 1][curr.col]) {
      stack[s_idx].row = curr.row - 1;
      stack[s_idx].col = curr.col;
      s_idx++;
    }
    if (curr.col - 1 >= 0 && !visit[curr.row][curr.col - 1]) {
      stack[s_idx].row = curr.row;
      stack[s_idx].col = curr.col - 1;
      s_idx++;
    }
  }
  return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
  int i, j;
  bool res = false;
  
  for (i = 0; i < boardSize; i++) {
    for (j = 0; j < boardColSize[0]; j++) {
      if (board[i][j] == word[0]) {
        res = dfs (board, boardSize, boardColSize[0], i, j, word);
        if (res)
          return true;
      }
    }
  }
  return false;
}
