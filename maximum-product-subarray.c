/*
https://leetcode.com/problems/maximum-product-subarray/

Interetingly O(n^2) passes the test cases. But that is not enough!

Follow the second solution of :

https://www.geeksforgeeks.org/maximum-product-subarray/

*/

/*
//O(n^2) solution
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

*/


int max_ (int a, int b)
{
  return a > b ? a : b;
}

int min_ (int a, int b)
{
  return a < b ? a : b;
}

int maxProduct(int* nums, int numsSize){
  int *max = (int *) malloc (numsSize * sizeof (int));
  int *min = (int *) malloc (numsSize * sizeof (int));
  int i, cur_min, cur_max, res;
  
  max[0] = nums[0];
  min[0] = nums[0];
  
  for (i = 1; i < numsSize; i++) {
    cur_min = min_ (nums[i] * max[i-1], nums[i] * min[i-1]);
    cur_max = max_ (nums[i] * max[i-1], nums[i] * min[i-1]);
    max[i] = max_ (cur_max, nums[i]);
    min[i] = min_ (cur_min, nums[i]);
  }
  
  res = max[0];
  for (i = 1; i < numsSize; i++) {
    if (max[i] > res)
      res = max[i];
  }
  return res;
}
