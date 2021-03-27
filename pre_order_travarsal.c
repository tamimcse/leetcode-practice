#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

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

void preorder1 (struct node *root)
{
  if (!root)
    return;
  printf ("%d ", root->data);
  preorder1 (root->left);
  preorder1 (root->right);
}

void preorder2 (struct node *root)
{
  struct node *curr_node;
  struct node_stack *stack = NULL;

  if (!root)
    return;
  
  curr_node = root;
  while (1) {
    if (curr_node) {
      printf ("%d ", curr_node->data);
      if (curr_node->right)
        push (&stack, curr_node->right);
      curr_node = curr_node->left;
    } else {
      curr_node = pop (&stack);
      if (!curr_node)
        break;
      printf ("%d ", curr_node->data);
      if (curr_node->right)
        push (&stack, curr_node->right);
      curr_node = curr_node->left;      
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

  printf ("Pre order travarsal (recursive) = ");
  preorder1 (&n1);
  printf ("\n");
  printf ("Pre order travarsal (non recursive) = ");
  preorder2 (&n1);
  printf ("\n");
}

