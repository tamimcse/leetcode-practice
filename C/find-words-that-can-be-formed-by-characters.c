/*
https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
*/
int can_form (char *s, int *hash)
{
  int i, j, count;
  int tmp[26];
  
  memcpy (tmp, hash, 26 * sizeof (int));
  for (i = 0; s[i]; i++) {
    if (!tmp[s[i] - 'a'])
      return 0;
    tmp[s[i] - 'a']--;
  }
  return i;
}

int countCharacters(char ** words, int wordsSize, char * chars){
  int hash[26] = {0};
  int i, j, res = 0;
  
  for (i = 0; chars[i]; i++)
    hash[chars[i] - 'a']++;
  
  for (i = 0; i < wordsSize; i++) {
    res += can_form (words[i], hash);
  }
  return res;
}
