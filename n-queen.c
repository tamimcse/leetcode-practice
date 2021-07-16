/*
https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/

Take a look beneath main () to see leetcode 
*/
#include <stdio.h>
#include <stdlib.h>

int is_valid_location (int *arr, int n, int row, int col)
{
  int i, j;
  
  if (arr[row * n + col])
    return 0;

  for (j = 0; j < n; j++) {
    if (arr[row * n + j])
      return 0;
  }

  for (i = 0; i < n; i++) {
    if (arr[i * n + col])
      return 0;
  }

  //right-down diagonal
  i = row + 1;
  j = col + 1;
  while (i < n && j < n) {
    if (arr[i * n + j])
      return 0;
    i++;
    j++;
  }

  //left-up diagonal
  i = row - 1;
  j = col - 1;
  while (i >= 0 && j >= 0) {
    if (arr[i * n + j])
      return 0;
    i--;
    j--;
  }

  //right-up diagonal
  i = row - 1;
  j = col + 1;
  while (i >= 0 && j < n) {
    if (arr[i * n + j])
      return 0;
    i--;
    j++;
  }

  //left-down diagonal
  i = row + 1;
  j = col - 1;
  while (i < n && j >= 0) {
    if (arr[i * n + j])
      return 0;
    i++;
    j--;
  }

  return 1;
}

int n_queen_inner (int *arr, int n, int col)
{
  int row, idx, i, j, res;

  if (col == n) {
    printf ("Chess box = \n");
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        printf ("%d ", arr[i * n + j]);
      }
      printf ("\n");
    }
    return 0;
  }

  for (row = 0; row < n; row++) {
    if (!is_valid_location(arr, n, row, col))
      continue;
    arr[row * n + col] = 1;
    res = n_queen_inner (arr, n, col + 1);
    if (!res)
      return 0;
    arr[row * n + col] = 0;
  }
  return -1;
}

void n_queen (int n)
{
  int *res = (int *)calloc (n * n, sizeof (*res));
  n_queen_inner (res, n, 0);
}

void main ()
{
  int n = 8;

  n_queen (n);
}

/*
https://leetcode.com/problems/n-queens/

bool is_valid (int x1, int y1, int x2, int y2)
{
  return !(x1 == x2 || y1 == y2 || abs (x2 - x1) == abs (y2 - y1));  
}

bool can_place (char **board, int board_size, int row, int col)
{
  int i, j;
  
  for (i = 0; i < board_size; i++) {
    for (j = 0; j < col; j++) {
      if (board[i][j] == 'Q' && !is_valid (i, j, row, col))
        return false;
    }
  }
  return true;
}

char **create_board (int n)
{
  int i;
  char **board = (char **) malloc (n * sizeof (*board)); 
  
  for (i = 0; i < n; i++) {
    board[i] = (char *) calloc (n + 1, sizeof (char));
  }
  return board;
}

void place_queen (char **board, int board_size, int col, char ***res, int *res_cnt)
{
  int i, j;
  
  if (col == board_size) {
    char **new_board = create_board (board_size);
    for (i = 0; i < board_size; i++)
      memcpy (new_board[i], board[i], board_size * sizeof (char));
    res[*res_cnt] = new_board;
    (*res_cnt)++;
    return;
  }
  
  for (i = 0; i < board_size; i++) {
    if (can_place (board, board_size, i, col)) {
      board[i][col] = 'Q';
      place_queen (board, board_size, col + 1, res, res_cnt);
      board[i][col] = '.';
    }
  }
}

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
  char ***res = (char ***) calloc (n*54, sizeof (*res));
  int res_cnt = 0;
  int i, j, k;
  char **board = create_board (n);
  
  for (i = 0; i < n; i++) {
    memset (board[i], '.', n * sizeof (char));
  }
  
  place_queen (board, n, 0, res, &res_cnt);
  *returnSize = res_cnt;
  *returnColumnSizes = (int *) malloc (res_cnt * sizeof (int));
  for (i = 0; i < res_cnt; i++) {
    (*returnColumnSizes)[i] = n;
  }
  return res;
}

*/
