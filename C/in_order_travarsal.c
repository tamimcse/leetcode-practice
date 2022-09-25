/*
https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

void inorder1(struct node *r)
{
  if (!r)
    return;
  inorder1 (r->left);
  printf ("%d ", r->data);
  inorder1 (r->right);
}

void inorder2(struct node *r)
{
  struct node *stack[100];
  struct node *curr;
  int start = 0;

  if (!r)
    return;

  int backtracking = 0;
  stack[start++] = r;
  while (start) { 
    curr = stack[start - 1];
    if (!backtracking && curr->left) {
      stack[start++] = curr->left;
      //going deep
      backtracking = 0;
    } else {
      backtracking = 1;
      curr = stack[--start];
      printf ("%d ", curr->data);
      if (curr->right) {
        stack[start++] = curr->right;
        //going deep
        backtracking = 0;
      }
    }
  }
}

struct node_stack {
  struct node *n;
  struct node_stack *next;
};

void push (struct node_stack **head, struct node *n)
{
  struct node_stack *new_node = (struct node_stack *) malloc (sizeof (*new_node));
  new_node->n = n;
  new_node->next = *head;
  *head = new_node;
}

struct node* pop (struct node_stack **head)
{
  struct node *res;
  struct node_stack *tmp;

  if (!(*head))
    return NULL;
  res = (*head)->n;
  tmp = *head;
  *head = (*head)->next;
  free (tmp);
  return res;
}


void inorder3(struct node *r)
{
  struct node *curr_node;
  struct node_stack *stack = NULL;

  if (!r)
    return;

  curr_node = r;
  while (1) {
    if (!curr_node) {
      curr_node = pop (&stack);
      if (!curr_node)
        break;
      printf ("%d ", curr_node->data);
      curr_node = curr_node->right;
    } else if (curr_node->left) {
      push (&stack, curr_node);
      curr_node = curr_node->left;
    } else {
      printf ("%d ", curr_node->data);
      curr_node = curr_node->right;
    }
  }
}


void main ()
{
  struct node n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
  n1 = (struct node) {1, &n2, &n3};
  n2 = (struct node) {2, &n4, &n5};
  n3 = (struct node) {3, NULL, &n6};
  n4 = (struct node) {4, NULL, NULL};
  n5 = (struct node) {5, &n7, NULL};
  n6 = (struct node) {6, &n8, NULL};
  n7 = (struct node) {7, &n9, &n10};
  n8 = (struct node) {8, NULL, NULL};
  n9 = (struct node) {9, NULL, NULL};
  n10 = (struct node) {10, NULL, NULL};

  printf ("In order travarsal (recursive) = ");
  inorder1 (&n1);
  printf ("\n");
  printf ("In order travarsal (non recursive) = ");
  inorder2 (&n1);
  printf ("\n");
  printf ("In order travarsal (non recursive - following geekforgeeks) = ");
  inorder3 (&n1);
  printf ("\n");
}
