/*
https://leetcode.com/problems/majority-element/

https://www.geeksforgeeks.org/majority-element/
*/
int majorityElement(int* nums, int numsSize){
  int idx = 0, count = 1, i;
  
  for (i = 1; i < numsSize; i++) {
    if (nums[i] == nums[idx]) {
      count++;
    } else {
      count--;
    }
    if (!count) {
      idx = i;
      count = 1;
    }
  }
  return nums[idx];
}
