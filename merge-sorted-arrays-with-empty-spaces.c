/*
https://www.geeksforgeeks.org/merge-one-array-of-size-n-into-another-one-of-size-mn/
*/
#include <stdio.h>

void merge (int *arr1, int *arr2, int arr1_len, int arr2_len)
{
  int i, num_space, j, k;
  for (i = arr1_len - 1, num_space = 0; i >= 0; i--) {
    if (arr1[i] == -1) {
      num_space++;
    } else if (num_space) {
      arr1[i + num_space] = arr1[i];
    }
  }

  k = 0;
  i = arr2_len;
  j = 0;
  while (i < arr1_len && j < arr2_len) {
    arr1[k++] = (arr1[i] <= arr2[j]) ? arr1[i++] : arr2[j++];
  }

  while (j < arr2_len) {
    arr1[k++] = arr2[j++];
  }
}

void main ()
{
  int arr1[] = {-1, 2, -1, 5, -1, 6, 9, -1, -1, 11};
  int arr2[] = {1, 3, 7, 12, 13};
  
  int arr1_len = sizeof (arr1) / sizeof (arr1[0]);
  int arr2_len = sizeof (arr2) / sizeof (arr2[0]);

  merge (arr1, arr2, arr1_len, arr2_len);

  for (int i = 0; i < arr1_len; i++) {
    printf ("%d ", arr1[i]);
  }
  printf ("\n");
}
