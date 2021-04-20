/*
https://www.geeksforgeeks.org/merge-two-sorted-arrays-o1-extra-space/

https://www.geeksforgeeks.org/merge-two-sorted-arrays-in-o1-extra-space-using-quicksort-partition/

https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/

This is a very common question!!
*/
#include <stdio.h>

void merge (int arr1[], int len1, int arr2[], int len2)
{
  int i, j;

  for (i = len2 - 1; i >= 0; i--) {
    if (arr2[i] < arr1[len1 - 1]) {
      //swap the two numbers
      int tmp = arr2[i];
      arr2[i] = arr1[len1 - 1];
      arr1[len1 - 1] = tmp;
      //sort arr1 in insertion sort fashion
      for (j = len1 - 2; j >= 0; j--) {
        if (arr1[j] > tmp) {
          arr1 [j + 1] = arr1[j];
        } else {    
          break;
        }
      }
      arr1 [j + 1] = tmp;
    }
  }
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
