/*
https://leetcode.com/problems/sort-array-by-parity/

You may inclined to implement this using two pointer approach. But, it is better to implement using quick sort partitioning.
*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
  int i = -1, j = 0, pivot_idx = numsSize - 1, tmp;
  
  for (j = 0; j < pivot_idx; j++) {
    if ((nums[j] & 1) == 0) {
      ++i;
      tmp = nums[i];
      nums[i] = nums[j];
      nums[j] = tmp;
    }
  }
  i++;
  tmp = nums[i];
  nums[i] = nums[pivot_idx];
  nums[pivot_idx] = tmp;
  *returnSize = numsSize;
  return nums;
  
}
