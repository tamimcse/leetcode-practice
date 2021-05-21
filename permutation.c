/*
https://leetcode.com/problems/permutations/
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void permute_inner (int* nums, int numsSize, int *arr, int arr_cnt, int **res, int *res_cnt, int *hash)
{
  int i, j;
  
  if (arr_cnt == numsSize) {
    res[*res_cnt] = (int *) malloc (numsSize * sizeof (int));
    memcpy (res[*res_cnt], arr, sizeof (int) * numsSize);
    (*res_cnt)++;
    return;
  }
  
  for (i = 0; i < numsSize; i++) {
    if (hash[nums[i] + 10])
      continue;
    hash[nums[i] + 10] = 1;
    arr[arr_cnt] = nums[i];
    permute_inner (nums, numsSize, arr, arr_cnt + 1, res, res_cnt, hash);
    hash[nums[i] + 10] = 0;
  }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
  int **res = (int **) calloc (46656, sizeof (*res));
  int *arr = (int *) calloc (numsSize, sizeof (*arr));
  int i, res_cnt;
  
  for (i = 0; i < numsSize; i++) {
    int hash[21] = {0};
    arr[0] = nums[i];
    hash[nums[i] + 10] = 1;
    permute_inner (nums, numsSize, arr, 1, res, &res_cnt, hash);
  }
  *returnSize = res_cnt;
  
  *returnColumnSizes = (int *) malloc (res_cnt * sizeof (int));
  for (i = 0; i < res_cnt; i++) {
    (*returnColumnSizes)[i] = numsSize;
  }
  return res;
}

void main ()
{
  int nums [] = {1, 2, 3};
  int len = sizeof (nums) / sizeof (nums[0]);
  int res_len;
  int *colSizes;
  int **res;
  int i, j;

  res = permute (nums, len, &res_len, &colSizes);
  for (i = 0; i < res_len; i++) {
    for (j = 0; j < colSizes[i]; j++) {
      printf ("%d ", res[i][j]);
    }
    printf ("\n");
  }
}
