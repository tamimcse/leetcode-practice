/*
https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
*/
#include <stdio.h>
#include <stdlib.h>

int largest_subarray_sum_dp (int *arr, int len)
{
  int *dp_sum = (int *) calloc (len, sizeof (*dp_sum));
  int *dp_prev = (int *) calloc (len, sizeof (*dp_prev));
  int i;

  dp_sum[0] = arr[0];
  for (i = 1; i < len; i++) {
    if (dp_sum[i - 1] > 0) {
      dp_sum[i] = dp_sum[i - 1] + arr[i];
      dp_prev[i] = 1;
    } else {
      dp_sum[i] = arr[i];
    }
  }

  int max_idx = 0;
  for (i = 1; i < len; i++) {
    if (dp_sum[i] > dp_sum[max_idx])
      max_idx = i;
  }

  i = max_idx;
  while (1) {
    printf ("%d ", arr[i]);
    if (!dp_prev[i])
      break;
    else
      i--;
  }
  printf ("\n");

  return dp_sum[max_idx];
}

int largest_subarray_sum (int *arr, int len)
{
  int i, max_sum, sum_so_far;

  max_sum = arr[0];
  sum_so_far = arr[0];
  for (i = 1; i < len; i++) {
    if (sum_so_far > 0)
      sum_so_far += arr[i];
    else
      sum_so_far = arr[i];

   if (sum_so_far > max_sum)
     max_sum = sum_so_far;
  }

  return max_sum;
}

void main ()
{
//  int arr[] = {2, -3, 1, 10, -3, 5, 4, -2, -3, 4};
  int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
   
  int len = sizeof (arr) / sizeof (arr[0]);

  int res_dp = largest_subarray_sum_dp (arr, len);
  int res = largest_subarray_sum (arr, len);

  printf ("largest array sum = %d %d \n", res_dp, res);
}
