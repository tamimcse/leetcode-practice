/*
https://leetcode.com/problems/reverse-pairs/
*/
void merge_sort (int* nums, int *tmp_arr, int start, int end, int *count)
{
  int i, j, k;
  long long tmp;
  if (start == end)
    return;
  int mid = (start + end) >> 1;
  
  merge_sort (nums, tmp_arr, start, mid, count);
  merge_sort (nums, tmp_arr, mid + 1, end, count);
  //count
  int hi = end; 
  for (i = mid; i >= start; i--) {
    while (hi >= mid + 1 && (long long)nums[hi] * 2 >= nums[i])
      hi--;
    if (hi >= mid + 1)
      *count += (hi - mid);
  }
  //merge
  i = start;
  j = mid + 1;
  k = 0;
  while (i <= mid && j <= end) {
    tmp_arr[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];
  }
  while (i <= mid)
    tmp_arr[k++] = nums[i++];
  while (j <= end)
    tmp_arr[k++] = nums[j++];
  memcpy (nums + start, tmp_arr, (end - start + 1) * sizeof (*tmp_arr));
}

int reversePairs(int* nums, int numsSize){
  int *tmp_arr = (int *) malloc (numsSize * sizeof (*tmp_arr));
  int count = 0;
  
  merge_sort (nums, tmp_arr, 0, numsSize - 1, &count);
  return count;
}
