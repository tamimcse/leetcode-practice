/*
https://leetcode.com/problems/super-egg-drop/
*/
#include <stdio.h>

int superEggDrop_inner(int k, int start, int end)
{
  int mid, res1, res2, max;
  printf ("k = %d start = %d end = %d \n", k, start, end);

  if (end < start)
    return 0;
  if (start == end)
    return 1;
  if (k == 1)
    return end - start + 1;
  mid = (start + end) >> 1;
  res1 = superEggDrop_inner (k, mid + 1, end);
  res2 = superEggDrop_inner (k - 1, start, mid-1);
  max = res1 > res2 ? res1 : res2;
  return max + 1;
}

int superEggDrop(int k, int n){
  return superEggDrop_inner (k, 1, n);
}

void main  ()
{
  int n = 14, k = 3;

  int res = superEggDrop (k, n);

  printf ("res = %d \n", res);
}
