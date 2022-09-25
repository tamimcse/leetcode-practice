/*
https://leetcode.com/problems/minimum-depth-of-binary-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int min (int a, int b)
{
  return a < b ? a : b;
}

int minDepth(struct TreeNode* root){
  int left, right;
  
  if (!root)
    return 0;
  
  if (!(root->left) && !(root->right))
    return 1;
  if (root->left && root->right) {
    left = minDepth (root->left);
    right = minDepth (root->right);
    return min (left, right) + 1;    
  }
  if (root->left)
    return minDepth (root->left) + 1;
  else
    return minDepth (root->right) + 1;
}
