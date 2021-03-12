/*
Count ways to reach the n’th stair: There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top.

Input: n = 1
Output: 1
There is only one way to climb 1 stair

Input: n = 2
Output: 2
There are two ways: (1, 1) and (2)

Input: n = 4
Output: 5
(1, 1, 1, 1), (1, 1, 2), (2, 1, 1), (1, 2, 1), (2, 2)
*/
#include <stdio.h>

int stair_case(int n)
{
  int i, sum;

  if (n <= 0)
    return 0;
  else if (n == 1)
    return 1;
  else if (n == 2)
    return 2;
  else {
    return stair_case (n - 1) + stair_case (n - 2);
  }
}

void main ()
{
  int n = 9;
  int res = stair_case (n);
  printf ("Number of ways to reach %d stairs with maximum 2 step is %d \n", n, res);
}
