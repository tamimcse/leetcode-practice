/*
https://leetcode.com/problems/target-sum/
*/
void findTargetSumWays_inner(int* nums, int numsSize, int target, int start, int prev, int *res)
{
  int sum1 = prev + nums[start], sum2 = prev - nums[start];
  if (start == numsSize - 1) {
    if (sum1 == target)
      *res += 1;
    if (sum2 == target)
      *res += 1;
  } else {
    findTargetSumWays_inner (nums, numsSize, target, start + 1, sum1, res);
    findTargetSumWays_inner (nums, numsSize, target, start + 1, sum2, res);    
  }
}

int findTargetSumWays(int* nums, int numsSize, int target){
  int res = 0;
  
  findTargetSumWays_inner (nums, numsSize, target, 0, 0, &res);
  return res;
}
