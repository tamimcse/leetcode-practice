/*
https://www.geeksforgeeks.org/program-print-substrings-given-string/
*/
#include <stdio.h>
#include <string.h>

//It generates same substr multiple times (uses backtracking)
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

void substr_itr (char *str, int len)
{
  int i, j, k;

  for (i = 0; i < len; i++) {
    for (j = len - 1; j >= 0; j--) {
      for (k = i; k <= j; k++) {
        printf ("%c", str[k]);
      }
      printf ("\n");
    }
  }
}

void main ()
{
  char str[] = "abcd";
  int len = strlen (str);

  printf ("substring backtracking version:\n");
  substr (str, 0, len - 1);

  printf ("substring iterative version:\n");
  substr_itr (str, len);
}
