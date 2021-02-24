/*
Implement hash map operations
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_BUCKET 10

int hash (int val)
{
  return val % NUM_BUCKET;
}

struct node {
  int data;
  struct node *next;
};

struct node hashmap[NUM_BUCKET];

struct node* search (int val)
{
  struct node *runner = NULL;
  int bucket_no = hash (val);

  runner = hashmap[bucket_no].next;
  while (runner) {
    if (runner->data == val)
      return runner;
    runner = runner->next;
  }
  return NULL;
}

bool insert (int val)
{
  struct node* n = search (val);

  //already exists
  if (n)
    return false;

  struct node* new_node = (struct node*) malloc (sizeof (*new_node));
  new_node->data = val;
  int bucket_no = hash (val);
  struct node* head = &hashmap[bucket_no];
  new_node->next = head->next;
  head->next = new_node;
  return true;
}

bool delete (int val)
{
  struct node *runner = NULL;
  int bucket_no = hash (val);

  runner = &hashmap[bucket_no];
  while (runner->next) {
    if (runner->next && runner->next->data == val) {
      struct node *to_delete = runner->next;  
      runner->next = runner->next->next;
      free (to_delete);
      return true;
    }
    runner = runner->next;
  }
  return false;
}

void print ()
{
  int i;
  struct node *runner;

  for (i = 0; i < NUM_BUCKET; i++) {
    runner = &hashmap[i];
    printf ("%d. ", i);
    while (runner->next) {
      printf ("%d ", runner->next->data);
      runner = runner->next;
    }
    printf ("\n");
  }
}

void main ()
{
  insert (1);
  insert (2);
  insert (3);
  insert (4);
  insert (101);
  insert (102);
  insert (103);
  insert (104);
  insert (201);
  insert (202);
  insert (203);
  insert (204);
  print();
  delete (2);
  delete (103);
  delete (204);
  print ();
}
