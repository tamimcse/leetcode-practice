/*
https://leetcode.com/problems/the-kth-factor-of-n/
*/
int kthFactor(int n, int k){
  int len = sqrt (n), i, count1 = 0, count2 = 0;
  int *factor1 = (int *) calloc (len, sizeof (int));
  int *factor2 = (int *) calloc (len, sizeof (int));
  
  for (i = 1; i <= len; i++) {
    if (n % i == 0) {
      factor1[count1++] = i;
      if (i != n / i)
        factor2[count2++] = n / i;
    }
  }
  
  if (k > count1 + count2)
    return -1;
  if (k <= count1)
    return factor1[k - 1];
  else
    return factor2[count2 - (k - count1)];
}
