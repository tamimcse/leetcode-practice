/*
https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

Note that we should use DP here
*/
#include <stdio.h>

#define INF 1000

int coin_change (int coins [], int num_coins, int V)
{
  int min_coins = INF, cur_count, i, j, num_largest_coins = 0, res;

  for (i = num_coins - 1; i >= 0; i--) {
    if (V == coins[i])
      return 1;
  }

  for (i = num_coins - 1; i >= 0; i--) {
    if (V > coins[i]) {
      res = coin_change (coins, num_coins, V - coins[i]) + 1;
      if (res < min_coins) {
        min_coins = res;
      }
    }
  }
  return min_coins;
}

//check beneath main
void main ()
{
  int coins [] = {1, 5, 10, 14, 15, 20, 25};
  int num_coins = sizeof (coins) / sizeof (coins[0]);
  int V = 29;
  int res = coin_change (coins, num_coins, V);
  printf ("Result is %d \n", res);
}

/*
https://leetcode.com/problems/coin-change/

int coinChange(int* coins, int coinsSize, int amount){
  if (amount == 0)
    return 0;
  int i, j, min;
  int *dp = (int *) malloc ((amount+1) * sizeof (*dp));
  dp[0] = 0;
  for (i = 1; i <= amount; i++) {
    min = 50000;
    for (j = 0; j < coinsSize; j++) {
      if (coins[j] == i) {
        min = 1;
        break;
      } else if (coins[j] > i) {
        continue;
      } else {
        if (dp[i - coins[j]] > 0 && dp[i - coins[j]] + 1 < min)
          min = dp[i - coins[j]] + 1;
      }
    }
    dp[i] = min != 50000 ? min : -1;
  }
  return dp[amount];
}
*/
