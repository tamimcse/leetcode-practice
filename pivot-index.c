/*
https://leetcode.com/problems/find-pivot-index/
*/
int pivotIndex(int* nums, int numsSize){
  int left_sum = 0, right_sum = 0, i;
  
  for (i = 1; i < numsSize; i++) {
    right_sum += nums[i];
  }
  
  for (i = 0; i < numsSize; i++) {
    if (left_sum == right_sum) {
      return i;
    }
    if (i == numsSize - 1)
      return -1;
    left_sum += nums[i];
    right_sum -= nums[i+1];
  }
  return -1;
}
