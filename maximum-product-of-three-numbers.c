/*
https://leetcode.com/problems/maximum-product-of-three-numbers/

Very very very interesting problem !!!!!!
*/
int cmp (const void *a, const void *b)
{
  return *((int *)a) - *((int *)b); 
}

int max (int a, int b)
{
  return a > b ? a : b;
}

int maximumProduct(int* nums, int numsSize){
  if (numsSize == 3)
    return nums[0] * nums[1] * nums[2];
  
  qsort (nums, numsSize, sizeof (int), cmp);
  
  if (nums[0] >= 0) {
    return nums[numsSize - 3] * nums[numsSize - 2] * nums[numsSize - 1];
  }
  
  return max (nums[numsSize - 3] * nums[numsSize - 2] * nums[numsSize - 1],
             nums[0] * nums[1] * nums[numsSize - 1]);
}
