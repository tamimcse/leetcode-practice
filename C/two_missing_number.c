/*
https://www.geeksforgeeks.org/find-two-missing-numbers-set-1-an-interesting-linear-time-solution/
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
void find_missing_numbers1 (int arr[], int len, int *res1, int *res2)
{
  int i;
  bool first_found = false;
  char *flag_arr = (char *)calloc (len + 2, sizeof (*flag_arr));

  for (i = 0; i < len; i++) {
    flag_arr[arr[i] - 1] = 1;
  }

  for (i = 0; i < len + 2; i++) {
    if (!flag_arr[i]) {
      if (!first_found) {
        *res1 = i + 1;
        first_found = true;
      } else {
        *res2 = i + 1;
        break;
      }
    }
  }
  free (flag_arr);
}

void find_missing_numbers2 (int arr[], int len, int *res1, int *res2)
{
  int i, sum, missing_sum, sum1;
  bool first_found = false;
   
  sum = 0;
  for (i = 0; i < len; i++) {
    sum += arr[i];
  }

  int right_len = len + 2;
  missing_sum = ((right_len * (right_len + 1)) >> 1) - sum;
  int missing_avg = missing_sum >> 1;

  //we assume the array is sorted
  sum1 = 0;
  for (i = 0; i < missing_avg - 1; i++) {
    sum1 += arr[i];
  }
  *res1 = ((missing_avg * (missing_avg + 1)) >> 1) - sum1;

  sum += *res1;
  *res2 = ((right_len * (right_len + 1)) >> 1) - sum;
}

void main ()
{
  int res1, res2;
  int arr[] = {1, 3, 5, 6};
  int len = sizeof (arr) / sizeof (arr[0]);

  find_missing_numbers1 (arr, len, &res1, &res2);
  printf ("Missing numbers are %d and %d \n", res1, res2);

  res1 = 0;
  res2 = 0; 
  find_missing_numbers2 (arr, len, &res1, &res2);
  printf ("Missing numbers are %d and %d \n", res1, res2);
}

