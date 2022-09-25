/*
https://leetcode.com/problems/valid-palindrome/
*/

bool isPalindrome(char * s){
  int start = 0, end = strlen (s) - 1;
  while (end > start) {
    if (!isalnum (s[start])) {
      start++;
      continue;
    } else if (!isalnum (s[end])) {
      end--;
      continue;
    }
    if (toupper(s[start]) != toupper(s[end])) {
      return false;
    }
    start++;
    end--;
  }
  return true;
}
