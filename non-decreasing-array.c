/*
https://leetcode.com/problems/non-decreasing-array/
*/
bool checkPossibility(int* nums, int numsSize){
  int i, j, count = 0;
  
  for (i = 1; i < numsSize; i++) {
    if (nums[i] < nums[i-1]) {
      if ((i >= 2 && nums[i - 2] > nums[i]) &&
          (i + 1 < numsSize && nums[i-1] > nums[i+1])) {
        return false;
      }
      count++;
      if (count > 1)
        return false;
    }
  }
  return true;
}
