/*
https://leetcode.com/problems/longest-continuous-increasing-subsequence/
*/
int findLengthOfLCIS(int* nums, int numsSize){
  int max = 1, curr_len = 1, i, j;
  
  for (i = 1; i < numsSize; i++) {
    if (nums[i] > nums[i-1]) {
      curr_len++;
    } else {
      curr_len = 1;
    }
    if (curr_len > max)
      max = curr_len;
  }
  return max;
}
