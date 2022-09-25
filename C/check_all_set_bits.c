/*
https://www.geeksforgeeks.org/check-bits-number-set/
*/
#include <stdio.h>

int check_set_bits (int a)
{
  if (!a)
    return 0;
  return ((a & (a + 1))) ? 0 : 1;
}

void main ()
{
  int a = 14;
  int res = check_set_bits (a);
  if (res)
    printf ("All bits of %d are set \n", a);
  else
    printf ("All bits of %d are not set \n", a);
}
