/*
https://leetcode.com/problems/is-subsequence/

This is a very intesting and tough problem!!!!!!
*/


bool isSubsequence(char * s, char * t){
  int s_start = 0, s_end, s_len = strlen (s), 
    t_len = strlen (t), t_start = 0, t_end = 0;
  
  if (!s[0])
    return true;
  
  while (t_start < t_len && t[t_start] != s[0])
    t_start++;
  if (t_start == t_len)
    return false;
  t_end = t_start;
  s_start = 0;
  s_end = 0;
  
  while (s_end + 1 < s_len) {
    if (t_end + 1 == t_len) {
      t_start++;
      while (t_start < t_len && t[t_start] != s[0])
        t_start++;
      if (t_start == t_len)
        return false;
      t_end = t_start;
      s_start = 0;
      s_end = 0;
      continue;
    }
    if (s[s_end + 1] == t[t_end+1]) {
      s_end++;
    }
    t_end++;
  }
  return true;
}
