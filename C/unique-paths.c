/*
https://leetcode.com/problems/unique-paths/
*/

//backtracking would be too expensive

//recursive solution also may exceed time limit
int uniquePaths(int m, int n){
  if (m == 1 || n == 1)
    return 1;

  return uniquePaths (m - 1, n) + uniquePaths (m, n - 1);
}

//DP works fine!
int uniquePaths(int m, int n){
  int i, j;
  int *dp = calloc (m * n, sizeof (*dp));
  
  for (i = 0; i < n; i++)
    dp [i] = 1;
  
  for (i = 0; i < m; i++)
    dp[i * n] = 1;
  
  for (i = 1; i < m; i++) {
    for (j = 1; j < n; j++) {
      dp[i * n + j] = dp[(i - 1) * n + j] + dp[i * n + j - 1];
    }
  }
  
  return dp [(m - 1) * n + n - 1];
}

