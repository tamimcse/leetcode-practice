/*
https://leetcode.com/problems/valid-palindrome-ii/
*/


bool is_palindrome (char * s, int start, int end)
{
  while (end > start) {
    if (s[end] != s[start])
      return false;
    start++;
    end--;
  }
  return true;
}

bool validPalindrome(char * s){
  int start = 0, end = strlen(s) - 1;
  bool res;
  
  while (end > start) {
    if (s[start] == s[end]) {
      start++;
      end--;
      continue;
    }
    if (end - start == 1)
      return true;
    res = is_palindrome (s, start + 1, end);
    if (res)
      return true;
    res = is_palindrome (s, start, end-1);
    return res;
  }
  return true;
}
