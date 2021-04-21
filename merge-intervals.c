/*
https://www.geeksforgeeks.org/merging-intervals/
*/
#include <stdio.h>
#include <stdlib.h>

int cmp (const void *a, const void *b)
{
  return *((int *)a) - *((int *)b);
}

int merge_intervals (int arr[][2], int len, int *res, int *res_cnt)
{
  int i, j;
  qsort (arr, len, 2 * sizeof (int), cmp);

  i = 0; j = 1;
  res[0] = arr[0][0];
  res[1] = arr[0][1];
  while (j < len) {
    if (arr[j][0] < res[i * 2 + 1]) {
      res[i * 2 + 1] = arr[j][1];
    } else {
      i++;
      res[i*2] = arr[j][0];
      res[i*2+1] = arr[j][1];
    }
    j++;
  }

  *res_cnt = i + 1;
}

void main ()
{
  int arr[][2] = {{1, 3}, {5, 7}, {2, 4}, {6, 8}};
  int arr_len = sizeof (arr) / sizeof (arr[0]);

  int *res = (int *) calloc (arr_len * 2, sizeof (*res)); 
  int res_cnt = 0;

  merge_intervals (arr, arr_len, res, &res_cnt);

  for (int i = 0; i < res_cnt; i++) {
    printf ("(%d, %d) ", res[i * 2], res[i * 2 + 1]);
  }
  printf ("\n");
}
