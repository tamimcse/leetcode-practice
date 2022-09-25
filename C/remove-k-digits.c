/*
https://leetcode.com/problems/remove-k-digits/

Can be solved using backtracking. However, more efficient approach is to...
*/

char * removeKdigits(char * num, int k){
  int i, j, m, len = strlen (num);
  
  if (k >= len)
    return "0";
  
  for (i = 0; i < k; i++) {
    for (j = 1; num[j]; j++) {
      if (num[j] < num[j-1]) {
        for (m = j; num[m]; m++) {
          num[m-1] = num[m];
        }
        break;
      }
    }
    num[len - 1 - i] = '\0';
  }
  
  while (num[0] == '0')
    num++;
  if (num[0] == '\0')
    return "0";
  else
    return num;
}
