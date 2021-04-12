/*
https://www.geeksforgeeks.org/interesting-method-generate-binary-numbers-1-n/
*/
#include <stdio.h>
#include <stdlib.h>

void gen_binary (int n)
{
  char* queue[100];
  int start = 0, end = 0;
  char *str;
  int len, num;

  queue[end++] = "1";
  len = 1;
  num = 0;
  while (end > start) {
    str = queue[start++];
    printf ("%s\n", str);
    len++;
    if (++num == n)
      break; 
    char *str1 = calloc (len, sizeof (*str1));
    char *str2 = calloc (len, sizeof (*str2));
    sprintf (str1, "%s0", str);
    queue[end++] = str1;
    sprintf (str2, "%s1", str);
    queue[end++] = str2;
  }
}

void main ()
{
  int n = 16;

  gen_binary (n);
}
