/*
https://leetcode.com/problems/house-robber/
*/
int rob(int* nums, int numsSize){
  int i, j, max;
  int *dp = (int *) calloc (numsSize, sizeof (int));
  
  dp[0] = nums[0];
  if (numsSize > 1)
    dp[1] = nums[1] > nums[0] ? nums[1] : nums[0];
  for (i = 2; i < numsSize; i++) {
    dp[i] = nums[i] + dp[i-2] > dp[i-1] ? nums[i] + dp[i-2] : dp[i-1];
  }

  return dp[numsSize-1];
}
