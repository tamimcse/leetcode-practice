/*
Rotating a linked list ‘k’ times to the right.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

void linkedlist_insert (struct node **head, int data)
{
  struct node *new_node = (struct node *) malloc (sizeof (*new_node));
  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}

void linkedlist_rotate (struct node **head, int k)
{
  int i;

  //find k-th element from the end
  struct node *runner1 = *head, *runner2 = NULL;
  i = 0;
  if (!*head)
    return;
  while (runner1->next) {
    if (i == k) {
      runner2 = *head;
    }
    i++;
    runner1 = runner1->next;
    if (runner2)
      runner2 = runner2->next;
  }
  //if k-th element is NULL
  if (!runner2)
    return;

  runner1->next = *head;
  *head = runner2->next;
  runner2->next = NULL;
}

void print (struct node *head)
{
  while (head) {
    printf ("%d ", head->data);
    head= head->next;
  }
  printf ("\n");
}

void main ()
{
  struct node *head = NULL;

  linkedlist_insert (&head, 8);
  linkedlist_insert (&head, 7);
  linkedlist_insert (&head, 6);
  linkedlist_insert (&head, 5);
  linkedlist_insert (&head, 4);
  linkedlist_insert (&head, 3);
  linkedlist_insert (&head, 2);
  linkedlist_insert (&head, 1);

  print(head);
  
  linkedlist_rotate (&head, 4);

  print(head);
}
