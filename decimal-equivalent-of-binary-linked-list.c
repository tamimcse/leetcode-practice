/*
https://www.geeksforgeeks.org/decimal-equivalent-of-binary-linked-list/
*/
#include <stdio.h>

struct node {
  int data;
  struct node *next;
};

int value (struct node *head)
{
  int val = 0;

  while (head) {
    val = (val << 1) + head->data;
    head = head->next;
  }
  return val;
}

void main ()
{
  struct node n1, n2, n3, n4, n5, n6;
  n1 = (struct node) {1, &n2};
  n2 = (struct node) {1, &n3};
  n3 = (struct node) {0, &n4};
  n4 = (struct node) {0, &n5};
  n5 = (struct node) {1, &n6};
  n6 = (struct node) {0, NULL};

  int res = value (&n1);

  printf ("Value is %d \n", res);
}
