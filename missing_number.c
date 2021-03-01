/*
Missing number in array: Given an array of size N-1 such that it can only contain distinct integers in the range of 1 to N. Find the missing element.

Input:
N = 5
A[] = {1,2,3,5}
Output: 4

Input:
N = 10
A[] = {1,2,3,4,5,6,7,8,10}
Output: 9
*/
#include <stdio.h>

void main ()
{
  int i, sum = 0;
  int arr [] = {1,2,3,4,5,6,7,8,10};
  int size = sizeof (arr) / sizeof (arr[0]);
  
  for (i = 0; i < size; i++) {
    sum += arr[i];
  }

  //expected sum
  int n = size + 1;
  int expected_sum = (n * (n + 1)) >> 1;

  printf ("Missing number is %d \n", expected_sum - sum);
}
