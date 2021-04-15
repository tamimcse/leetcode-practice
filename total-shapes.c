/*
https://practice.geeksforgeeks.org/problems/x-total-shapes3617/1/?company[]=Amazon&company[]=Amazon&page=1&query=company[]Amazonpage1company[]Amazon
*/
#include <stdio.h>
#include <stdlib.h>

#define COL_NUM 4

struct point {
  int row;
  int col;
};

int count_x_shapes (char arr[][COL_NUM], int row_num)
{
  int i, j, count = 0, q_start, q_end, curr_i, curr_j;
  struct point *curr;
  struct point *queue = (struct point *) malloc (row_num * COL_NUM * sizeof (*queue));
  
  for (i = 0 ; i < row_num; i++) {
    for (j = 0; j < COL_NUM; j++) {
      if (arr[i][j] != 'x')
        continue;
      //perform BFS
      q_start = 0;
      q_end = 0;
      queue[q_end].row = i;
      queue[q_end].col = j;
      q_end++;
      while (q_end > q_start) {
        curr = &queue[q_start++];
        arr[curr->row][curr->col] = '-';
        //push right
        if (curr->col < COL_NUM - 1 && arr[curr->row][curr->col + 1] == 'x') {
          queue[q_end].row = curr->row;
          queue[q_end].col = curr->col + 1;
          q_end++;
        }
        //push down
        if (curr->row < row_num - 1 && arr[curr->row + 1][curr->col] == 'x') {
          queue[q_end].row = curr->row + 1;
          queue[q_end].col = curr->col;
          q_end++;
        }
      }
      count++;
    }
  }
  return count;
}

void main ()
{
  char arr[][COL_NUM] = {{'x', 'x', 'o', 'x'}, {'x', 'o', 'o', 'o'}, {'x', 'x', 'x', 'o'}, {'o', 'o', 'o', 'o'}, {'o', 'x', 'o', 'o'}, {'o', 'o', 'o', 'o'}, {'o', 'x', 'x', 'x'}};
  int row_num = sizeof (arr) / sizeof (arr[0]);
  int res = count_x_shapes (arr, row_num);
  printf ("Number of x islands are %d \n", res);
}
