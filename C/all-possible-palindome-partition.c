/*
https://www.geeksforgeeks.org/given-a-string-print-all-possible-palindromic-partition/

Use backtracking to check each substring to see if it's a palindrome. Simple, so not implementing it now.

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_palindome (char *str, int start, int end)
{
  int i, j;

  for (i = start, j = end; i < j; i++, j--) {
    if (str[i] != str[j])
      return false;
  }
  return true;
}

void print (char *str, int start, int end)
{
  int i;

  for (i = start; i <= end; i++) {
    printf ("%c", str[i]);
  }
  printf ("\n");
}

void palindrome_substr (char *str)
{
  int i, j, substr_len;
  int len = strlen (str);

  for (substr_len = len; substr_len > 1; substr_len--) {
    if (is_palindome (str, 0, substr_len - 1)) {
      print (str, 0, substr_len - 1);
      return;
    }
  }
}

void main ()
{
  char str[] = "acinici";
}

