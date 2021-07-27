/*
https://leetcode.com/problems/sliding-window-maximum/

It's a very interesting problem!!! You can use heap, but may not the way as it seems at the beginning. Simple heap may lead to TLE

You will find details discussion in note.
*/
struct elem {
  int val;
  int idx;
};
  
void push_up (struct elem *arr, int len, int child_idx)
{
  if (!child_idx)
    return;
  int parent_idx = (child_idx - 1) >> 1;
  
  int left_idx = (parent_idx << 1) + 1, right_idx = (parent_idx << 1) + 2;
  int max_child_idx = -1;
  struct elem tmp;
  
  if (left_idx < len)
    max_child_idx = left_idx;
  
  if (right_idx < len && arr[right_idx].val > arr[max_child_idx].val) {
    max_child_idx = right_idx;
  }
  
  if (max_child_idx >=0 && arr[max_child_idx].val > arr[parent_idx].val) {
    tmp = arr[parent_idx];
    arr[parent_idx] = arr[max_child_idx];
    arr[max_child_idx] = tmp;
    push_up (arr, len, parent_idx);
  }
}


void push_down (struct elem *arr, int len, int parent_idx)
{
  int left_idx = (parent_idx << 1) + 1, right_idx = (parent_idx << 1) + 2;
  int max_child_idx = -1;
  struct elem tmp;
  
  if (left_idx < len)
    max_child_idx = left_idx;
  
  if (right_idx < len && arr[right_idx].val > arr[max_child_idx].val) {
    max_child_idx = right_idx;
  }
  
  if (max_child_idx >=0 && arr[max_child_idx].val > arr[parent_idx].val) {
    tmp = arr[parent_idx];
    arr[parent_idx] = arr[max_child_idx];
    arr[max_child_idx] = tmp;
    push_down (arr, len, max_child_idx);
  }
}

void construct_heap (struct elem *arr, int len)
{
  int last_idx = len - 1, i, j;
  int last_parent_idx = (last_idx - 1) >> 1;
  
  for (i = last_parent_idx; i >= 0; i--) {
    push_down (arr, len, i);
  }
}

void heap_add (struct elem *arr, int size, int *len, struct elem to_add)
{
  if (*len == size)
    return;
  arr[*len] = to_add;
  (*len)++;
  push_up (arr, *len, *len - 1);
}

void heap_pop_root (struct elem *arr, int *len)
{
  arr[0] = arr[*len - 1];
  (*len)--;
  push_down (arr, *len, 0);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
  int i, j;
  struct elem *heap = (struct elem *) malloc (numsSize * sizeof (*heap));
  int heap_len;
  int res_cnt = numsSize - k + 1;
  *returnSize = res_cnt;
  int *res = (int *) malloc (res_cnt * sizeof (int));
  int to_remove;
  struct elem to_add;
    
  for (i = 0; i < k; i++) {
    heap[i].val = nums[i];
    heap[i].idx = i;
    heap_len++;
  }

  construct_heap (heap, heap_len);  
  
  for (i = 0; i <= numsSize - k; i++) {
    res[i] = heap[0].val;
    if (i + k < numsSize) {
      to_add = (struct elem) {nums[i + k], i + k};
      heap_add (heap, numsSize, &heap_len, to_add);
      while (heap[0].idx <= i) {
        heap_pop_root (heap, &heap_len);
      }
    }
  }
  return res;
}
