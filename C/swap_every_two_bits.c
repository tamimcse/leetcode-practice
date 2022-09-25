/*
https://www.geeksforgeeks.org/swap-every-two-bits-bytes/
*/
#include <stdio.h>

int swap_every_two_bits1 (int a)
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

int swap_every_two_bits2 (int a)
{
  return ((a & 0b10101010101010101010101010101010) >> 1) | ((a & 0b01010101010101010101010101010101) << 1);
}

void main ()
{
  int a = 0b101010011011;
  int res1 = swap_every_two_bits1 (a);
  int res2 = swap_every_two_bits2 (a);
  printf ("%d res1 = %d res2 = %d\n", a, res1, res2);
}
