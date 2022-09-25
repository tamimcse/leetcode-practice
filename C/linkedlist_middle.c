/*
https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
*/
#include <stdio.h>

struct node {
  int value;
  struct node *next;
};

struct node* find_middle1 (struct node* head)
{
  struct node *runner1 = head, *runner2 = head;

  while (runner1->next) {
    runner1 = runner1->next;
    if (runner1)
      runner1 = runner1->next;
    runner2 = runner2->next;
  }
  return runner2;
}

struct node* find_middle2 (struct node* head)
{
  struct node *runner1 = head;
  int count = 0;

  while (head) {
    count++;
    if (count & 1)
      runner1 = runner1->next;
    head = head->next;
  }
  return runner1;
}


void main ()
{
  struct node n1, n2, n3, n4, n5;
  n1 = (struct node){1, &n2};
  n2 = (struct node){2, &n3};
  n3 = (struct node){3, &n4};
  n4 = (struct node){4, &n5};
  n5 = (struct node){5, NULL};

  int res1 = find_middle1 (&n1)->value;
  int res2 = find_middle1 (&n1)->value;

  printf ("Middle element is %d and %d \n", res1, res2);
}


