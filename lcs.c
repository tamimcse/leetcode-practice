/*
Longest Common Subsequence (LCS): 

LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

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

int lcs_dp (char *s1, char *s2)
{
  int len1 = strlen (s1);
  int len2 = strlen (s2);
  if (!len1 || !len2)
    return 0;
  int *dp_arr = (int *) calloc (len1 * len2, sizeof (*dp_arr));
  int i, j;
  bool match = false;

  //initalize the first row
  for (i = 0; i < len2; i++) {
    if (s1[0] == s2[i])
      match = true;
    dp_arr[i] = match ? 1 : 0;
  }

  match = false;
  //initalize the first column
  for (i = 0; i < len1; i++) {
    if (s1[i] == s2[0])
      match = true;
    dp_arr[i * len2] = match ? 1 : 0;
  }

  for (i = 1; i < len1; i++) {
    for (j = 1; j < len2; j++) {
      if (s1[i] == s2[j])
        dp_arr[i * len2 + j] = dp_arr[(i - 1) * len2 + j - 1] + 1;
      else
        dp_arr[i * len2 + j] = fmax (dp_arr[(i - 1) * len2 + j], dp_arr[i * len2 + j - 1]);
    }
  }

  return dp_arr[(len1 - 1) * len2 + (len2 -1)];
}

void main ()
{
  char *s1 = "AGGTAB", *s2 = "GXTXAYB", *s3 = "ABCDGH", *s4 = "AEDFHR";
  int lcs1_len = lcs (s1, s2);
  printf ("LCS of %s and %s is %d \n", s1, s2, lcs1_len);
  int lcs2_len = lcs (s3, s4);
  printf ("LCS of %s and %s is %d \n", s3, s4, lcs2_len);

  printf ("Now DP version .......\n");
  lcs1_len = lcs_dp (s1, s2);
  printf ("LCS of %s and %s is %d \n", s1, s2, lcs1_len);
  lcs2_len = lcs_dp (s3, s4);
  printf ("LCS of %s and %s is %d \n", s3, s4, lcs2_len);
  
}
