/*
How to delete a node in linklist, when value of that node is given.
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

int delete (struct node **head, int val)
{
  struct node *runner = *head, *to_delete = NULL;

  if (!*head)
    return 1;

  if ((*head)->data == val) {
    *head = (*head)->next;
    free (runner);
    return 0;
  }
  
  while (runner->next) {
    if (runner->next->data == val) {
      to_delete = runner->next;
      runner->next = runner->next->next;
      free (to_delete);
      return 0;
    }
    runner = runner->next;
  }
  return 1;
}

void print (struct node *head)
{
  while (head) {
    printf ("%d ", head->data);
    head = head->next;
  }
  printf ("\n");
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
  print (head);
}
