/*
https://leetcode.com/problems/path-sum/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode* root, int targetSum){
  bool left = false, right = false;
  
  if (!root) {
    return false;
  }
  
  if (!(root->left) && !(root->right))
    return root->val == targetSum;
  
  if (root->left)
    left = hasPathSum (root->left, targetSum - root->val);
  if (root->right)
    right = hasPathSum (root->right, targetSum - root->val);
  
  return left || right;
}
