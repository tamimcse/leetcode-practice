/*
https://leetcode.com/problems/maximum-subarray/

Very interesting problem!
*/

int maxSubArray(int* nums, int numsSize){
  int subset_sum[30000] = {0};
  int i;
  int max_sum;
  
  if (!numsSize)
    return 0;
  
  subset_sum[0] = nums[0];
  for (i = 1; i < numsSize; i++) {
    if (subset_sum[i - 1] > 0)
      subset_sum[i] = subset_sum[i - 1] + nums[i];
    else
      subset_sum[i] = nums[i];
  }
  
  max_sum = subset_sum[0];
  for (i = 1; i < numsSize; i++) {
    if (max_sum < subset_sum[i])
      max_sum = subset_sum[i];
  }
  return max_sum;
}
