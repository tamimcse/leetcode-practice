/*
https://leetcode.com/problems/buddy-strings/
*/


bool buddyStrings(char * s, char * goal){
  int s_len = strlen (s), g_len = strlen (goal);
  int i, j, k, num_unmatch;
  int idx[2] = {0};
  int hash[26] = {0};
  
  if (s_len != g_len)
    return false;
  
  if (!strcmp (s, goal)) {
    for (i = 0; s[i]; i++) {
      hash[s[i] - 'a']++;
      if (hash[s[i] - 'a'] > 1)
        return true;
    }
    return false;
  }
  
  for (i = 0, j = 0, num_unmatch = 0; s[i]; i++) {
    if (s[i] != goal[i]) {
      num_unmatch++;
      if (num_unmatch > 2)
        return false;
      idx[j++] = i;
    }
  }

  if (num_unmatch < 2)
    return false;
  return s[idx[0]] == goal[idx[1]] && s[idx[1]] == goal[idx[0]];
}
