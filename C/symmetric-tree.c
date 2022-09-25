/*
https://www.geeksforgeeks.org/symmetric-tree-tree-which-is-mirror-image-of-itself/
*/
#include <stdio.h>
#include <stdbool.h>

struct node {
  int val;
  struct node *left;
  struct node *right;
};

bool is_mirror (struct node *r1, struct node *r2)
{
  bool res;

  if (!r1 && !r2)
    return true;
  if ((r1 && !r2) || (!r1 && r2))
    return false;
  if (r1->val != r2->val)
    return false;
  res = is_mirror (r1->left, r2->right);
  if (!res)
    return false;
  res = is_mirror (r1->right, r2->left);
  return res;
}

bool is_symetric (struct node *root)
{
  return is_mirror (root, root);
}

void main ()
{
  struct node n1, n2, n3, n4, n5, n6, n7;
  n1 = (struct node) {1, &n2, &n3};
  n2 = (struct node) {2, &n4, &n5};
  n3 = (struct node) {2, &n6, &n7};
  n4 = (struct node) {3, NULL, NULL};
  n5 = (struct node) {4, NULL, NULL};
  n6 = (struct node) {4, NULL, NULL};
  n7 = (struct node) {3, NULL, NULL};

  bool res = is_symetric (&n1);
  printf ("The tree %s a symetric tree\n", res ? "is" : "isn't");
}
