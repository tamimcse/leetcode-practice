/*
Find distance between two nodes of a Binary Tree

https://www.geeksforgeeks.org/find-distance-between-two-nodes-of-a-binary-tree/
*/
#include <stdio.h>

struct node {
  int value;
  struct node *left;
  struct node *right;
};

struct node* lca (struct node *root, int n1, int n2)
{
  if (!root)
    return NULL;

  if (root->value == n1 || root->value == n2)
    return root;

  struct node* left_res = lca (root->left, n1, n2);
  struct node* right_res = lca (root->right, n1, n2);

  if (left_res && right_res)
    return root;
  else
    return left_res ? left_res : right_res;
}

int node_distance_inner (struct node *root, int n)
{
  if (!root)
    return -1;

  if (root->value == n)
    return 0;

  int l = node_distance_inner (root->left, n);
  int r = node_distance_inner (root->right, n);
  if (l >= 0 || r >= 0)
    return l >= 0 ? l + 1 : r + 1;
  else
    return -1;
}

int node_distance (struct node *root, int n1, int n2)
{
  struct node* common_ancestor = lca (root, n1, n2);

  if (common_ancestor->value == n1) {
    return node_distance_inner (common_ancestor, n2);
  } else if (common_ancestor->value == n2) {
    return node_distance_inner (common_ancestor, n1);
  } else {
    int n1_depth = node_distance_inner (common_ancestor, n1);
    int n2_depth = node_distance_inner (common_ancestor, n2);
    return n1_depth + n2_depth;
  }
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

  int res = node_distance (&n1, 4, 11);
  printf ("The node distance of the nodes is %d \n", res);
}
