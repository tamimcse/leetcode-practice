/*
https://www.geeksforgeeks.org/find-largest-prime-factor-number/
*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int max_prime_factor (int a)
{
  int i;

  if (a == 1)
    return 1;
  while ((a & 1) == 0) {
      a = a >> 1;
  }
  if (a == 1)
    return 2;
  for (i = sqrt(a); i >= 3; i--) {
    if (a % i == 0)
      return a / i;
  }
  return a;
}

void main ()
{
  int i;

  for (i = 1; i < 100; i++) {
    int res = max_prime_factor (i);
    printf ("Max prime factor of %d is %d \n", i, res);
  }
}
