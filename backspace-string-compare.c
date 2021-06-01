/*
https://leetcode.com/problems/backspace-string-compare/
*/



bool backspaceCompare(char * s, char * t){
  int i, j, s_len = strlen (s), t_len = strlen (t);
    
  for (i = 0; s[i]; i++) {
    if (i != 0 && s[i] == '#') {
      for (j = i + 1; j <= s_len; j++) {
        s[j-2] = s[j];
      }
      s_len -= 2;
      i -= 2;
    }
  }
  
  printf ("s = %s\n", s);
  
  for (i = 0; t[i]; i++) {
    if (i != 0 && t[i] == '#') {
      for (j = i + 1; j <= t_len; j++) {
        t[j-2] = t[j];
      }
      t_len -= 2;
      i -= 2;
    }
  }
  
  printf ("t = %s\n", t);
  
  for (i = 0; s[i]; i++) {
    if (s[i] != '#') {
      s = &s[i];
      break;
    }  
  }
  
  for (i = 0; t[i]; i++) {
    if (t[i] != '#') {
      t = &t[i];
      break;
    }  
  }
  
  return strcmp (s, t) == 0;
}
