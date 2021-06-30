/*
https://leetcode.com/problems/count-of-range-sum/

My merge sort is also getting TLE.
*/

/*
//O(n^2) approach
int countRangeSum(int* nums, int numsSize, int lower, int upper){
  long *prefix_sum = (long *) calloc (numsSize + 1, sizeof (*prefix_sum));
  int i, j, k, row, col, count, idx;
  long range_sum;
  
  prefix_sum[0] = 0;
  for (i = 0; i < numsSize; i++) {
    prefix_sum[i+1] = prefix_sum[i] + nums[i];
  }
  
  count = 0;
  for (i = 0; i < numsSize; i++) {
    for (j = i; j < numsSize; j++) {
      range_sum = prefix_sum[j+1] - prefix_sum[i];
      if (range_sum >= lower && range_sum <= upper)
        count++;
    }
  }
  return count;
}
*/
void merge_sort (long *arr, int start, int end, int *count, int lower, int upper, long *tmp_arr)
{
  //printf ("start = %d end = %d \n", start, end);
  int i, j, k, m, sum;
  if (start == end) {
    if (arr[start] >= lower && arr[start] <= upper)
      (*count)++;
    return;
  }
  int mid = (start + end) >> 1;
  merge_sort (arr, start, mid, count, lower, upper, tmp_arr);
  merge_sort (arr, mid + 1, end, count, lower, upper, tmp_arr);
  //count
  for (i = start; i <= mid; i++) {
    int hi = mid + 1;
    while (hi <= end && arr[hi] - arr[i] < lower)
      hi++;
    int lo = end;
    while (lo >= hi && arr[lo] - arr[i] > upper)
      lo--;
    if (lo >= hi)
      *count += lo - hi + 1;
  }
  //merge
  i = start;
  j = mid + 1;
  k = 0;
  while (i <= mid && j <= end) {
    tmp_arr[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
  }
  while (i <= mid)
    tmp_arr[k++] = arr[i++];
  while (j <= end)
    tmp_arr[k++] = arr[j++];
  memcpy (arr + start, tmp_arr, (end - start + 1) * sizeof (*tmp_arr));
}


int countRangeSum(int* nums, int numsSize, int lower, int upper){
  int i, j, k, m;
  long *prefix_sum = (long *) calloc (numsSize, sizeof (*prefix_sum));
  long *tmp_arr = (long *) calloc (numsSize, sizeof (*tmp_arr));
  int count = 0;
  
  prefix_sum[0] = nums[0];
  for (i = 1; i < numsSize; i++) {
    prefix_sum[i] = prefix_sum[i - 1] + nums[i];
  }
  merge_sort (prefix_sum, 0, numsSize-1, &count, lower, upper, tmp_arr);
  return count;
}
