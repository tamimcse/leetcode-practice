/*
https://www.geeksforgeeks.org/sum-of-the-multiples-of-two-numbers-below-n/
*/
#include <stdio.h>

int gcd (int a, int b)
{
  int tmp;
  if (a > b) {
    tmp = a;
    a = b;
    b = tmp;
  }

  int devisor = a;
  int devident = b;
  while (devident % devisor) {
    devisor = devident % devisor;W
    devident = devisor;
  }
  return devisor;
}

int lcm_ (int a, int b)
{
  return (a * b) / gcd (a, b);
}

int sum_of_multiples_below_n(int a, int b, int n)
{
  int num_a = (n - 1) / a;
  int num_b = (n - 1) / b;
  int sum = ((a * num_a * (num_a + 1)) >> 1) + ((b * num_b * (num_b + 1)) >> 1);
  int lcm = lcm_ (a, b);
  printf ("lcm = %d \n", lcm);
  int num_lcm = (n - 1) / lcm;
  int lcm_sum = (lcm * num_lcm * (num_lcm + 1)) >> 1;
  return sum - lcm_sum;
}

void main ()
{
  int A = 2, B = 3, N = 20;
  int res = sum_of_multiples_below_n (A, B, N);
  printf ("The result is %d \n", res);
}
