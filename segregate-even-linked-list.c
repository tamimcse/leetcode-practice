/*
https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/
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

void segregate_even_odd (struct node **head)
{
  struct node *runner = *head, *even_head = NULL, *even_tail = NULL, *odd_head = NULL, *odd_tail = NULL;

  while (runner) {
    if (runner->data & 1) {
      if (!odd_head) {
        odd_head = runner;
        odd_tail = runner;
      } else {
        odd_tail->next = runner;
        odd_tail = runner;
      }
    } else {
      if (!even_head) {
        even_head = runner;
        even_tail = runner;
      } else {
        even_tail->next = runner;
        even_tail = runner;
      }
    }
    runner = runner->next;
  }
  odd_tail->next = even_head;
  even_tail->next = NULL;
  *head = odd_head;
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
  segregate_even_odd (&head);
  print (head);
}
