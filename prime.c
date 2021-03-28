/*
Check if a number is a prime number or not
*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime (int a)
{
  int i;

  if (a == 1 || a == 2)
    return true;
  if ((a & 1) == 0)
    return false;
  for (i = 3; i <= sqrt(a); i++) {
    if (a % i == 0)
      return false;
  }
  return true;
}

void main ()
{
  int i;

  for (i = 0; i < 100; i++) {
    bool res = is_prime (i);
    printf ("%d %s prime \n", i, res ? "is" : "is not");
  }
}
