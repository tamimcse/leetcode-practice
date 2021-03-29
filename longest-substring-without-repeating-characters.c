/*
https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
*/
#include <stdio.h>
#include <string.h>

int len_of_longest_substr_without_repeating_chars(char *str)
{
  int i;
  char hash[256] = {0};
  int count = 0;

  for (i = 0; str[i]; i++) {
    if (!hash[str[i]]) {
      hash[str[i]] = 1;
      count++;
    }
  }
  return count;
}

void main ()
{
  char arr[] = "ABDEFGABEF";
  int res = len_of_longest_substr_without_repeating_chars (arr);
  printf ("Result is %d \n", res);
}
