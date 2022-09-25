/*
https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/

https://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node* create_balanced_bst (int arr[], int start, int end)
{
  int mid = start + ((end - start) >> 1);
  struct node *new_node = (struct node *) malloc (sizeof (*new_node));
  new_node->data = arr[mid];
  printf ("Creating node %d \n", new_node->data);
  if (start <= mid - 1)
    new_node->left = create_balanced_bst (arr, start, mid - 1);
  else
    new_node->left = NULL;
  if (end >= mid + 1)
    new_node->right = create_balanced_bst (arr, mid + 1, end);
  else
    new_node->right = NULL;
}

void in_order (struct node *root)
{
  if (!root)
    return;
  in_order (root->left);
  printf ("%d ", root->data);
  in_order (root->right);
}

void main ()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  int arr_len = sizeof (arr) / sizeof (arr[0]);

  struct node *root = create_balanced_bst (arr, 0, arr_len - 1);
  in_order (root);
  printf ("\n");
}
