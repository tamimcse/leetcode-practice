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

void heapify (int arr[], int size, int i)
{
  int left_chield, right_chield;//left and right chield index
  int tmp;
  int smaller_index = -1;

  left_chield = (i << 1) + 1;
  right_chield = (i << 1) + 2;
  if (left_chield < size && arr[left_chield] < arr[i])
    smaller_index = left_chield;
  else
    smaller_index = i;
  if (right_chield < size && arr[right_chield] < arr[smaller_index])
    smaller_index = right_chield;
  //heap property is violated
  if (smaller_index != i) {
    tmp = arr[i];
    arr[i] = arr[smaller_index];
    arr[smaller_index] = tmp;
    heapify (arr, size, smaller_index);
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

void print (int arr[], int size)
{
  int i;

  for (i = 0; i < size; i++) {
    printf ("%d ", arr[i]);
  }
  printf ("\n");
}

int remove_min (int arr[], int *size)
{
  int smallest = arr[0];
  arr[0] = arr[--(*size)];
  heapify (arr, *size, 0);
  return smallest;
}

void main ()
{
  int i;
  int k;
  int kth_number;
  int arr[] = {100, 90, 80, 70, 7, 10, 4, 3, 20, 15, 1, 24, 30};
  int arr_size = sizeof (arr) / sizeof (arr[0]);

  printf ("Enter the value of k = ");
  scanf ("%d", &k);  
  if (k > arr_size) {
    printf ("The value of k exceeds the size of the array\n");
    return;
  }

  build_min_heap (arr, arr_size);
  printf ("Printing heap = ");
  print (arr, arr_size);

  for (i = 0; i < k; i++) {
    kth_number = remove_min(arr, &arr_size); 
  }
  printf ("%d-th smallest number is %d\n", k, kth_number);
}
