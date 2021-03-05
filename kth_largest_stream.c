/*
Kth largest element in a stream: Given an input stream arr[] of n integers, find the kth largest element for each element in the stream.

Input:
k = 4, n = 6
arr[] = {1, 2, 3, 4, 5, 6}
Output:
-1 -1 -1 1 2 3
Explanation:
k = 4
For 1, the 4th largest element doesn't
exist so we print -1.
For 2, the 4th largest element doesn't
exist so we print -1.
For 3, the 4th largest element doesn't
exist so we print -1.
For 4, the 4th largest element is 1.
For 5, the 4th largest element is 2.
for 6, the 4th largest element is 3.

Input:
k = 1, n = 2
arr[] = {3, 4}
Output:
3 4 
Explanation: 
For the 1st and 2nd element the 1st largest 
element is itself.
*/
#include <stdio.h>
#include <stdlib.h>

void heapify (int *heap, int size, int idx)
{
  int tmp;
  int left_idx = (idx << 1) + 1;
  int right_idx = (idx << 1) + 2;
  int smallest_index;
  if (left_idx < size && heap[idx] > heap[left_idx])
    smallest_index = left_idx;
  else
    smallest_index = idx;
  if (right_idx < size && heap[smallest_index] > heap[right_idx])
    smallest_index = right_idx;

  if (smallest_index != idx) {
    tmp = heap[idx];
    heap[idx] = heap[smallest_index];
    heap[smallest_index] = tmp;
    heapify (heap, size, smallest_index);
  }
}

//This function inserts a new element and returns root of the heap. Here we
//assume that all the numbers will be greater than -1.
int minheap_insert (int *heap, int size, int a)
{
  if (heap[0] == -1 || heap[0] < a) {
    heap[0] = a;
    heapify (heap, size, 0);
  }
  return heap[0];
} 

void main ()
{
  int i;
  int arr [] = {3, 7, 1, 2, 5, 4, 9, 6, 12, 13, 2, 3, 14};
  int len = sizeof (arr) / sizeof (arr[0]);
  int k = 4;

  //create a min-heap of size k
  int *min_heap = (int *) malloc (k * sizeof (*min_heap));
  for (i = 0; i < k; i++) {
    min_heap[i] = -1;
  }

  int output;
  for (i = 0; i < len; i++) {
    output = minheap_insert (min_heap, k, arr[i]);
    printf ("%d ", output);
  }
  printf ("\n");
}
