/*
https://www.geeksforgeeks.org/trie-insert-and-search/
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct node {
  struct node *children[ALPHABET_SIZE];
  bool end_of_the_word;
};

void insert (struct node *root, char *str)
{
  struct node *child, *new_node;
  struct node *runner = root;
  int idx = 0;
  int child_idx;

  printf ("Inserting %s \n", str);

  while (1) {
    child_idx = str[idx] - 'a';
    if (!runner->children[child_idx]) {
      runner->children[child_idx] = (struct node *) calloc (1, sizeof (*new_node));
      if (!str[idx + 1]) {
        runner->children[child_idx]->end_of_the_word = true;
        break;
      }
    }
    runner = runner->children[child_idx];
    idx++;
  }
}

void main ()
{
  int i;
  char *strs[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
  int strs_len = sizeof (strs) / sizeof (strs[0]);

  struct node root;
  memset (&root, 0, sizeof (struct node));

  for (i = 0; i < strs_len; i++)
    insert (&root, strs[i]);
}
