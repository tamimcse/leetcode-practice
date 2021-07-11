/*
https://leetcode.com/problems/edit-distance/

Very interesing!!!
*/
int min (int a, int b, int c)
{
  return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int minDistance(char * word1, char * word2){
  int num_col = strlen (word1) + 1, num_row = strlen (word2) + 1;
  int **dp = (int **) calloc (num_row, sizeof (*dp));
  int i, j, k;
  
  for (i = 0; i < num_row; i++) {
    dp[i] = (int *) calloc (num_col, sizeof (int));
  }
  
  dp[0][0] = 0;
  for (i = 1; i < num_col; i++) {
    dp[0][i] = i;
  }
  
  for (i = 1; i < num_row; i++) {
    dp[i][0] = i;
  }
  
  for (i = 1; i < num_row; i++) {
    for (j = 1; j < num_col; j++) {
      if (word1[j-1] == word2[i-1]) {
        dp[i][j] = min (dp[i-1][j-1], dp[i-1][j] + 1, dp[i][j-1] + 1);
      } else {
        dp[i][j] = min (dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;
      }
    }
  }
  
  return dp[num_row-1][num_col-1];
}
