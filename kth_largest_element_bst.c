/*
https://www.geeksforgeeks.org/kth-largest-element-in-bst-when-modification-to-bst-is-not-allowed/
*/
#include <stdio.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

int k_th_largest_number_inner (struct node *root, int *count, int k)
{
  int res;

  if (root->right) {
    res = k_th_largest_number_inner (root->right, count, k);
    if (*count == k)
      return res;
  }

  (*count)++;
  if (*count == k)
    return root->data;

  if (root->left) {
    res = k_th_largest_number_inner (root->left, count, k);
    if (*count == k)
      return res;
  }
  //return res;
}

int k_th_largest_number(struct node *root, int k)
{
  int count = 0;
  return k_th_largest_number_inner (root, &count, k);
}

void main ()
{
  struct node n20, n8, n22, n4, n12, n10, n14;
  n20 = (struct node) {20, &n8, &n22};
  n8 = (struct node) {8, &n4, &n12};
  n22 = (struct node) {22, NULL, NULL};
  n4 = (struct node) {4, NULL, NULL};
  n12 = (struct node) {12, &n10, &n14};
  n10 = (struct node) {10, NULL, NULL};
  n14 = (struct node) {14, NULL, NULL};

  int k = 3;
  int res = k_th_largest_number (&n20, k);
  printf ("%d-th largest element is is %d \n", k, res);
}
