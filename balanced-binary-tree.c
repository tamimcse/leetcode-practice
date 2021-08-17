/*
https://leetcode.com/problems/balanced-binary-tree/
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

int height (struct TreeNode *root, bool *ret)
{
  int left, right;
  
  if (!root)
    return 0;
  
  left =  height (root->left, ret);
  right =  height (root->right, ret);
  
  if (*ret == false)
    return max (left, right) + 1;
  
  if (abs (left - right) > 1) {
    *ret = false;
  }
  return max (left, right) + 1;
}

bool isBalanced(struct TreeNode* root){
  bool res = true;
  
  height (root, &res);
  return res;
}
