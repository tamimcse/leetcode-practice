/*
https://www.geeksforgeeks.org/program-for-armstrong-numbers/
*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_armstrong (int a)
{
  int i, sum = 0, digit, b = a;
  int num_digit = (a % 10) ? ceil (log10 (a)) : log10 (a) + 1;
  
  while (a) {
    digit = a % 10;
    sum += pow (digit, num_digit);
    a = a / 10;
  }
  return sum == b; 
}

void main ()
{
  int arr [] = {153, 120, 1253, 1634};
  int i;

  for (i = 0; i < sizeof (arr) / sizeof (arr[0]); i++) {
    bool res = is_armstrong (arr[i]);
    printf ("%d %s an armstrong number\n", arr[i], res ? "is" : "is not");
  }
}
