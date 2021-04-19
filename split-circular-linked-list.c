/*
https://www.geeksforgeeks.org/split-a-circular-linked-list-into-two-halves/
*/
#include <stdio.h>

struct node {
  int data;
  struct node *next;
};

void split (struct node *head, struct node **res1, struct node **res2)
{
  if (!head || !(head->next))
    return;

  struct node *runner1 = head, *runner2 = head->next;

  while (runner2->next != head && runner2->next->next != head) {
    runner2 = runner2->next->next;
    runner1 = runner1->next;
  }

  *res2 = runner1->next;
  *res1 = head;

  runner2->next = runner1->next;
  runner1->next = head;
}

void print (struct node *head)
{
  struct node *runner = head;
  printf ("List = ");
  do {
    printf ("%d ", runner->data);
    runner = runner->next;
  } while (runner != head);
  printf ("\n");
}

void main ()
{
  struct node n1, n2, n3, n4, n5, n6;
  n1 = (struct node) {1, &n2};
  n2 = (struct node) {2, &n3};
  n3 = (struct node) {3, &n4};
  n4 = (struct node) {4, &n5};
  n5 = (struct node) {5, &n6};
  n6 = (struct node) {6, &n1};

  struct node *res1 = NULL, *res2 = NULL;
  split (&n1, &res1, &res2);

  print (res1);
  print (res2);
}
