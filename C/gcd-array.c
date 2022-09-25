/*
https://www.geeksforgeeks.org/gcd-two-array-numbers/
*/
#include <stdio.h>

int gcd (int m, int n)
{
  //if n is smaller, swap them
  if (n < m) {
    int tmp = n;
    n = m;
    m = tmp;
  }

  int divisor = m;
  int divident = n;
  int tmp;
  while (divident % divisor) {
    tmp = divisor;
    divisor = divident % divisor;
    divident = tmp;
  }
  return divisor;
}

void main ()
{
  int arr[] = {12, 15, 30, 48};
  int res, i, arr_len = sizeof (arr) / sizeof (arr[0]);

  for (i = 1; i < arr_len; i++) {
    res = (i == 1) ? gcd (arr[0], arr[1]) : gcd (res, arr[i]);
  }
  printf ("GCD = %d \n", res);
}
