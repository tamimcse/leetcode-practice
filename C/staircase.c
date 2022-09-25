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
#include <stdlib.h>

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

int stair_case_dp(int n)
{
  int *dp_arr = (int *) calloc (n + 1, sizeof (*dp_arr));
  dp_arr[0] = 0;
  dp_arr[1] = 1;
  dp_arr[2] = 2;
  int i;

  for (i = 3; i <= n; i++) {
    dp_arr[i] = dp_arr[i - 1] + dp_arr[i - 2];
  }
  return dp_arr[n];
}

//check beneath main
void main ()
{
  int n = 9;
  int res = stair_case (n);
  int dp_res = stair_case_dp (n);
  printf ("Number of ways to reach %d stairs with maximum 2 step is %d DP result %d \n", n, res, dp_res);
}

/*
https://leetcode.com/problems/climbing-stairs/

int climbStairs(int n){
  int i;
  int *dp = (int *) malloc (n * sizeof (*dp));
  
  if (n >= 1)
    dp[0] = 1;
  if (n >= 2)
    dp[1] = 2;
  
  for (i = 2; i < n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }
  
  return dp[n-1];
}
*/
