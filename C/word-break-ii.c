/*
https://leetcode.com/problems/word-break-ii/
*/

struct trie_node {
  bool leaf;
  struct trie_node *children[26];
};

struct trie_node* create_node ()
{
  return (struct trie_node *) calloc (1, sizeof (struct trie_node));
}

void trie_insert (struct trie_node *root, char *s)
{
  int i, j;
  struct trie_node *runner = root;
  
  for (i = 0; s[i]; i++) {
    if (!runner->children[s[i] - 'a']) {
      runner->children[s[i] - 'a'] = create_node();
    }
    runner = runner->children[s[i] - 'a'];
  }
  runner->leaf = true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** wordBreak(char * s, char ** wordDict, int wordDictSize, int* returnSize){
  int i, j, k, count, str_len = strlen (s);
  struct trie_node *runner;
  struct trie_node *root = create_node ();
  char **str_list;
  int str_list_cnt;
  
  for (i = 0; i < wordDictSize; i++) {
    trie_insert (root, wordDict[i]);
  }
  
  char ***dp = (char ***) calloc (str_len, sizeof (*dp));
  int *dp_cnt = (int *) calloc (str_len, sizeof (*dp_cnt));
  for (i = str_len - 1; i >= 0; i--) {
    runner = root;
    str_list = (char **) calloc (100, sizeof (*str_list));
    str_list_cnt = 0;
    for (j = i; j < str_len; j++) {
      if (!runner->children[s[j]-'a'])
        break;
      runner = runner->children[s[j]-'a'];
      if (runner->leaf) {
        if (j == str_len - 1) {
          str_list[str_list_cnt] = (char *) calloc (100, sizeof (char)); 
          strcpy (str_list[str_list_cnt], s + i);
          str_list_cnt++;
        } else if (dp[j+1]) {
          char substr[100] = {0};
          memcpy (substr, s + i, (j - i + 1) * sizeof (char));
          for (k = 0; k < dp_cnt[j+1]; k++) {
            str_list[str_list_cnt] = (char *) calloc (100, sizeof (char));
            sprintf (str_list[str_list_cnt], "%s %s", substr, dp[j+1][k]);
            str_list_cnt++;
          }
        }
      }
    }
    dp[i] = str_list;
    dp_cnt[i] = str_list_cnt;
  }
  *returnSize = dp_cnt[0];
  return dp[0];
}
