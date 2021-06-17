/*
https://leetcode.com/problems/perfect-squares/
*/
int numSquares(int n){
  int perf_squares_len = sqrt (n);
  int *perf_squares = (int *) malloc (perf_squares_len * sizeof (*perf_squares));
  int *dp = (int *) calloc ((n + 1), sizeof (*dp));
  int i, j, min;
  
  
  for (i = 1; i <= perf_squares_len; i++) {
    perf_squares[i-1] = i * i;
  }
  
  dp[0] = 0;
  for (i = 1; i <= n; i++) {
    min = n * n;
    for (j = 0; j < perf_squares_len; j++) {
      if (perf_squares[j] > i)
        continue;
      if (min > dp[i - perf_squares[j]] + 1)
        min = dp[i - perf_squares[j]] + 1;
    }
    dp[i] = min;
  }
  return dp[n];  
}
