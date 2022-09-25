/*
Find the Euler Totient Function (ETF) Φ(N) for an input N. ETF is the count of numbers in {1, 2, 3, …, N} that are relatively prime to N, i.e., the numbers whose GCD (Greatest Common Divisor) with N is 1.

Input:
N = 11
Output:
10
Explanation:
From 1 to 11,
1,2,3,4,5,6,7,8,9,10
are relatively prime to 11.

Input:
N = 16
Output:
8
Explanation:
From 1 to 16
1,3,5,7,9,11,13,15 
are relatively prime
to 16.
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

int relatively_prime (int m, int n)
{
  return gcd (m, n) == 1;
}

void main ()
{
  int n = 16;
  int i, count = 0;

  printf ("relative primes are ");
  for (i = 1; i <= n; i++) {
    if (relatively_prime (i, n)) {
      printf ("%d ", i); 
      count++;
    }
  }
  printf ("\n");

  printf ("ETF of %d is %d \n", n, count);
}
