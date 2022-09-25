/*
https://leetcode.com/problems/regular-expression-matching/
*/

bool isMatch(char * s, char * p){
  int i;
  bool res;
  
  if (*p == NULL && *s == NULL)
    return true;
  if (*p == NULL)
    return false;
  if (*s == NULL) {
    while (*p) {
      if (!*(p + 1) || (*(p + 1) && *(p + 1) != '*'))
        return false;
      else
        p += 2;
    }
    return true;
  } 
  if (!*(p + 1) || (*(p + 1) && *(p + 1) != '*')) {
    if (*p == '.' || *s == *p) {
      return isMatch (s + 1, p + 1);
    } else {
      return false;
    }
  } else {
    res = isMatch (s, p + 2);
    if (res)
      return true;
    if (*p == '.') {
      for (i = 0; s[i]; i++) {
        res = isMatch (s + 1 + i, p + 2);
        if (res)
          return true;
      }
      return false;
    } else {
      for (i = 0; *(s + i) == *p; i++) {
        res = isMatch (s + 1 + i, p + 2);
        if (res)
          return true;
      }
      return false;
    }
  }
}
