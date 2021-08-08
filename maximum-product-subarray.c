/*
https://leetcode.com/problems/maximum-product-subarray/

Interetingly O(n^2) passes the test cases.
*/
int maxProduct(int* nums, int numsSize){
  int i, j, prefix_prod, max = -11000000000000000;
  
  for (i = 0; i < numsSize; i++) {
    if (nums[i] > max)
      max = nums[i];
    if (i + 1 >=  numsSize)
      continue;
    prefix_prod = nums[i] * nums[i + 1];
    if (prefix_prod > max)
      max = prefix_prod;
    for (j = i + 2; j < numsSize; j++) {
      prefix_prod *= nums[j];
      if (prefix_prod > max)
        max = prefix_prod;
    }
  }
  return max;
}
