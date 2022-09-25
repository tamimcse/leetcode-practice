/*
https://leetcode.com/problems/rotate-string/
*/
bool rotateString(char * s, char * goal){
  int i;
  
  if (strlen (s) != strlen (goal))
    return false;
  
  for (i = strlen (s) - 1; i >= 1; i--) {
    if (strstr (goal, s + i) == goal && strstr (s, goal + strlen (s) - i) == s)
      return true;
  }
  return false;
}
