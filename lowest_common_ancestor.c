/*
https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
*/
#include <stdio.h>

struct node {
  int value;
  struct node *left;
  struct node *right;
};

bool is_descendent (struct node *root, int n)
{
  if (!root)
    return false;
  if (root->value == n)
    return true;
  return is_descendent (root->left, n) || is_descendent (root->right, n);
}

struct node* LCA (struct node *root, int n1, int n2)
{
  if (!root)
    return NULL;
  if (!root->left || !root->right)
    return NULL;

  struct node *left_subtree = NULL, *right_subtree = NULL;
  left_subtree = 

  if (root->left->value == n1 && root->right->value == n2)
    return root;

  int left_hieght, right_hieght, h;
  if (!root || (!(root->left) && !(root->right)))
    return 0;

  left_hieght = height (root->left);
  right_hieght = height (root->right);
  h = left_hieght > right_hieght ? left_hieght : right_hieght;
  return h + 1;
}

void main ()
{
  struct node n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11;
  n1 = (struct node ){1, &n2, &n3};
  n2 = (struct node ){2, &n4, &n5};
  n3 = (struct node ){3, NULL, &n6};
  n4 = (struct node ){4, NULL, NULL};
  n5 = (struct node ){5, NULL, &n9};
  n6 = (struct node ){6, &n7, &n8};
  n7 = (struct node ){7, NULL, NULL};
  n8 = (struct node ){8, NULL, NULL};
  n9 = (struct node ){9, NULL, &n10};
  n10 = (struct node ){10, &n11, NULL};
  n11 = (struct node ){11, NULL, NULL};

  //printf("%d %d %d \n", n1.value, n1.left->value, n1.right->value);

  int res = LCA (&n1, 4, 11);
  printf ("height of the tree is %d \n", res);
}
