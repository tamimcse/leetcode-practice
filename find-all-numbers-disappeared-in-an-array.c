/*
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

How would you do it without extra space? One solution is to use the array inself as a hash. You can make the array element negative if the corresponding element exists...Thus negative number will indicate if the number has be seen or not.
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
  int *hash = (int *) calloc (numsSize, sizeof (*hash));
  int i, j, k;
  int *res = (int *) malloc (numsSize * sizeof (*res));
  int res_cnt = 0;
  
  for (i = 0; i < numsSize; i++) {
    hash[nums[i] - 1] = 1;
  }
  
  for (i = 0; i < numsSize; i++) {
    if (!hash[i])
      res[res_cnt++] = i + 1;
  }
  *returnSize = res_cnt;
  return res;
}
