/*
String matching using KMP algorithm
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

  //calculate the longest prefix length which is also a suffix of the subpattern pattern. 
  //https://www.educative.io/edpresso/what-is-the-knuth-morris-pratt-algorithm
int max_prex_len (char *str, int len)
{
  int prefix_len = 0, i, l;

  for (l = 1; l <= len; l++) {
    for (i = 0; i < l; i++) {
      if (str[i] != str[len - l + i])
        break;
    }
    if (i == l) {
      prefix_len = l;
    }
  }
  printf ("len = %d prefix_len = %d \n", len, prefix_len);
  return prefix_len;
}

void kmp (char *str, char *match)
{
  int i, j, subpat_idx;
  int str_len = strlen (str);
  int match_len = strlen (match);
  int *prefix_lens = (int *) calloc (match_len, sizeof (*prefix_lens));

  for (i = 0; i < match_len; i++) {
    prefix_lens[i] = max_prex_len (match, i);
  }

  printf ("Array = ");
  for (i = 0; i < match_len; i++)
    printf ("%d ", prefix_lens[i]);
  printf ("\n");
  
  free (prefix_lens);
}

void main ()
{
  char *str = "cabcbbb", *match = "cabca";
  kmp (str, match);
}
