/*
https://www.geeksforgeeks.org/diagonal-sum-binary-tree/
*/
#include <stdio.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

void diagonal_sum_inner (struct node *root, int arr[], int curr_idx)
{
  if (!root)
    return;
  arr[curr_idx] += root->data;
  diagonal_sum_inner (root->left, arr, curr_idx + 1);
  diagonal_sum_inner (root->right, arr, curr_idx);
}

void diagonal_sum (struct node *root)
{
  int i;
  int arr[5] = {0};

  diagonal_sum_inner (root, arr, 0);
  for (i = 0; i < 5; i++) {
    printf ("arr[%d] = %d \n", i, arr[i]);
  }
}

void main ()
{
  struct node n1, n2, n3, n4, n5, n6, n7, n9, n10, n11, n12;
  n1 = (struct node) {1, &n2, &n3};
  n2 = (struct node) {2, &n9, &n6};
  n3 = (struct node) {3, &n4, &n5};
  n4 = (struct node) {4, &n12, &n7};
  n5 = (struct node) {5, NULL, NULL};
  n6 = (struct node) {6, &n11, NULL};
  n7 = (struct node) {7, NULL, NULL};
  n9 = (struct node) {9, NULL, &n10};
  n10 = (struct node) {10, NULL, NULL};
  n11 = (struct node) {11, NULL, NULL};
  n12 = (struct node) {12, NULL, NULL};
 
  diagonal_sum (&n1);
}
