/*
https://leetcode.com/problems/partition-labels/
*/
int *end_g;

int cmp (const void *a, const void *b)
{
  return end_g[*((int *)a)] - end_g[*((int *)b)];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char * s, int* returnSize){
  int start[26];
  int end[26];
  int i;
  int *res = (int *) malloc (strlen (s) * sizeof (int));
  int res_cnt = 0, last_start, last_end;
  int indices[26]; 

  for (i = 0; i < 26; i++)
    start[i] = -1;
  
  for (i = 0; i < 26; i++)
    end[i] = -1;
  
  for (i = 0; i < 26; i++)
    indices[i] = i;
  
  for (i = 0; s[i]; i++) {
    if (start[s[i] - 'a'] == -1) {
      start[s[i] - 'a'] = i;
      end[s[i] - 'a'] = i;
    } else {
      end[s[i] - 'a'] = i;
    }
  }

  end_g = start;
  qsort (indices, 26, sizeof (int), cmp);
  
  for (i = 0; i < 26; i++) {
    if (start[indices[i]] == -1)
      continue;
    if (res_cnt == 0 || start[indices[i]] > last_end) {
      last_start = start[indices[i]];
      last_end = end[indices[i]];
      res[res_cnt++] = last_end - last_start + 1;
    } else {
      if (end[indices[i]] > last_end)
        last_end = end[indices[i]];
      res[res_cnt-1] = last_end - last_start + 1;
    }
  }
  
  *returnSize = res_cnt;
  return res;
}
