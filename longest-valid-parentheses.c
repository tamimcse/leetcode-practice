/*
https://leetcode.com/problems/longest-valid-parentheses/
*/
int longestValidParentheses(char * s){
  int max = 0, i, j, k, count = 0;
  char stack[30001];
  int s_idx = 0;
  bool found;
  
  for (i = 0; s[i]; i++) {
    if (s[i] == '(') {
      stack[s_idx++] = '(';
    } else {
      found = false;
      for (j = s_idx - 1; j >= 0; j--) {
        if (stack[j] == '(') {
          stack[j] = 2;
          found = true;
          break;
        }
      }
      if (!found) {
        stack[s_idx++] = ')';
      }
    }
  }
  
  count = 0;
  for (i = s_idx - 1; i >= 0; i--) {
    if (stack[i] == 2) {
      count += 2;
      if (max < count)
        max = count;
    } else {
      count = 0;
    }
  }
  return max;
}
