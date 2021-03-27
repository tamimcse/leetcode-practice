/*
https://www.geeksforgeeks.org/check-if-a-binary-tree-is-subtree-of-another-binary-tree/
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool is_equal (struct node *r1, struct node *r2)
{
  struct node_stack *stack1 = NULL, *stack2 = NULL;
  struct node *curr_node1 = r1, *curr_node2 = r2;
  bool res = false;

  while (1) {
    if ((!curr_node1 && curr_node2) || (curr_node1 && !curr_node2)) {
      //should clean the stack as well
      return false;
    }
    if (!curr_node1) {
      curr_node1 = pop (&stack1);
      curr_node2 = pop (&stack2);
      if (!curr_node1 && !curr_node2)
        return true;
      else if ((!curr_node1 && curr_node2) || (curr_node1 && !curr_node2))
        return false;
    }
    if (curr_node1->data != curr_node2->data)
      return false;
    if (curr_node1->right)
      push (&stack1, curr_node1->right);
    curr_node1 = curr_node1->left;
    if (curr_node2->right)
      push (&stack2, curr_node2->right);
    curr_node2 = curr_node2->left;
  }
}

bool is_subtree1 (struct node *r1, struct node *r2)
{
  struct node *curr_node;
  struct node_stack *stack = NULL;

  if (!r1 || !r2)
    return false;
  
  curr_node = r1;
  while (1) {
    if (!curr_node) {
      curr_node = pop (&stack);
      if (!curr_node)
        break;
    }
    //start checking subtree
    if (curr_node->data == r2->data) {
      bool res = is_equal (curr_node, r2);
      if (res)
        return true;
    }
    if (curr_node->right)
      push (&stack, curr_node->right);
    curr_node = curr_node->left;
  }
  return false;
}

bool is_subtree2 (struct node *r1, struct node *r2)
{
  bool res;
  if (!r2)
    return true;
  if (!r1)
    return false;
  if (r1->data == r2->data) {
    res = is_equal (r1, r2);
    if (res)
      return true;
  } else {
    res = is_subtree2 (r1->left, r2);
    if (res)
      return true;
    res = is_subtree2 (r1->right, r2);
    if (res)
      return true;
    return false;
  }
}

void main ()
{
  //tree 1
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

  //tree 2
  struct node m5, m7, m9, m10;
  m5 = (struct node) {5, &m7, NULL};
  m7 = (struct node) {7, &m9, &m10};
  m9 = (struct node) {9, NULL, NULL};
  m10 = (struct node) {10, NULL, NULL};

  bool res = is_subtree1 (&n1, &m5);
  if (res)
    printf ("Subtree\n");
  else
    printf ("Not Subtree\n");

  bool res1 = is_subtree2 (&n1, &m5);
  if (res1)
    printf ("Subtree\n");
  else
    printf ("Not Subtree\n");
}

