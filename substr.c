/*
https://www.geeksforgeeks.org/program-print-substrings-given-string/
*/
#include <stdio.h>
#include <string.h>

void substr (char *str, int start, int end)
{
  int i;
  char tmp;

  for (i = start; i <= end; i++) {
    printf ("%c", str[i]);
  }
  printf ("\n");
  if (end == start)
    return;

  tmp = str[start];  
  str[start] = '0';
  substr (str, start + 1, end);
  str[start] = tmp;

  tmp = str[end];
  str[end] = '0';
  substr (str, start, end - 1);
  str[end] = tmp;
}

void main ()
{
  char str[] = "abcd";
  int len = strlen (str);

  substr (str, 0, len - 1);
}
