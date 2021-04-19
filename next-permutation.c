/*
https://leetcode.com/problems/next-permutation/

https://www.geeksforgeeks.org/find-the-next-lexicographically-greater-word-than-a-given-word/
*/
#include <stdio.h>

void next_perm (int *arr, int len)
{
  int i, j, smallest_idx, tmp;

  if (len == 1)
    return;

  for (i = len - 2; i >= 0; i--) {
    if (arr[i] < arr[i + 1])
      break;
  }

  //this is the last permutation. If you need to go to the first permutation, simply reverse the array
  if (i < 0) {
    return;
  }

  //find the smallest element that is greater than arr[i]
  smallest_idx = i + 1;
  for (j = i + 2; j < len; j++) {
    if (arr[j] > arr[i])
      smallest_idx = j;
    else
      break;
  }
  
  //swap arr[i] and arr[smallest_idx]
  tmp = arr[i];
  arr[i] = arr[smallest_idx];
  arr[smallest_idx] = tmp;

  //reverse arr[i+1...n]
  for (i = i + 1, j = len - 1; i < j; i++, j--) {
    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }
}

void main ()
{
//  int arr[] = {1, 2, 3, 4, 2, 1};
  int arr[] = {4, 2, 1};

  int len = sizeof (arr) / sizeof (arr[0]);

  next_perm (arr, len);

  printf ("Next permutation is = \n");
  for (int i = 0; i < len; i++)
    printf ("%d ", arr[i]);
  printf ("\n");
}
