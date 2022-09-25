/*
https://www.geeksforgeeks.org/merge-two-sorted-arrays-in-o1-extra-space-using-quicksort-partition/
*/
#include <stdio.h>
#include <stdlib.h>

int cmp (const void *a, const void *b)
{
  return *((int *)a) - *((int *)b);
}

void merge (int arr1[], int len1, int arr2[], int len2)
{
  int i, j, k, pivot, tmp, leftmost_largest_idx;
  
  //find the pivot index
  i = 0;
  j = 0;
  k = 0;
  while (k != len1) {
    if (arr1[i] <= arr2[j])
      i++;
    else
      j++;
    k++;
  }

  //pivot is already positioned in the right place
  if (i == len1)
    return;
  
  pivot = (arr1[i] <= arr2[j]) ? arr1[i] : arr2[j];

  for (i = 0; i < len1; i++) {
    if (arr1[i] >= pivot) {
      leftmost_largest_idx = i;
      break;
    }
  }

  for (i = 0; i < len2; i++) {
    if (arr2[i] < pivot) {
      tmp = arr1[leftmost_largest_idx];
      arr1[leftmost_largest_idx] = arr2[i];
      arr2[i] = tmp;
      leftmost_largest_idx++;
      if (leftmost_largest_idx == len1)
        break;
    }
  }

  qsort (arr1, len1, sizeof (int), cmp);
  qsort (arr2, len2, sizeof (int), cmp);
}

void main ()
{
  int i;
  //int arr1[] = {3, 4, 5};
  //int arr2[] = {1, 2, 3};

  int arr1[] = {1, 5, 9, 10, 15, 20};
  int arr2[] = {2, 3, 8, 13};

  int len1 = sizeof (arr1) / sizeof (arr1[0]);
  int len2 = sizeof (arr2) / sizeof (arr2[0]);

  merge (arr1, len1, arr2, len2);

  printf ("arr1 = ");
  for (i = 0; i < len1; i++)
    printf ("%d ", arr1[i]);
  printf ("\n");

  printf ("arr2 = ");
  for (i = 0; i < len2; i++)
    printf ("%d ", arr2[i]);
  printf ("\n");
}
