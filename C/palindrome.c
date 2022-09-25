/*
A srring is plindrome if reverse of the string is same as the origibal string. Now check if a string is palindrome or not.

abc  --- not palindrome
abba --- palindrome
*/
#include <stdio.h>
#include <string.h>

int is_palindrome (char str[])
{
  int i;
  int len = strlen (str);

  for (i = 0; i < len - 1; i++, len--) {
    if (str[i] != str[len - 1])
      return 0;
  }
  return 1;
}

void main ()
{
  char str1 [] = "Hello World";
  char str2 [] = "ABCDCBA";

  if (is_palindrome (str1))
    printf ("str1 is a palindrone\n");
  else
    printf ("str1 is not a palindrone\n");

  if (is_palindrome (str2))
    printf ("str2 is a palindrone\n");
  else
    printf ("str2 is not a palindrone\n");
}
