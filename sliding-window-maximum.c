/*
https://leetcode.com/problems/sliding-window-maximum/

It gets TLE. It suggests to use Dequeue instead of heap. But, I can see, heap will outperform Dequeue in some cases.
*/
void push_down (int *arr, int len, int parent_idx)
{
  int left_idx = (parent_idx << 1) + 1, right_idx = (parent_idx << 1) + 2;
  int max_child_idx = -1, tmp;
  
  if (left_idx < len)
    max_child_idx = left_idx;
  
  if (right_idx < len && arr[right_idx] > arr[max_child_idx]) {
    max_child_idx = right_idx;
  }
  
  if (max_child_idx >=0 && arr[max_child_idx] > arr[parent_idx]) {
    tmp = arr[parent_idx];
    arr[parent_idx] = arr[max_child_idx];
    arr[max_child_idx] = tmp;
    push_down (arr, len, max_child_idx);
  }
}

void construct_heap (int *arr, int len)
{
  int last_idx = len - 1, i, j;
  int last_parent_idx = (last_idx - 1) >> 1;
  
  for (i = last_parent_idx; i >= 0; i--) {
    push_down (arr, len, i);
  }
}

void construct_heap_from_idx (int *arr, int len, int start)
{
  int i;
  
  for (i = start; i >= 0; i--) {
    push_down (arr, len, i);
  }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
  int i, j;
  int *heap = (int *) malloc (k * sizeof (int));
  int res_cnt = numsSize - k + 1;
  *returnSize = res_cnt;
  int *res = (int *) malloc (res_cnt * sizeof (int));
  int to_remove;
  
  memcpy (heap, nums, k * sizeof (int));

  construct_heap (heap, k);  
  
  for (i = 0; i <= numsSize - k; i++) {
    res[i] = heap[0];
    if (i + k < numsSize) {
      to_remove = nums[i];
      for (j = 0; j < k; j++) {
        if (heap[j] == to_remove) {
          heap[j] = nums[i + k];
          if (nums[i + k] > to_remove)
            construct_heap_from_idx (heap, k, j);
          else 
            push_down (heap, k, j);
          break;
        }
      }
    }
  }
  return res;
}
