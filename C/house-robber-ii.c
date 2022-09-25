/*
https://leetcode.com/problems/house-robber-ii/
*/
int rob_linear(int* nums, int numsSize){
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

int rob(int* nums, int numsSize){
  if (numsSize == 1)
    return nums[0];
  int res1 = rob_linear (nums, numsSize - 1);
  int res2 = rob_linear (nums + 1, numsSize - 1);
  return res1 > res2 ? res1 : res2;
}
