/*
https://www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/

https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/?company[]=Amazon&company[]=Amazon&page=1&query=company[]Amazonpage1company[]Amazon
*/
#include <stdio.h>
#include <stdlib.h>

void gen_balanced_parenthesis_backtracking (int n, char *str, int num_open, int num_close)
{
  if (num_open + num_close == (n << 1)) {
    printf ("%s\n", str);
    return;
  }

  if (n > num_open) {
    str[num_open + num_close] = '(';
    gen_balanced_parenthesis_backtracking (n, str, num_open + 1, num_close);
    str[num_open + num_close] = '\0';
  }
  if (num_open > num_close) {
    str[num_open + num_close] = ')';
    gen_balanced_parenthesis_backtracking (n, str, num_open, num_close + 1);
    str[num_open + num_close] = '\0';
  }
}

void gen_balanced_parenthesis (int n)
{
  char *str = calloc (n << 1, sizeof (*str));
  str[0] = '(';
  gen_balanced_parenthesis_backtracking (n, str, 1, 0);
}

void main ()
{
  int n = 4;

  gen_balanced_parenthesis (n);
}
