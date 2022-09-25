/*
https://leetcode.com/problems/counting-bits/
*/
int count_set_bits (int a )
{
  int count = 0;
  while (a) {
    a = a & (a - 1);
    count++;
  }
  return count;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
  int *res = (int *) calloc (n + 1, sizeof (*res));
  int i, j;

  for (i = 1; i <= n; i++) {
    res[i] = count_set_bits (i);
  }
  *returnSize = n + 1;
  return res;
}
