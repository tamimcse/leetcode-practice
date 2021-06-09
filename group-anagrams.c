/*
https://leetcode.com/problems/group-anagrams/

For some reason, leetcode is running out of time althrough we are using efficient algorithm to check anagram.
*/

bool is_anagram (char *s1, char *s2)
{
  int i, idx;
  int hash[26] = {0};
  
  for (i = 0; s1[i]; i++)
    hash[s1[i] - 'a'] += 1;
  
  for (i = 0; s2[i]; i++) {
    idx = s2[i] - 'a';
    hash[idx] -= 1;
  } 
  
  for (i = 0; i < 26; i++) {
    if (hash[i] != 0)
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
  char ***res = (char ***) malloc (strsSize * sizeof (*res));
  int *colsizes = (int *) calloc (strsSize, sizeof (int));
  int res_cnt = 0;
  int i, j, k, count;
  int *included = (int *) calloc (strsSize, sizeof (*included));
  char *anagrams_idx = (char *) calloc (strsSize, sizeof (*anagrams_idx));
    
  for (i = 0; i < strsSize; i++) {
    if (included[i])
      continue;
    memset (anagrams_idx, 0, strsSize * sizeof (*anagrams_idx));
    anagrams_idx[i] = 1;
    included[i] = 1;    
    count = 1;
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
    for (j = 0, k = 0; j < strsSize; j++) {
      if (anagrams_idx[j]) {
        //res[res_cnt][k] = strs[j];
        res[res_cnt][k] = (char *) malloc ((strlen (strs[i]) + 1) * sizeof (char));
        strcpy (res[res_cnt][k], strs[j]);
        k++;
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
