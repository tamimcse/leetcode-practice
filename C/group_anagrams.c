/*
https://leetcode.com/problems/group-anagrams/
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_anagram (char *s1, char *s2)
{
  int i;
  int hash[26] = {0};
  int s1_len, s2_len;
    
  s1_len = strlen (s1);
  s2_len = strlen (s2);
  if (s1_len != s2_len)
    return false;
  
  if (!s1_len)
    return false;
  
  for (i = 0; s1[i]; i++)
    hash[s1[i] - 'a'] = 1;
  
  for (i = 0; s2[i]; i++)
    hash[s2[i] - 'a'] += 1;
  
  for (i = 0; i < 26; i++) {
    if (hash[i] == 1)
      return false;
  }
  return true;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** groupAnagrams(char **strs, int strsSize, int* returnSize, int** returnColumnSizes){
  char ***res = (char ***) malloc (10000 * sizeof (*res));
  int *colsizes = (int *) calloc (10000, sizeof (int));
  int res_cnt = 0;
  int i, j, k;
  int included[10000] = {0};
  
  
  for (i = 0; i < strsSize; i++) {
    if (included[i])
      continue;
    int anagrams_idx[10000] = {0};
    int count = 1;
    for (j = i + 1; j < strsSize; j++) {
      if (included[j])
        continue;
      if (is_anagram (strs[i], strs[j])) {
        anagrams_idx[j] = 1;
        included[j] = 1;
        count++;
      }
    }
    colsizes[res_cnt] = count;
    res[res_cnt] = (char **) malloc (count * sizeof (char *));
    char *first =(char *) malloc (sizeof (strs[i]));
    strcpy (first, strs[i]);
    res[res_cnt][0] = first;
    
    for (k = 0, j = 1; k < 10000; k++) {
      if (anagrams_idx[k]) {
        char *new_anagram =(char *) malloc (sizeof (strs[i]));
        strcpy (new_anagram, strs[k]);
        res[res_cnt][j++] = new_anagram;
      }
    }
    res_cnt++;
  }
  *returnSize = res_cnt;
  *returnColumnSizes = (int *) malloc (res_cnt * sizeof (int));
  for (i = 0; i < res_cnt; i++) {
    (*returnColumnSizes)[i] = colsizes[i];
  }
  return res;
}

void main ()
{
  char *strs[] = {"bdddddddddd","bbbbbbbbbbc"};
  int len = sizeof (strs) / sizeof (strs[0]);
  int res_size;
  int *returnColumnSizes;

  char ***res = groupAnagrams (strs, len, &res_size, &returnColumnSizes);

  for (int i = 0; i < res_size; i++) {
    for (int j = 0; j < returnColumnSizes[i]; j++) {
      printf ("%s ", res[i][j]);
    }
    printf ("\n");
  }
}
