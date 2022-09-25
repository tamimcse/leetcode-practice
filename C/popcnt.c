/*
Number of 1 Bits: 

Input:
N = 6
Output:
Explanation:
Binary representation is '110' 
So the count of the set bit is 2.
*/
#include <stdio.h>

int popcount (unsigned int i)
{
  int count = 0;

  while (i) {
    i = i & (i - 1);
    count++;
  }
  return count;
}

void main ()
{
  int i = 39;
  int popcnt = popcount (i);
  printf ("popcnt of %d is %d \n", i, popcnt);

}
