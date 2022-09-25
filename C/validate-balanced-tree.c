/*
https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

void is_balanced_inner (struct node *root, int *max_depth, int *min_depth, int current_depth)
{
  if (!root)
    return;
  //leaf
  if (!root->left && !root->right) {
    if (current_depth > *max_depth)
      *max_depth = current_depth;
    if (current_depth < *min_depth)
      *min_depth = current_depth;
  } else {
    is_balanced_inner (root->left, max_depth, min_depth, current_depth + 1);
    is_balanced_inner (root->right, max_depth, min_depth, current_depth + 1);
  }
}

#define INF 100
#define NINF -100

bool is_balanced (struct node *root)
{
  int max_depth = NINF, min_depth = INF;
  is_balanced_inner (root, &max_depth, &min_depth, 0);
  printf ("max_depth = %d min_depth = %d \n", max_depth, min_depth);
  return max_depth - min_depth == 1;
}

void main ()
{
  struct node n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13;
  n1 = (struct node) {1, &n2, &n3};
  n2 = (struct node) {2, &n4, &n5};
  n3 = (struct node) {3, NULL, &n8};
  n4 = (struct node) {4, &n6, &n7};
  n5 = (struct node) {5, NULL, &n9};
  n6 = (struct node) {6, NULL, NULL};
  n7 = (struct node) {7, NULL, NULL};
  n8 = (struct node) {8, &n10, NULL};
  n9 = (struct node) {9, &n11, NULL};
  n10 = (struct node) {10, NULL, &n12};
  n11 = (struct node) {11, NULL, &n13};
  n12 = (struct node) {12, NULL, NULL};
  n13 = (struct node) {13, NULL, NULL};

  bool res = is_balanced (&n1);
  printf ("The tree %s balanced\n", res ? "is" : "is not");
}
