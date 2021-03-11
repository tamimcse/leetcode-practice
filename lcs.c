/*
Longest Common Subsequence (LCS): 

LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
*/
#include <stdio.h>
#include <math.h>
#include <string.h>

int lcs_inner (char *s1, int len1, char *s2, int len2)
{
  if (!len1 || !len2) {
    return 0;
  }

  if (s1[len1 - 1] == s2[len2 - 1]) {
    return 1 + lcs_inner (s1, len1 - 1, s2, len2 - 1);
  } else {
    return fmax (lcs_inner (s1, len1, s2, len2 - 1), lcs_inner (s1, len1 - 1, s2, len2));
  }
}

int lcs (char *s1, char *s2)
{
  int len1 = strlen (s1);
  int len2 = strlen (s2);

  return lcs_inner (s1, len1, s2, len2);
}

void main ()
{
  char *s1 = "AGGTAB", *s2 = "GXTXAYB", *s3 = "ABCDGH", *s4 = "AEDFHR";
  int lcs1_len = lcs (s1, s2);
  printf ("LCS of %s and %s is %d \n", s1, s2, lcs1_len);
  int lcs2_len = lcs (s3, s4);
  printf ("LCS of %s and %s is %d \n", s3, s4, lcs2_len);
}
