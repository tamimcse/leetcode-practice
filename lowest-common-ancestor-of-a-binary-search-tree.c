/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
  struct TreeNode *smaller, *larger, *runner;
  
  if (p->val < q->val) {
    smaller = p;
    larger = q;
  } else {
    smaller = q;
    larger = p;
  }

  runner = smaller;
  while (runner) {
    if (runner == larger)
      return smaller;
    if (larger->val > runner->val)
      runner = runner->right;
    else
      runner = runner->left;
  }
  
  runner = larger;
  while (runner) {
    if (runner == smaller)
      return larger;
    if (smaller->val > runner->val)
      runner = runner->right;
    else
      runner = runner->left;
  }

  runner = root;
  while (runner) {
    if (runner->val > smaller->val && runner->val < larger->val)
      return runner;
    if (runner->val > larger->val)
      runner = runner->left;
    else
      runner = runner->right;
  }
  return NULL;
}
