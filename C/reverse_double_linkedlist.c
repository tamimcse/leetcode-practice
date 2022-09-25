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
  struct node *runner1 = NULL, *runner2 = *head, *runner3;
  if (runner2)
    runner2 = runner2->next;

  while (runner2) {
    runner1 = runner2->prev;
    runner3 = runner2->next;
    runner2->next = runner1;
    runner1->prev = runner2;
    runner2 = runner3;
  }
  (*head)->next = NULL;
  *head = runner1->prev;
}

void main ()
{
  struct node n1, n2, n3, n4, n5;
  n1 = (struct node) {1, &n2, NULL};
  n2 = (struct node) {2, &n3, &n1};
  n3 = (struct node) {3, &n4, &n2};
  n4 = (struct node) {4, &n5, &n3};
  n5 = (struct node) {5, NULL, &n4};

  struct node *head = &n1;

  print (head);
  reverse_double_ll (&head);
  print (head);
}
