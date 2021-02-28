/*
K-th smallest element: Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Input:
N = 6
arr[] = 7 10 4 3 20 15
K = 3
Output : 7
Explanation :
3rd smallest element in the given 
array is 7.

Input:
N = 5
arr[] = 7 10 4 20 15
K = 4
Output : 15
Explanation :
4th smallest element in the given 
array is 15. 
*/
#include <stdio.h>

void heapify (int arr[], int size, int idx)
{
  int left_child, right_chield;//left and right chield index

  left_child = (i << 1) + 1;
  right_child = (i << 1) + 2;
  //min-heap property is violated
  if (arr[left_child] < arr[i] || arr[right_child] < arr[i]) {
    heapify (int arr[], int size, i);
  }
}

void build_min_heap (int arr[], int size)
{
  int last_idx = size - 1;
  int start_ix = (last_idx - 1) >> 1;//same as floor ((last_idx - 1)/2)
  int i;

  for (i = start_ix; i >= 0; i--) {
    heapify (arr, size, i);
  }
}

void main ()
{
  int arr[] = {7, 10, 4, 3, 20, 15, 20, 1, 24, 30};
}
