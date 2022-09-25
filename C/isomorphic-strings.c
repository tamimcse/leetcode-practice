/*
https://leetcode.com/problems/isomorphic-strings/
*/
bool isIsomorphic(char * s, char * t){
  int hash[256] = {0};
  int hash2[256] = {0};
  int i, j, k;
  
  for (i = 0; s[i]; i++) {
    if (!t[i])
      return false;
    if (!hash[s[i]]) {
      hash[s[i]] = t[i];
      if (hash2[t[i]])
        return false;
      hash2[t[i]] = 1;
    } else {
      if (t[i] != hash[s[i]])
        return false;
    }
  }
  if (t[i])
    return false;
  return true;
}
