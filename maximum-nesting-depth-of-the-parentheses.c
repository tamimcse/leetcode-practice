/*
https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
*/


int maxDepth(char * s){
  int i, count = 0, max = 0;
  
  for (i = 0; s[i]; i++) {
    if (s[i] == '(') {
      count++;
      if (count > max)
        max = count;
    } else if (s[i] == ')') {
      count--;
    }
  }
  return max;
}
