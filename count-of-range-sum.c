/*
https://leetcode.com/problems/count-of-range-sum/

Gets TLE. Solve this using Binary Index Tree
*/
int countRangeSum(int* nums, int numsSize, int lower, int upper){
  long *prefix_sum = (long *) calloc (numsSize + 1, sizeof (*prefix_sum));
  int i, j, k, row, col, count, idx;
  long range_sum;
  
  prefix_sum[0] = 0;
  for (i = 0; i < numsSize; i++) {
    prefix_sum[i+1] = prefix_sum[i] + nums[i];
  }
  
  count = 0;
  for (i = 0; i < numsSize; i++) {
    for (j = i; j < numsSize; j++) {
      range_sum = prefix_sum[j+1] - prefix_sum[i];
      if (range_sum >= lower && range_sum <= upper)
        count++;
    }
  }
  return count;
}
