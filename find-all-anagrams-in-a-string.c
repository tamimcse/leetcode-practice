/*
https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/
bool anagram (int *hash)
{
  int i;
  
  for (i = 0; i < 26; i++) {
    if (hash[i])
      return false;
  }
  return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char * s, char * p, int* returnSize){
  int hash[26] = {0};
  int s_len = strlen (s), p_len = strlen (p);
  int *res = (int *) malloc (s_len * sizeof (int));
  int res_cnt = 0, i;
  
  if (p_len > s_len) {
    *returnSize = 0;
    return NULL;
  }
  
  for (i = 0; i < p_len; i++)
    hash[p[i] - 'a']++;
  
  for (i = 0; i < p_len; i++)
    hash[s[i] - 'a']--;
  
  if (anagram (hash)) {
    res[res_cnt++] = 0;
  }
  
  for (i = 0; i < s_len - p_len; i++) {
    hash[s[i] - 'a']++;
    hash[s[i + p_len] - 'a']--;
    if (anagram (hash))
      res[res_cnt++] = i+1;
  }
  
  *returnSize = res_cnt;
  return res;
}
