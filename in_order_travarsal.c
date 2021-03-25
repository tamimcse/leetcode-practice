/*
https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
*/
#include <stdio.h>

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
}
