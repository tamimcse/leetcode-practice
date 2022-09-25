/*
https://leetcode.com/problems/diameter-of-binary-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max (int a, int b)
{
  return a > b ? a : b;
}

int height(struct TreeNode* root, int *diameter)
{
  int left = 0, right = 0;
  
  if (!(root->left) && !(root->right))
    return 0;
  
  if (root->left)
    left = height (root->left, diameter) + 1;
  
  if (root->right)
    right = height (root->right, diameter) + 1;  
  
  if (left + right > *diameter)
    *diameter = left + right;
  return max (left, right);
}

int diameterOfBinaryTree(struct TreeNode* root){
  int diameter = 0;
  
  height (root, &diameter);
  return diameter;
}
