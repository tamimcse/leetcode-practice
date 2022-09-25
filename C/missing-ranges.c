/*
https://leetcode.com/problems/missing-ranges/
*/
void add_res (int start, int end, char **res, int *res_cnt)
{
  char *new_res = (char *) calloc (30, sizeof (char));;
  
  if (start == end) {
    sprintf (new_res, "%d", start);
  } else {
    sprintf (new_res, "%d->%d", start, end);
  }
  res[(*res_cnt)++] = new_res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findMissingRanges(int* nums, int numsSize, int lower, int upper, int* returnSize){
  int i;
  char **res = (char **) malloc (1000 * sizeof (*res));
  int res_cnt = 0;
  
  if (!numsSize) {
    add_res (lower, upper, res, &res_cnt);
    *returnSize = 1;
    return res;
  }
  
  if (lower < nums[0])
    add_res (lower, nums[0] - 1, res, &res_cnt);
  
  for (i = 0; i < numsSize - 1; i++) {
    if (nums[i + 1] > nums[i] + 1) {
      add_res (nums[i] + 1, nums[i+1] - 1, res, &res_cnt);
    }
  }
  
  if (nums[numsSize - 1] < upper)
    add_res (nums[numsSize - 1] + 1, upper, res, &res_cnt);
  
  *returnSize = res_cnt;
  return res;
}
