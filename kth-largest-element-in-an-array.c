/*
https://leetcode.com/problems/kth-largest-element-in-an-array/
*/
void bubble_down (int *arr, int arr_len, int idx)
{
  int tmp;
  int left_child_idx = (idx << 1) + 1, right_child_idx = (idx << 1) + 2;
  
  if (left_child_idx >= arr_len && right_child_idx >= arr_len)
    return;
    
  int max_child_idx = - 1;
  
  if (right_child_idx < arr_len)
    max_child_idx = arr[left_child_idx] >= arr[right_child_idx] ? left_child_idx : right_child_idx;
  else 
    max_child_idx = left_child_idx;
  
  if (arr[max_child_idx] > arr[idx]) {
    tmp = arr[idx];
    arr[idx] = arr[max_child_idx];
    arr[max_child_idx] = tmp;
    bubble_down (arr, arr_len, max_child_idx);
  }
}

int findKthLargest(int* nums, int numsSize, int k){
  int parent_idx = (numsSize - 2) >> 1, i, j, num;
  
  for (i = parent_idx; i >= 0; i--) {
    bubble_down (nums, numsSize, i);
  }
  
  for (i = 0; i < k; i++) {
    num = nums[0];
    nums[0] = nums[--numsSize];
    bubble_down (nums, numsSize, 0);
  }
  
  return num;
}
