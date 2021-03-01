/*
Reverse Bits: Given a 32 bit number X, reverse its binary form and print the answer in decimal.

Input:
X = 1
Output:
2147483648 
Explanation:
Binary of 1 in 32 bits representation-
00000000000000000000000000000001
Reversing the binary form we get, 
10000000000000000000000000000000,
whose decimal value is 2147483648.

Input:
X = 5
Output:
2684354560 
Explanation:
Binary of 5 in 32 bits representation-
00000000000000000000000000000101
Reversing the binary form we get, 
10100000000000000000000000000000,
whose decimal value is 2684354560.
*/
#include <stdio.h>

unsigned int reverse_bit (unsigned int a)
{
  int i;
  unsigned int out = 0;

  for (i = 0; i < 32; i++) {
    out <<= 1;
    out |= (a & 1);
    a >>= 1;
  }
  return out;
} 

void main ()
{
  unsigned int a = 1, b = 5;
  printf ("Reverse of %u is %u\n", a, reverse_bit(a));
  printf ("Reverse of %u is %u\n", b, reverse_bit(b));
  
  
}
