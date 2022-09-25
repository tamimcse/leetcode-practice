/*
https://leetcode.com/problems/inorder-successor-in-bst/
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* find_root (struct TreeNode* root, struct TreeNode* p)
{
  struct TreeNode *res = NULL, *runner = NULL;
  
  if (!root)
    return NULL;
  runner = root->left;
  while (runner && runner->right)
    runner = runner->right;
  if (runner == p)
    return root;
  res = find_root (root->left, p);
  if (res)
    return res;
  return find_root (root->right, p);
}

struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p) {
  struct TreeNode *runner;
  if (p->right) {
    runner = p->right;
    while (runner->left) {
      runner = runner->left;
    }
    return runner;
  }
  return find_root (root, p);
}
