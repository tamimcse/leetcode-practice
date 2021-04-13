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

bool search (struct node *root, char *str)
{
  struct node *child, *new_node;
  struct node *runner = root;
  int idx = 0;
  int child_idx;

  while (1) {
    child_idx = str[idx] - 'a';
    if (!runner->children[child_idx])
      return false;
    if (!str[idx + 1])
      return runner->children[child_idx]->end_of_the_word;
    runner = runner->children[child_idx];
    idx++;
  }
  return false;
}

void main ()
{
  int i;
  char *key;
  bool res;
  char *strs[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
  int strs_len = sizeof (strs) / sizeof (strs[0]);

  struct node root;
  memset (&root, 0, sizeof (struct node));

  for (i = 0; i < strs_len; i++)
    insert (&root, strs[i]);

  key = "their";
  res = search (&root, key);
  printf ("%s %s found \n", key, res ? "is" : "is not");
}
