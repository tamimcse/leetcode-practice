/*
https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
*/
#include <stdio.h>
#include <stdlib.h>

void longest_increasing_subseq (int arr[], int len)
{
  int i, j, max_lis, prev, max_idx, curr_idx;
  int *dp_arr = (int *) calloc (len, sizeof (*dp_arr));
  int *dp_arr_prev = (int *) calloc (len, sizeof (*dp_arr_prev));
  int *res = (int *) calloc (len, sizeof (*res));

  for (i = 0; i < len; i++) {
    max_lis = 0;
    prev = -1;
    for (j = i - 1; j >= 0; j--) {
      if (arr[i] > arr[j] && dp_arr[j] > max_lis) {
        max_lis = dp_arr[j];
        prev = j;
      }
    }
    dp_arr[i] = max_lis + 1;
    dp_arr_prev[i] = prev;
  }

  max_lis = 0;
  max_idx = -1;
  for (i = 0; i < len; i++) {
    if (dp_arr[i] > max_lis) {
      max_idx = i;
      max_lis = dp_arr[i];
    }
  }

  printf ("Length of the longest increasing subsequence is %d \n", max_lis);

  for (i = max_lis - 1, curr_idx = max_idx; i >= 0; i--, curr_idx = dp_arr_prev[curr_idx]) {
    res [i] = arr[curr_idx];
  }

  printf ("longest increasing subsequence is = ");
  for (i = 0; i < max_lis; i++) {
    printf ("%d ", res[i]);
  }
  printf ("\n");
}

void main ()
{
//  int arr[] = {3, 10, 2, 1, 20};
  int arr[] = {50, 3, 10, 7, 40, 80};
  int len = sizeof (arr) / sizeof (arr[0]);

  longest_increasing_subseq (arr, len);
}
