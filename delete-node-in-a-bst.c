/*
https://leetcode.com/problems/delete-node-in-a-bst/

https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

geeksforgeeks explanantion is better
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* predecessor (struct TreeNode* root)
{
  if (!root->left)
    return NULL;
  root = root->left;
  while (root->right)
    root = root->right;
  return root;
}

struct TreeNode* succesoor (struct TreeNode* root)
{
  if (!root->right)
    return NULL;
  root = root->right;
  while (root->left)
    root = root->left;
  return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key){
  struct TreeNode *runner = root, *prev = NULL;
  struct TreeNode *succ, *pred;
  
  while (runner) {
    if (runner->val == key) {
      if (!runner->left && !runner->right) {
        if (prev) {
          if (prev->val >= key) {
            prev->left = NULL;
          } else {
            prev->right = NULL;
          }
          return root;
        } else {
          return NULL;
        }
      } else if (!runner->left && runner->right) {
        if (prev) {
          if (prev->val >= key) {
            prev->left = runner->right;
          } else {
            prev->right = runner->right;
          }
          return root;
        } else {
          return runner->right;
        }
      } else if (runner->left && !runner->right) {
        if (prev) {
          if (prev->val >= key) {
            prev->left = runner->left;
          } else {
            prev->right = runner->left;
          }
          return root;
        } else {
          return runner->left;
        }
      } else {
        succ = succesoor (runner);
        runner->val = succ->val;
        runner->right = deleteNode (runner->right, succ->val);
        return root;
      }
    } else if (key > runner->val) {
      prev = runner;
      runner = runner->right;
    } else {
      prev = runner; 
      runner = runner->left;
    }
  }
  return root;
}
