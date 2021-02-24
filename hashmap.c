#include <stdio.h>

#define NUM_BUCKET 100

int hash (int val)
{
  return val % NUM_BUCKET;
}

struct node {
  int data;
  struct node *next;
}

struct node hashmap[NUM_BUCKET];

struct node* search (int val)
{
  struct node *runner = NULL;
  int bucket_no = hash (val);

  runner = hashmap[bucket_no].next;
  while (runner) {
    if (runner->value == val)
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
  int bucket_no = hash (val);
  struct node* head = &hashmap[bucket_no];
  new_node->next = head->next;
  head->next = new_node;
  return true;
}

void main ()
{

}
