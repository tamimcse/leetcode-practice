/*
https://www.geeksforgeeks.org/sort-array-wave-form-2/


Note that, it will only work if all the elements are distinct. If some elements are same, it will not work. For details, take a look at the note.
*/
#include <stdio.h>
#include <stdlib.h>

int cmp (const void *a, const void *b)
{
  return *((int *)a) - *((int *)b);
}

void wave_sort (int *arr, int len)
{
  int i, tmp;

  qsort (arr, len, sizeof (arr[0]), cmp);
  for (i = 0; i < len - 1; i += 2) {
    int tmp = arr[i];
    arr[i] = arr[i + 1];
    arr[i + 1] = tmp;
  }
}

void main ()
{
  int arr[] = {10, 5, 6, 3, 2, 20, 100, 80};
  int len = sizeof (arr) / sizeof (arr[0]);
  wave_sort (arr, len);

  for (int i = 0; i < len; i++)
    printf ("%d ", arr[i]);
  printf ("\n");
}
