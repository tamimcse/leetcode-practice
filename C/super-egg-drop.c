/*
https://leetcode.com/problems/super-egg-drop/

Details would be found in notes.

https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/

https://leetcode.com/problems/super-egg-drop/solution/
*/
#define max(a,b) (a < b ? b : a)

int superEggDrop(int k, int n){
  int i, j, m, min, res, start, end, mid;
  int **dp = (int **) calloc (k + 1, sizeof (*dp)); 
  
  for (i = 0; i <= k; i++)
    dp[i] = (int *) calloc (n + 1, sizeof (int));
  
  for (i = 1; i <= n; i++)
    dp[1][i] = i;
  
  for (i = 2; i <= k; i++)
    dp[i][1] = 1;
  
  for (i = 2; i <= k; i++) {
    for (j = 2; j <= n; j++) {
      start = 1;
      end = j;
      min = 10000000;
      while (start <= end) {
        mid = (start + end) >> 1;
        if (dp[i-1][mid-1] < dp[i][j-mid]) {
          start = mid + 1;
          if (dp[i][j-mid] < min)
            min = dp[i][j-mid];
        } else if (dp[i-1][mid-1] > dp[i][j-mid]) {
          end = mid - 1;
          if (dp[i-1][mid-1] < min)
            min = dp[i-1][mid-1];
        } else {
          if (dp[i-1][mid-1] < min)
            min = dp[i-1][mid-1];
          break;
        }
      }
      dp[i][j] = min + 1;
    }
  }
  return dp[k][n];
}
