/*
https://leetcode.com/problems/contiguous-array/

Very very very interesting problem! Look at the approach #2 at

https://leetcode.com/problems/contiguous-array/solution/
*/

int findMaxLength(int* nums, int numsSize){
  int i, j, k, hash_size = (numsSize << 1) + 1, count = 0, max = 0;
  
  int *hash = (int *) malloc (hash_size * sizeof (int));
  
  for (i = 0; i < hash_size; i++)
    hash[i] = -1;
  
  hash[numsSize] = 0;
  for (i = 0; i < numsSize; i++) {
    count = nums[i] ? count + 1 : count - 1;
    if (hash[count + numsSize] == -1) {
      hash[count + numsSize] = i + 1;
    } else {
      if ((i + 1 - hash[count + numsSize]) > max)
        max = i + 1 - hash[count + numsSize];
    }
  }
  return max;
}
