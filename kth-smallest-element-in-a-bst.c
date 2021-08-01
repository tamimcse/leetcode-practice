/*
https://leetcode.com/problems/kth-smallest-element-in-a-bst/
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void kthSmallest_inner (struct TreeNode* root, int *k, int *res)
{
  if (root->left)
    kthSmallest_inner (root->left, k, res);
  if (*res >= 0)
    return res;
  --(*k);
  if (*k == 0) {
    *res = root->val;
    return;
  }
  if (root->right)
    kthSmallest_inner (root->right, k, res);
}

int kthSmallest(struct TreeNode* root, int k){
  int res = -1;
  
  kthSmallest_inner (root, &k, &res);
  return res;
}
