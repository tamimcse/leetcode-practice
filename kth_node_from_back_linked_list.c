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


void main ()
{
  struct node *head = NULL;

  insert (&head, 10);
  insert (&head, 20);
  insert (&head, 30);
  insert (&head, 40);
  insert (&head, 50);
  delete (&head, 40);
  insert (&head, 40);
  insert (&head, 50);
  delete (&head, 40);
  print (head);
}
