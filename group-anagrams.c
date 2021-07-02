/*
https://leetcode.com/problems/group-anagrams/
*/

struct str_with_len {
  char *str;
  int len;
};

int cmp (const void *a, const void *b)
{
  return ((struct str_with_len *)a)->len - ((struct str_with_len *)b)->len;
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
  int i, j, k, count, len, col_num;
  struct str_with_len *arr = (struct str_with_len *) malloc (strsSize * sizeof (*arr));
  char *added = (char *) calloc (strsSize, sizeof (*added));
  
  for (i = 0; i < strsSize; i++) {
    arr[i].str = strs[i];
    arr[i].len = strlen (strs[i]);
  }
  qsort (arr, strsSize, sizeof (struct str_with_len), cmp);
  
  for (i = 0; i < strsSize; i++) {
    if (added[i])
      continue;
    res[res_cnt] = (char **) malloc (strsSize * sizeof (char *));
    col_num = 0;
    res[res_cnt][col_num++] = arr[i].str;
    int hash[26] = {0};
    for (j = 0; arr[i].str[j]; j++)
      hash[arr[i].str[j] - 'a']++;
    for (j = i + 1; j < strsSize; j++) {
      if (arr[i].len != arr[j].len)
        break;
      int hash1[26];
      memcpy (hash1, hash, sizeof (int) * 26);
      for (k = 0; arr[j].str[k]; k++) {
        int idx = arr[j].str[k] - 'a';
        hash1[idx]--;
        if (hash1[idx] < 0)
          goto done;
      }
      for (k = 0; k < 26; k++) {
        if (hash1[k])
          goto done;
      }
      res[res_cnt][col_num++] = arr[j].str;
      added[j] = 1;
done:
      continue;
    }
    colsizes[res_cnt] = col_num;
    res_cnt++;
  }
  *returnSize = res_cnt;
  *returnColumnSizes = (int *) malloc (res_cnt * sizeof (int));
  for (i = 0; i < res_cnt; i++) {
    (*returnColumnSizes)[i] = colsizes[i];
  }
  return res;
}
