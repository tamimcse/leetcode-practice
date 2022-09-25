/*
https://leetcode.com/problems/jump-game/

This may look like a graph problem, but it can be solved in a easier way using iterative approach.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize){
  int i, max = nums[0];

  for (i = 1; i < numsSize; i++) {
    if (i > max)
      return false;
    else if (max < i + nums[i])
      max = i + nums[i];
  }
  return max >= numsSize - 1;
}

struct edge {
  int v2;
  struct edge *next;
};

bool canJump_graph(int* nums, int numsSize){
  int i, j;
  struct edge *new_edge, *runner;
  struct edge **adj_list = (struct edge **) calloc (numsSize, sizeof (*adj_list));
  
  for (i = 0; i < numsSize - 1; i++) {
    if (!nums[i])
      continue;
    int start = i + 1;
    int end = ((i + nums[i]) < numsSize) ? i + nums[i] : numsSize - 1;
    for (j = start; j <= end; j++) {
      new_edge = (struct edge *) malloc (sizeof (*new_edge));
      new_edge->v2 = j;
      new_edge->next = adj_list[i];
      adj_list[i] = new_edge;
    }
  }
  
  char *inserted = (char *) calloc (numsSize, sizeof (*inserted));
  int *queue = (int *) malloc ((numsSize + 1) * sizeof (*queue));
  int q_start = 0, q_end = 0;
  queue[q_end++] = 0;
  inserted[0] = 1;
  int curr;
  while (q_end > q_start) {
    curr = queue[q_start++];
    if (curr == numsSize - 1)
      return true;
    runner = adj_list[curr];
    while (runner) {
      if (!inserted[runner->v2]) {
        queue[q_end++] = runner->v2;
        inserted[runner->v2] = 1;
      }
      runner = runner->next;
    }
  }
  return false;
}

void main ()
{
  int nums[] = {3, 2, 1, 0, 4};
  int len = sizeof (nums) / sizeof (nums[0]);

  bool res = canJump (nums, len);

  printf ("nums len is %d \n", len);

  printf ("%s jump\n", res ? "can" : "cannot");
}
