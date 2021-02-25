/*
Reverse a linked list using recursion
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
} *head = NULL;

void insert (int val)
{
  struct node *new_node = (struct node *)malloc (sizeof (*new_node));
  new_node->data = val;
  if (!head) {
    head = new_node;
  } else {
    new_node->next = head;
    head = new_node;
  }
}

void print ()
{
  struct node *runner = head;

  while (runner) {
    printf ("%d ", runner->data);
    runner = runner->next;
  }
  printf ("\n");
}

void reverse ()
{
  //the list is empty or have just one item
  if (!head || !head->next) {
    return;
  }

  struct node *runner1, *runner2, *nxt_runner2;
  runner1 = head;
  runner2 = head->next;
  runner1->next = NULL;
  while (runner2) {
    nxt_runner2 = runner2->next;
    runner2->next = runner1;
    runner1 = runner2;
    runner2 = nxt_runner2;
  }
  head = runner1;
}

void main ()
{
  insert (3);
  insert (5);
  insert (8);
  insert (10);
  print ();
  reverse ();
  print ();
}
