/*
https://leetcode.com/problems/house-robber/
*/
int rob(int* nums, int numsSize){
  int i, j, max;
  int *dp = (int *) calloc (numsSize, sizeof (int));
  
  dp[0] = nums[0];
  if (numsSize > 1)
    dp[1] = nums[1];
  for (i = 2; i < numsSize; i++) {
    max = -1;
    for (j = i - 2; j >= 0; j--) {
      if (nums[i] + dp[j] > max)
        max = nums[i] + dp[j];
    }
    dp[i] = max;
  }
  
  max = dp[0];
  for (i = 1; i < numsSize; i++) {
    if (dp[i] > max)
      max = dp[i];
  }
  return max;
}
