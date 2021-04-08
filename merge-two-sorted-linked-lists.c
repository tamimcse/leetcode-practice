/*
https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/
*/
#include <stdio.h>

struct node {
  int data;
  struct node *next;
};

void merge (struct node **h1, struct node *h2)
{
  struct node *r1 = *h1, *r2 = h2, *tmp;

  if (r2 && r2->data < r1->data) {
    tmp = r2;
    r2 = r2->next;
    tmp->next = r1;
    *h1 = tmp;
    r1 = *h1;
  }

  while (r2) {
    if (!(r1->next)) {
      r1->next = r2;
      return;
    }
    if (r1->next->data >= r2->data) {
      tmp = r2->next;;
      r2->next = r1->next;
      r1->next = r2;
      r2 = tmp;
    } else {
      r1 = r1->next;
    }
  }
}

void main ()
{
  struct node n1, n2, n3, n4;
  n1 = (struct node) {5, &n2};
  n2 = (struct node) {10, &n3};
  n3 = (struct node) {15, &n4};
  n4 = (struct node) {40, NULL};

  struct node m1, m2, m3;
  m1 = (struct node) {2, &m2};
  m2 = (struct node) {3, &m3};
  m3 = (struct node) {20, NULL};

  struct node* h1 = &n1; 
  merge (&h1, &m1);

  printf ("Merged linked list = ");
  while (h1) {
    printf ("%d ", h1->data);
    h1 = h1->next;
  }
  printf ("\n");
}
