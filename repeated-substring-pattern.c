/*
https://leetcode.com/problems/repeated-substring-pattern/
*/
bool repeated_pattern (char *s, char *pat, int pat_len)
{
  int i, j;

  for (i = 0, j = 0; s[i]; i++, j = (j + 1) % pat_len) {
    if (s[i] != pat[j])
      return false;
  }
  return j == 0;
}

bool repeatedSubstringPattern(char * s){
  int len = strlen (s), i;
  
  for (i = 0; i < (len/2) + 2; i++)  {
    if (i + 1 < len && repeated_pattern (s + i + 1, s, i + 1))
      return true;
  }
  return false;
}
