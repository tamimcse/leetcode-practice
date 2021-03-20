/*
https://www.geeksforgeeks.org/reverse-a-doubly-linked-list/
*/
#include <stdio.h>

struct node {
  int data;
  struct node *next;
  struct node *prev;
};

void print (struct node *head)
{
  while (head) {
    printf ("%d ", head->data);
    head = head->next;
  }
  printf ("\n");
}

void reverse_double_ll (struct node **head)
{
  struct node *runner1 = *head, *runner2 = *head, *runner3;
  if (runner2)
    runner2 = runner2->next;

  while (runner2) {

  }
}

void main ()
{
  struct node n1, n2, n3;
  n1 = (struct node) {1, &n2, NULL};
  n2 = (struct node) {2, &n3, &n1};
  n3 = (struct node) {3, NULL, &n2};

  struct node *head = &n1;

  print (head);
  reverse_double_ll (&head);
  print (head);
}
