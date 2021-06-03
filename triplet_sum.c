/*
Find a triplet that sum to a given value: Given an array and a value, find if there is a triplet in array whose sum is equal to the given value. If there is such a triplet present in array, then print the triplet and return true. Else return false. 

Input: array = {12, 3, 4, 1, 6, 9}, sum = 24;
Output: 12, 3, 9
Explanation: There is a triplet (12, 3 and 9) present
in the array whose sum is 24. 

Input: array = {1, 2, 3, 4, 5}, sum = 9
Output: 5, 3, 1
Explanation: There is a triplet (5, 3 and 1) present 
in the array whose sum is 9. 
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool triplet_sum1 (int arr[], int len, int target)
{
  int i, j;

  int *hash = (int *) calloc (target, sizeof (*hash));
  for (i = 0; i < len; i++) {
    if (arr[i] < target)
      hash[arr[i]] = 1;
  }

  for (i = 0; i < len; i++) {
    for (j = i + 1; j < len; j++) {
      int to_find = target - arr[i] - arr[j];
      if (hash[to_find]) {
        printf ("Target = %d, output = %d %d %d \n", target, arr[i], arr[j], to_find);
        return true;
      }
    }
  }
  printf ("Triplet not found \n");
  return false;
}

int cmp_int (const void *a, const void *b)
{
  return *((int *)a) - *((int *)b); 
}

bool triplet_sum2 (int arr[], int len, int target)
{
  int i, j, start, end, to_find, inner_sum;
  qsort (arr, len, sizeof (arr[0]), cmp_int);

  for (i = 0; i < len; i++) {
    to_find = target - arr[i];
    start = i + 1;
    end = len - 1;
    while (end >= start) {
      inner_sum = arr[start] + arr[end];
      if (inner_sum == to_find) {
        printf ("Target = %d, output = %d %d %d \n", target, arr[i], arr[start], arr[end]);
        return true;
      } else if (inner_sum < to_find) {
        start++;
      } else {
        end--;
      }
    }
  }
  printf ("Triplet not found \n");
  return false;
}

//check beneath main
void main ()
{
  int arr [] = {12, 3, 4, 1, 6, 9};
  int len = sizeof (arr) / sizeof (arr[0]);

  triplet_sum1 (arr, len, 24);

  triplet_sum2 (arr, len, 24);
}

/*
https://leetcode.com/problems/3sum/

int cmp (const void *a, const void *b)
{
  return *((int *)a) - *((int *)b);
}

bool binary_search (int* nums, int start, int end, int to_find)
{
  int mid;
  
  while (end >= start) {
    mid = (start + end) >> 1;
    if (nums[mid] == to_find)
      return true;
    if (to_find > nums[mid])
      start = mid + 1;
    else
      end = mid - 1;
  }
  return false;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
  int i, j, to_find;
  int **res = (int **) malloc (pow (numsSize, 2) * sizeof (*res));
  int res_cnt = 0;
  
  qsort (nums, numsSize, sizeof (int), cmp);
  
  for (i = 0; i < numsSize - 2; i++) {
    if (i > 0 && nums[i] == nums[i-1])
      continue;
    for (j = i + 1; j < numsSize - 1; j++) {
      if (j > i + 1 && nums[j] == nums[j-1])
        continue;
      to_find = 0 - nums[i] - nums[j];
      if (!binary_search (nums, j + 1, numsSize - 1, to_find))
        continue;
      res[res_cnt] = (int *) malloc (3 * sizeof (int));
      res[res_cnt][0] = nums[i];
      res[res_cnt][1] = nums[j];
      res[res_cnt][2] = to_find;
      res_cnt++;
    }
  }
  *returnSize = res_cnt;
  *returnColumnSizes = (int *) malloc (res_cnt * sizeof (int));
  for (i = 0; i < res_cnt; i++)
    (*returnColumnSizes)[i] = 3;
  return res;
}
*/
