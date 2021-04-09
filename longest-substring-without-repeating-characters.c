/*
https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int len_of_longest_substr_without_repeating_chars(char *str)
{
  int i, j, count, max_substr_len = 0;
  int len = strlen (str);
  int *dp = (int *) calloc (len, sizeof (*dp));

  dp [0] = 1;
  for (i = 1; str[i]; i++) {
    count = 1;
    for (j = i - 1; j >= 0; j--) {
      if (str[i] != str[j])
        count++;
      else
        break;
    }
    dp[i] = count;
  }

  for (i = 0; i < len; i++) {
    if (dp[i] > max_substr_len)
      max_substr_len = dp[i];
  }
  return max_substr_len;
}

void main ()
{
  char arr[] = "ilovecincinati";
  int res = len_of_longest_substr_without_repeating_chars (arr);
  printf ("Result is %d \n", res);
}
