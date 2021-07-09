/*
https://leetcode.com/problems/word-ladder/
*/
bool adjacent_words (char *s1, char *s2)
{
  int i, count = 0;
  
  for (i = 0; s1[i] || s2[i]; i++) {
    if (!s1[i] || !s2[i]) {
      count++;
      continue;
    }
    if (s1[i] != s2[i])
      count++;
  }
  return count == 1;
}

struct edge {
  int id;
  struct node *next;
};

void insert_edge (struct edge **adj_list, int i, int j)
{
  struct edge *new_edge;
  
  new_edge = (struct edge *) malloc (sizeof (*new_edge));
  new_edge->id = i;
  new_edge->next = adj_list[j];
  adj_list[j] = new_edge;
  
  new_edge = (struct edge *) malloc (sizeof (*new_edge));
  new_edge->id = j;
  new_edge->next = adj_list[i];
  adj_list[i] = new_edge;
}

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
  int i, j, k;
  struct edge **adj_list = (struct edge **) calloc (wordListSize + 1, sizeof (*adj_list));
  int *queue = (int *) malloc (wordListSize * 205 * sizeof (*queue));
  int *len = (int *) malloc (wordListSize * 205 * sizeof (*len));
  int q_start = 0, q_end = 0, curr, curr_len;
  struct edge *runner;
  char *visit = (char *) calloc (wordListSize + 1, sizeof (*visit));
  int target = -1, min, start = -1;
  
  for (i = 0; i < wordListSize; i++) {
    if (!strcmp (endWord, wordList[i])) {
      target = i;
      break;
    }
  }
  if (target == -1)
    return 0;
  
  for (i = 0; i < wordListSize; i++) {
    if (!strcmp (beginWord, wordList[i])) {
      start = i;
      break;
    }
  }

  for (i = 0; i < wordListSize; i++) {
    for (j = i + 1; j < wordListSize; j++) {
      if (adjacent_words (wordList[i], wordList[j])) {
        insert_edge (adj_list, i, j);
      }
    }
  }
  
  if (start == -1) {
    for (i = 0; i < wordListSize; i++) {
      if (adjacent_words (wordList[i], beginWord)) {
        insert_edge (adj_list, i, wordListSize);
      }
    }
    start = wordListSize;
  }

  //BFS
  queue[q_end] = start;
  len[q_end] = 1;
  q_end++;
  while (q_end > q_start) {
    curr = queue[q_start];
    curr_len = len[q_start];
    q_start++;
    if (curr == target)
      return curr_len;
    runner = adj_list[curr];
    while (runner) {
      if (!visit[runner->id]) {
        queue[q_end] = runner->id;
        len[q_end] = curr_len + 1;
        q_end++;
      }
      runner = runner->next;
    }
    visit[curr] = 1;
  }
  return 0;
}
