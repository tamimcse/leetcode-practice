/*
https://leetcode.com/problems/validate-binary-search-tree/

https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/

May look simple, but it's not :)
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX (1LL << 35)

bool isValidBST_inner (struct TreeNode* root, double *last)
{
  bool res;
  
  if (!root)
    return true;
  
  res = isValidBST_inner (root->left, last);
  if (!res)
    return false;
  
  if (*last == MAX) {
    *last = root->val;
  } else {
    if (root->val <= *last)
      return false;
    else
      *last = root->val;
  }
  
  res = isValidBST_inner (root->right, last);
  return res;
}

bool isValidBST(struct TreeNode* root){
  double last = MAX;
  
  return isValidBST_inner (root, &last);
}
