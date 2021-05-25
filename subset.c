/*
https://www.geeksforgeeks.org/backtracking-to-find-all-subsets/
*/
#include <stdio.h>

void subset (int *arr, int len)
{
  int i, count;
  
  for (i = 0, count = 0; i < len; i++) {
    if (arr[i] != -1) {
      printf ("%d ", arr[i]);
      count++;
    }
  }
  printf ("\n");

  if (count == 1)
    return;

  for (i = 0; i < len; i++) {
    if (arr[i] != -1) {
      int tmp = arr[i];
      arr[i] = -1;
      subset (arr, len);
      arr[i] = tmp;
    }
  }
}

/*

https://leetcode.com/problems/subsets/

void subsets_inner (int* nums, int numsSize, int *state, int state_cnt, int start, int **res, int *res_num, int *returnColumnSizes)
{
  int i;
  
  for (i = start; i < numsSize; i++) {
    state[state_cnt] = nums[i];
    res[*res_num] = (int *) malloc ((state_cnt + 1) * sizeof (int));
    memcpy (res[*res_num], state, (state_cnt + 1) * sizeof (int));
    returnColumnSizes[*res_num] = state_cnt + 1;
    (*res_num)++;
    subsets_inner (nums, numsSize, state, state_cnt + 1, i + 1, res, res_num, returnColumnSizes);
  }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
  int res_cnt = pow (2, numsSize);
  *returnSize = res_cnt;
  int **res = (int **) calloc (res_cnt, sizeof (*res));
  int res_num = 0;
  int *state = (int *) malloc (numsSize * sizeof (*state));
  *returnColumnSizes = (int *) malloc (res_cnt * sizeof (int));
  (*returnColumnSizes)[res_cnt - 1] = 0;
  
  subsets_inner (nums, numsSize, state, 0, 0, res, &res_num, *returnColumnSizes);
  return res;
}
*/

void main ()
{
  int arr[] = {1, 2, 3}; 
  int len = sizeof (arr) / sizeof (arr[0]);

  subset (arr, len);
}
