/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* LCA_inner(struct TreeNode* root, struct TreeNode* p, 
               struct TreeNode* q, struct TreeNode** lca)
{
    struct TreeNode *res = NULL, *res1 = NULL, *res2 = NULL; 
  
    if (!root)
      return NULL;
  
    if (*lca)
      return root;
  
    if (root == p || root == q) {
      res = LCA_inner (root->left, p, q, lca);
      if (res) {
        *lca = root;
        return root;
      }
      res = LCA_inner (root->right, p, q, lca);
      if (res) {
        *lca = root;
        return root;
      }
      return root;
    }
    
    res1 = LCA_inner (root->left, p, q, lca);
    res2 = LCA_inner (root->right, p, q, lca);
  
    if (*lca)
      return root;
  
    if (res1 && res2) {
      *lca = root;
      return root;
    }
  
    return res1 ? res1 : res2;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (!root)
      return NULL;
    
    struct TreeNode *lca = NULL;
  
    LCA_inner (root, p, q, &lca);
    return lca;
}
