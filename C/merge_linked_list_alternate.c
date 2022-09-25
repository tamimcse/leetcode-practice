/*
Merge a linked list into another linked list at alternate positions:

Given two linked lists, insert nodes of second list into first list at alternate positions of first list.
For example, if first list is 5->7->17->13->11 and second is 12->10->2->4->6, the first list should become 5->12->7->10->17->2->13->4->11->6 and second list should become empty. The nodes of second list should only be inserted when there are positions available. For example, if the first list is 1->2->3 and second list is 4->5->6->7->8, then first list should become 1->4->2->5->3->6 and second list to 7->8.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

void insert (struct node **head, int val)
{
  struct node* new_node = (struct node*) malloc (sizeof (*new_node));
  new_node->data = val;
  new_node->next = *head;
  *head = new_node;
}

void print (struct node *head)
{
  struct node *runner = head;

  while (runner) {
    printf ("%d ", runner->data);
    runner = runner->next;
  }
  printf ("\n");
}

void merge (struct node *head1, struct node **head2)
{
  struct node *runner1 = head1, *runner2;

  while (runner1) {
    //second list is empty
    if (!*head2)
      break;
    runner2 = *head2;
    *head2 = (*head2)->next;
    runner2->next = runner1->next;
    runner1->next = runner2;
    runner1 = runner1->next->next;
  }
}

void main ()
{
  struct node *head1 = NULL, *head2 = NULL;
  
  insert (&head1, 6);
  insert (&head1, 5);
  insert (&head1, 4);
  insert (&head1, 3);

  insert (&head2, 16);
  insert (&head2, 15);
  insert (&head2, 14);
  insert (&head2, 13);
  insert (&head2, 12);
  insert (&head2, 11);

  print (head1);
  print (head2);
  
  merge (head1, &head2);

  print (head1);
  print (head2);
}
