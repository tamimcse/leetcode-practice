/*
https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/
*/
#include <stdio.h>
#include <stdlib.h>

enum state {ANY, LARGE, SMALL};

struct entry {
  int len;
  enum state s;
};

int longest_bitonic_sequence (int arr[], int len)
{
  int row, col, idx, i;
  struct entry *dp_arr = (struct entry *) calloc (len * len, sizeof (*dp_arr));


  for (row = 0; row < len; row++) {
    idx = row * len + row;
    dp_arr[idx].len = 1;
    dp_arr[idx].s = ANY;
  }

  for (row = 0; row < len - 1; row++) {
    idx = row * len + row + 1;
    dp_arr[idx].len = 2;
    dp_arr[idx].s = arr[row + 1] >= arr[row] ? LARGE : SMALL;
  }

  struct entry res1, res2;
  for (i = 2; i < len; i++) {
    for (row = 0, col = i; col < len; row++, col++) {
      idx = row * len + col;
      if (arr[col] < arr[col - 1]) {
        res1.len = dp_arr[row * len + col - 1].len + 1;
        res1.s = SMALL;
      } else {
        if (dp_arr[row * len + col - 1].s == LARGE || dp_arr[row * len + col - 1].s == ANY) {
          res1.len = dp_arr[row * len + col - 1].len + 1;
          res1.s = LARGE;
        } else {
          res1.len = dp_arr[row * len + col - 1].len;
          res1.s = SMALL;
        }
      }
      res2 = dp_arr[(row + 1) * len + col];
      dp_arr[idx] = (res1.len >= res2.len) ? res1 : res2;
    }
  }

  return dp_arr[len - 1].len;
}

void main ()
{
  int arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
  //int arr[] = {12, 11, 40, 5, 3, 1};
  //int arr[] = {80, 60, 30, 40, 20, 10};
  int len = sizeof (arr) / sizeof (arr[0]);
  int res = longest_bitonic_sequence (arr, len);
  printf ("Length of the longest bitonic subsequence is %d \n", res);

}
