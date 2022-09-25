/*
https://leetcode.com/problems/coin-change-2/

https://www.geeksforgeeks.org/coin-change-dp-7/

Very interesting!!
*/

int change(int amount, int* coins, int coinsSize){
  int i, j;
  int *dp = (int *) calloc (amount + 1, sizeof (*dp));
  dp[0] = 1;
  
  for (i = j; j < coinsSize; j++) {
    for (i = 0; i < amount + 1; i++) {
      if (i - coins[j] >= 0)
        dp[i] = dp[i] + dp[i - coins[j]];
    }
  }
  return dp[amount];
}
/*
//gets TLE

int change(int amount, int* coins, int coinsSize){
  int i, count = 0, res1 = 0, res2 = 0;
  
  if (amount == 0)
    return 1;
  
  if (amount < 0)
    return 0;
    
  if (coinsSize-1 >= 0)
    res1 = change (amount, coins, coinsSize-1);
  if (coinsSize-1 >= 0)
    res2 = change (amount - coins[coinsSize-1], coins, coinsSize);
  return res1 + res2;
}*/
