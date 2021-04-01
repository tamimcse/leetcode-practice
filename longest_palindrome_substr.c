/*
https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lps_rec_inner (char str[], int start, int end, char *lps)
{
  if (end <= start)
    return 0;
  if (str[start] == str[end]) {
    lps[start] = 1;
    lps[end] = 1;
    return lps_rec_inner (str, start + 1, end - 1, lps) + 2;
  } else {
    int i;
    int len = strlen (str);
    char *new_lps1 = (char *) calloc (len, sizeof (*new_lps1));
    char *new_lps2 = (char *) calloc (len, sizeof (*new_lps2));
    int res1 = lps_rec_inner (str, start + 1, end, new_lps1);
    int res2 = lps_rec_inner (str, start, end - 1, new_lps2);
    if (res1 > res2) {
      for (i = 0; i < len; i++) {
        if (new_lps1[i])
          lps[i] = 1;
      }
    } else {
      for (i = 0; i < len; i++) {
        if (new_lps2[i])
          lps[i] = 1;
      }
    }
    free (new_lps1);
    free (new_lps2);
    return res1 > res2 ? res1 : res2;
  }
}

int lps_rec (char str[])
{
  int len = strlen (str);
  char *lps = (char *) calloc (len, sizeof (*lps)); 
  int res = lps_rec_inner (str, 0, len - 1, lps);
  printf ("longest palindrome substring = ");
  for (int i = 0; i < len; i++) {
    if (lps[i])
      printf ("%c", str[i]);
  }
  printf ("\n");
  return res;
}

int lps_dp (char str[])
{
  int i, x_idx, y_idx;
  int len = strlen (str);
  int *dp_arr = (int *) calloc (len * len, sizeof (*dp_arr));

  for (i = 0; i < len; i++)
    dp_arr[i * len + i] = 0;

  int distance = 0;
  for (i = 0; i < len; i++) {
    distance++;
//    printf ("distance = %d ", distance);
    for (x_idx = 0; x_idx < len - distance; x_idx++) {
      y_idx = x_idx + distance;
      if (str[x_idx] == str[y_idx]) {
        dp_arr[x_idx * len + y_idx] = 2 + dp_arr[(x_idx + 1) * len + (y_idx - 1)];
      } else {
        int left = dp_arr[x_idx * len + (y_idx - 1)];
        int down = dp_arr[(x_idx + 1) * len + y_idx];
        dp_arr[x_idx * len + y_idx] = left > down ? left : down;
      }
//      printf ("(%d, %d) = %d ", x_idx, y_idx, dp_arr[x_idx * len + y_idx]);
    }
//    printf ("\n");
  }
  return dp_arr[len - 1];
}

void main ()
{
  char str[] = "ilovecinncinati";
//  char str[] = "cincinatici";
  int res = lps_rec (str);
  printf ("Longest palindrom substring is of length %d \n", res);

  int res1 = lps_dp (str);
  printf ("Longest palindrom substring is of length %d \n", res1);
}
