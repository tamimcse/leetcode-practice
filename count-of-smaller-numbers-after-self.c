/*
https://leetcode.com/problems/count-of-smaller-numbers-after-self/
*/
struct cell {
  int num;
  int idx;
};

void merge_sort (struct cell *arr, int start, int end, struct cell *new_arr, int *res)
{
  int i, j, k, m;
  struct cell tmp, to_insert;
  if (start == end)
    return;
  int mid = (start + end) >> 1;
  merge_sort (arr, start, mid, new_arr, res);
  merge_sort (arr, mid + 1, end, new_arr, res);
  //now merge two arrays!!!!
  i = mid, j = end, k = end - start;
  while (i >= start && j >= mid + 1) {
    if (arr[i].num <= arr[j].num) {
      new_arr[k--] =  arr[j--];  
    } else {
      res[arr[i].idx] += j - mid;
      new_arr[k--] = arr[i--];
    }
  }
  while (i >= start) {
    new_arr[k--] = arr[i--];
  }
  while (j >= mid + 1) {
    new_arr[k--] = arr[j--];
  }
  memcpy (arr + start, new_arr, (end - start + 1) * sizeof (*new_arr));
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSmaller(int* nums, int numsSize, int* returnSize){
  int i, j;
  int *res = (int *) calloc (numsSize, sizeof (*res));
  *returnSize = numsSize;
  struct cell *cells = (struct cell *) malloc (numsSize * sizeof (*cells));
  struct cell *tmp_cells = (struct cell *) malloc (numsSize * sizeof (*tmp_cells));
  for (i = 0; i < numsSize; i++) {
    cells[i].num = nums[i];
    cells[i].idx = i;
  }
  
  merge_sort (cells, 0, numsSize - 1, tmp_cells, res);
  return res;
}
