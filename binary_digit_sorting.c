/*
sort given binary digits in Input: 0010101001101, Output: 0000000011111111.
*/
#include <stdio.h>

int binary_digit_sorting_var1 (int a)
{
  int popcount = 0;

  while (a) {
    a = a & (a - 1);
    popcount++;
  }
  return (1 << popcount) - 1;
}

void main ()
{
  int i = 13, j = 10788;
  int sort_i = binary_digit_sorting_var1 (i);
  int sort_j = binary_digit_sorting_var1 (j);
  printf ("Sorting of %d is %d \n", i, sort_i);
  printf ("Sorting of %d is %d \n", j, sort_j);
}

