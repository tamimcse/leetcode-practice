/*
https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

https://www.geeksforgeeks.org/frequency-substring-string/
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

  //calculate the longest proper prefix length which is also a suffix of the subpattern pattern. 
  //https://www.educative.io/edpresso/what-is-the-knuth-morris-pratt-algorithm
int max_prex_len (char *str, int len)
{
  int i, l;

  for (l = len - 1; l >= 1; l--) {
    for (i = 0; i < l; i++) {
      if (str[i] != str[len - l + i]) {
        break;
      }
    }
    if (i == l) {
      return l;
    }
  }
  return 0;
}

void kmp (char *str, char *match)
{
  int i, j, subpat_idx;
  int str_len = strlen (str);
  int match_len = strlen (match);
  int *prefix_lens = (int *) calloc (match_len, sizeof (*prefix_lens));

  for (i = 0; i < match_len; i++) {
    prefix_lens[i] = max_prex_len (match, i + 1);
    printf("prefix_lens[%d] = %d\n", i, prefix_lens[i]);
  }

  i = 0;
  j = 0;
  while (i < str_len) {
    if (str[i] == match[j]) {
      i++;
      j++;
      if (j == match_len) {
        printf ("Match found at index %d !!! \n", i - match_len);
        j = prefix_lens[match_len - 1];
      }
    } else if (match[j]) {
      j = match[j];
    } else {
      j = 0;
      i++;
    }
  }
  
  free (prefix_lens);
}

void main ()
{
//  char *str = "cabcbbb", *match = "cabcb";
  char *str = "AABAACAADAABAABA", *match = "AABA";
  kmp (str, match);
}
