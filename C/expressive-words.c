/*
https://leetcode.com/problems/expressive-words/
*/

bool stretchy (char *s, char *q)
{
  int i, j, s_count, q_count;
  
  for (i = 0, j = 0; s[i] && q[j]; i++, j++) {
    if (s[i] != q[j])
      return false;
    q_count = 1;
    while (q[j] == q[j+1]) {
      j++;
      q_count++;
    }
    
    s_count = 1;
    while (s[i+1] == s[i]) {
      i++;
      s_count++;
    }
    if (s_count == q_count || (s_count > q_count && s_count >= 3))
      continue;
    else
      return false;
  }
  if (s[i] || q[j])
    return false;
  return true;
}

int expressiveWords(char * s, char ** words, int wordsSize){
  int i, count = 0;
  
  for (i = 0; i < wordsSize; i++) {
    if (stretchy (s, words[i]))
      count++;
  }
  return count;
}
