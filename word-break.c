/*
https://leetcode.com/problems/word-break/

https://www.geeksforgeeks.org/word-break-problem-dp-32/

https://www.geeksforgeeks.org/word-break-problem-trie-solution/

very interesting problem!
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

bool trie_search (struct trie_node *root, char *s)
{
  struct trie_node *runner;
  int i, j;
  int *dp = (int *) calloc (strlen (s) + 1, sizeof (*dp));
  
  dp[strlen (s)] = 1;
  for (i = strlen (s) - 1; i >= 0; i--) {
    runner = root;
    for (j = i; s[j]; j++) {
      if (!runner->children[s[j] - 'a']) {
        break;
      }
      runner = runner->children[s[j] - 'a'];
      if (runner->leaf && dp[j + 1]) {
        dp[i] = 1;
        break;
      }
    }
  }
  return dp[0];
}


bool wordBreak(char * s, char ** wordDict, int wordDictSize){
  int i;
  struct trie_node *root = create_node ();
  
  for (i = 0; i < wordDictSize; i++) {
    trie_insert (root, wordDict[i]);
  }
  
  return trie_search (root, s);
}
