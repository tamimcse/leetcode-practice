/*
https://www.geeksforgeeks.org/swap-every-two-bits-bytes/
*/
#include <stdio.h>

int swap_every_two_bits (int a)
{
  int i;
  
  for (i = 31; i > 0; i -= 2) {
    int x1 = (a >> i) & 1;
    int x2 = (a >> (i - 1)) & 1;
    if (x1 != x2) {
      a = (x1 == 1) ? (((~(1 << i)) & a) | (1 << (i - 1))) : ((a | (1 << i)) & (~(1 << (i - 1))));
      printf ("a = %d\n", a);
    } 
  }
  return a;
}

void main ()
{
  int a = 0b101010011011;
  int res = swap_every_two_bits (a);
  printf ("%d res = %d \n", a, res);
}
