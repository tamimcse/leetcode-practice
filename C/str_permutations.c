/*
String Permutations: Given a string S. The task is to find all permutations of a given string.

Input:
S = ABC
Output: ABC ACB BAC BCA CAB CBA 

Input:
S = ABSG
Output: ABGS ABSG AGBS AGSB ASBG ASGB
BAGS BASG BGAS BGSA BSAG BSGA GABS
GASB GBAS GBSA GSAB GSBA SABG SAGB
SBAG SBGA SGAB SGBA
*/
#include <stdio.h>
#include <string.h>

void swap (char *a, char *b)
{
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

void permutation (char str[], int start, int end)
{
  int i;

  if (start == end) {
    printf ("%s ", str);
    return;
  }

  for (i = start; i <= end; i++) {
    swap (&str[start], &str[i]);
    permutation (str, start + 1, end);
    swap (&str[i], &str[start]);
  }
}

void main ()
{
  char str [] = "ABSG";
  int len = strlen (str);

  permutation (str, 0, len - 1);
}
