/*
https://leetcode.com/problems/strobogrammatic-number/

Given a string num which represents an integer, return true if num is a strobogrammatic number.

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Example 1:

Input: num = "69"
Output: true
Example 2:

Input: num = "88"
Output: true
Example 3:

Input: num = "962"
Output: false
Example 4:

Input: num = "1"
Output: true
*/
bool isStrobogrammatic(char * num){
  int len = strlen (num);
  char *upside_down = (char *) malloc ((len + 1) * sizeof (char));
  upside_down[len] = '\0';
  int curr;
  int i;
  
  for (i = 0; num[i]; i++) {
    curr = num[i] - '0';
    if ((curr >= 2 && curr <= 5) || curr == 7) {
      return false;
    }
    switch (curr) {
      case 0:
      case 8:
      case 1:
        upside_down[len - 1 - i] = num[i];
        break;
      case 6:
        upside_down[len - 1 - i] = '9';
        break;
      case 9:
        upside_down[len - 1 - i] = '6';
        break;
    }
  }
  
  return strcmp (num, upside_down) == 0;
}
