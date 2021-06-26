/*
https://leetcode.com/problems/count-of-range-sum/

Gets TLE
*/
int countRangeSum(int* nums, int numsSize, int lower, int upper){
  long *dp = (int *) calloc (numsSize * numsSize, sizeof (*dp));
  int i, j, k, row, col, count, idx;

  count = 0;
  for (i = 0; i < numsSize; i++) {
    idx = i * numsSize + i;
    dp[idx] = nums[i];
    if (dp[idx] >= lower && dp[idx] <= upper)
      count++;
  }

  for (i = 1; i < numsSize; i++) {
    for (row = 0, col = i; col < numsSize; row++, col++) {
      idx = row * numsSize + col;
      dp[idx] = dp[idx - 1] + nums[col];
      if (dp[idx] >= lower && dp[idx] <= upper)
        count++;
    }
  }
  return count;
}
