/*
How to find the nth node in singly linked list from back.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

void insert (struct node **head, int val)
{
  struct node *new_node = (struct node *) malloc (sizeof (*new_node));
  new_node->data = val;
  new_node->next = *head;
  *head = new_node;
}

struct node * find_kth_elemement_from_back (struct node *head, int k)
{
  struct node *runner1 = head, *runner2 = NULL;
  int i = 0;

  while (runner1) {
    ++i;
    if (i == k) {
      runner2 = head;
    } else if (i > k) {
      runner2 = runner2->next;
    }
    runner1 = runner1->next;
  }
  return runner2;
}

void main ()
{
  struct node *head = NULL;
  int k = 3;

  insert (&head, 10);
  insert (&head, 20);
  insert (&head, 30);
  insert (&head, 40);
  insert (&head, 50);
  insert (&head, 40);
  insert (&head, 50);
  struct node *res = find_kth_elemement_from_back (head, k);
  printf ("%d-th element from back is %d\n", k, res ? res->data : 0);
}
