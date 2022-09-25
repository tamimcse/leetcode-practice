/*
https://leetcode.com/problems/word-search-ii/

https://www.geeksforgeeks.org/boggle-set-2-using-trie/

Trie + DFS (recursive). Note that, DFS sequential is hard to implemented with Trie.
*/
struct trie_node {
  bool leaf;
  bool considered;
  struct trie_node *child[26];
};

int neighbors[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs (char** board, int num_row, int num_col, int x, int y, struct trie_node *trie, char **res, int *res_cnt, int *visit, char *s, int s_len)
{
  int i, j, k, row, col;
  
  if (!trie->considered && trie->leaf) {
    trie->considered = true;
    res[*res_cnt] = (char *) malloc ((s_len + 1) * sizeof (char));
    strcpy (res[*res_cnt], s);
    (*res_cnt)++;
  }
  
  visit[x * num_col + y] = 1;
  for (i = 0; i < 26; i++) {
    if (trie->child[i]) {
      for (j = 0; j < 4; j++) {
        row = x + neighbors[j][0];
        col = y + neighbors[j][1];
        if (row >= num_row || row < 0 || col >= num_col || col < 0)
          continue;
        if (board[row][col] == i + 'a' && !visit [row * num_col + col]) {
          s[s_len] = board[row][col];
          dfs (board, num_row, num_col, row, col, trie->child[i], res, res_cnt, visit, s, s_len + 1);
          s[s_len] = '\0';
        }
      }
    }
  }
  visit[x * num_col + y] = 0;
}

void findwords_trie (char** board, int num_row, int num_col, struct trie_node *trie, char **res, int *res_cnt)
{
  int i, j, k;
  int *visit = (int *) calloc (num_row * num_col, sizeof (*visit));
  char s[30000] = {0};
  
  for (i = 0; i < num_row; i++) {
    for (j = 0; j < num_col; j++) {
      for (k = 0; k < 26; k++) {
        if (trie->child[k] && k + 'a' == board[i][j]) {
          s[0] = board[i][j];
          dfs (board, num_row, num_col, i, j, trie->child[k], res, res_cnt, visit, s, 1); 
        }
      }
    }
  }
}

struct trie_node* create_node ()
{
  struct trie_node *new_node = (struct trie_node *) calloc (1, sizeof (*new_node));
  return new_node;
}

void insert_word_to_trie (struct trie_node *root, char *s)
{
  int i;
  struct trie_node *runner = root;
  
    
  for (i = 0; s[i]; i++) {
    if (!runner->child[s[i] - 'a'])
      runner->child[s[i] - 'a'] = create_node ();
    runner = runner->child[s[i] - 'a'];
  }
  runner->leaf = true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findWords(char** board, int boardSize, int* boardColSize, char ** words, int wordsSize, int* returnSize){
  int i;
  char **res = (char **) malloc (wordsSize * sizeof (*res));
  int res_cnt = 0;
  int num_row = boardSize, num_col = boardColSize[0];
  
  struct trie_node* root = create_node ();
  for (i = 0; i < wordsSize; i++) {
    insert_word_to_trie (root, words[i]);
  }
  findwords_trie(board, num_row, num_col, root, res, &res_cnt);
  *returnSize = res_cnt;
  return res;
}
