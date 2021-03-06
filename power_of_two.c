/*
How to check a number, whether it is power of 2 or not, in as single statement.
*/
#include <stdio.h>

void main ()
{
  int n = 16;

  if (n != 0 && (n & (n - 1)) == 0 )
    printf ("%d is power of twwo\n", n);
  else
    printf ("%d is not a power of two\n", n);
}
