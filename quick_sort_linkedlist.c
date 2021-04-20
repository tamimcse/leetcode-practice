/*
https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/
*/
#include <stdio.h>
#include <stdlib.h>

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

struct node* partition (struct node *head, struct node *tail)
{
  int tmp;
  int pivot = tail->data;
  struct node *runner = head;
  struct node *leftmost_larger = NULL;
  
  while (runner != tail) {
    if (runner->data > pivot && !leftmost_larger) {
      leftmost_larger = runner;
    } else if (runner->data < pivot && leftmost_larger) {
      tmp = leftmost_larger->data;
      leftmost_larger->data = runner->data;
      runner->data = tmp;
      leftmost_larger = leftmost_larger->next;
    }
    runner = runner->next;
  }

  if (leftmost_larger) {
//    printf ("leftmost_larger = %d \n", leftmost_larger->data);
    tail->data = leftmost_larger->data;
    leftmost_larger->data = pivot;
    return leftmost_larger;
  } else {
    return tail;
  }
}

void quick_sort (struct node *head, struct node *tail)
{
  struct node *pivot = partition (head, tail);

  if (head != pivot && head->next != pivot)
    quick_sort (head, pivot->prev);
  if (tail != pivot && pivot->next != tail)
    quick_sort (pivot->next, tail);
}

void insert (struct node **head, struct node **tail, int data)
{
  struct node *new_node = (struct node *) malloc (sizeof (*new_node));
  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = *tail;
  if (*tail)
    (*tail)->next = new_node;
  *tail = new_node;
  if (!(*head))
    *head = new_node;
}

void main ()
{
  int arr[] = {20, 1, 3, 4, 8, 7, 12, 2, 14, 25};
  struct node *head = NULL, *tail = NULL;
  for (int i = 0; i < sizeof (arr) / sizeof (arr[0]); i++) {
    insert (&head, &tail, arr[i]);
  }

  quick_sort (head, tail);

  print (head);
}
