/*
Count how many times an integer occurs in an array of intervals.
*/
#include <stdio.h>

int interval_search (int arr[][2], int num_row, int target)
{
  int i;
  //assume that all the intervals are smaller than 100
  int freq[100] = {0};

  //preprocessing
  for (i = 0; i < num_row; i++) {
    freq[arr[i][0]]++;
    freq[arr[i][1] + 1]--;
  }
  for (i = 1; i < 100; i++) {
    freq[i] += freq[i - 1];
  }
  
  //actual search is O(1)
  return freq[target];
}

void main ()
{
  int arr[][2] = {{1, 10}, {5, 10}, {15, 25}, {7, 12}, {20, 25}};
  int num_row = sizeof (arr) / sizeof (arr[0]);
  int target = 8;
  
  int res = interval_search (arr, num_row, target);
  printf ("%d occurs %d times \n", target, res);

}
