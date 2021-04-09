/*
https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/
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

void main ()
{
  int coins [] = {1, 5, 10, 14, 15, 20, 25};
  int num_coins = sizeof (coins) / sizeof (coins[0]);
  int V = 29;
  int res = coin_change (coins, num_coins, V);
  printf ("Result is %d \n", res);
}
