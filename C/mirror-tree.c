/*
https://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

//We could also do it usinmg post order travarsal
struct node* mirror_tree (struct node *r)
{
  if (!r)
    return NULL;

  struct node *new_node = (struct node *) malloc (sizeof (*new_node));
  new_node->data = r->data;
  new_node->left = mirror_tree (r->right);
  new_node->right = mirror_tree (r->left);
  return new_node;
}

void print (struct node *r)
{
  if (!r)
    return;
  printf ("%d ", r->data);
  print (r->left);
  print (r->right);
}

void main ()
{
  struct node n1, n2, n3, n4, n5;
  n1 = (struct node) {1, &n3, &n2};
  n2 = (struct node) {2, &n5, &n4};
  n3 = (struct node) {3, NULL, NULL};
  n4 = (struct node) {4, NULL, NULL};
  n5 = (struct node) {5, NULL, NULL};

  printf ("Original tree = ");
  print (&n1);
  printf ("\n");

  struct node *res = mirror_tree (&n1);

  printf ("Mirror tree = ");
  print (res);
  printf ("\n");
}
