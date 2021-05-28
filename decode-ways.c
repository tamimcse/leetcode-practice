/*
https://leetcode.com/problems/decode-ways/
*/

int ways (char c1, char c2)
{
  int num, count = 0;
  
  if (c1 == '0')
    return 0;
  
  num = (c1 - '0') * 10 + (c2 - '0');
  if (num >= 1 && num <= 26)
    count++;
  if (c2 != '0')
    count++;
  
  return count;
  
}

bool valid (char c1, char c2)
{
  if (c1 == '0')
    return false;
  int num = (c1 - '0') * 10 + (c2 - '0');
  return num >= 1 && num <= 26;
}

int numDecodings(char * s){
  int len = strlen (s);
  int i;
  int res1, res2;
  
  int *dp = (int *) calloc (len, sizeof (*dp));
  
  if (len > 0 && s[i] != '0')
    dp[0] = 1;
  if (len > 1)
    dp[1] = ways (s[0], s[1]);
  
  for (i = 2; i < len; i++) {
    res1 = (s[i] != '0') ? dp[i - 1] : 0;
    res2 = valid (s[i-1], s[i]) ? dp[i - 2] : 0;
    dp[i] = res1 + res2;
  }
  return dp[len-1];
}
