/*
Reverse a linked list (recursive version)
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

void insert (struct node **head, int val)
{
  struct node *new_node = (struct node *)malloc (sizeof (*new_node));
  new_node->data = val;
  if (!*head) {
    *head = new_node;
  } else {
    new_node->next = *head;
    *head = new_node;
  }
}

static void print (struct node *head)
{
  struct node *runner = head;

  while (runner) {
    printf ("%d ", runner->data);
    runner = runner->next;
  }
  printf ("\n");
}

struct node *reverse_internal (struct node **head, struct node *start)
{
  struct node *next = start->next;

  //last node
  if (!next->next) {
    next->next = start;
    *head = next;
    return start;
  }
  next = reverse_internal (head, next);
  next->next = start;
}

void reverse (struct node **head)
{
  //the list is empty or have just one item
  if (!*head || !(*head)->next) {
    return;
  }

  struct node *runner1, *runner2;
  runner1 = *head;
  runner2 = (*head)->next;
  runner2 = reverse_internal (head, runner2);
  runner2->next = runner1;
  runner1->next = NULL;
}

void main ()
{
  struct node *head = NULL;

  insert (&head, 3);
  insert (&head, 5);
  insert (&head, 8);
  insert (&head, 10);
  print (head);
  reverse (&head);
  print (head);
}
