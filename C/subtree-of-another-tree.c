/*
https://leetcode.com/problems/subtree-of-another-tree/
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool same (struct TreeNode *t1, struct TreeNode *t2)
{
  bool left, right;
  if ((t1 && !t2) || (!t1 && t2))
    return false;
  if (!t1 && !t2)
    return true;
  if (t1->val != t2->val)
    return false;
  
  left = same (t1->left, t2->left);
  right = same (t1->right, t2->right);
  if (!left || !right)
    return false;
  else
    return true;
}

void preorder (struct TreeNode *t, struct TreeNode *sub, bool *res)
{
  if (!t || !sub)
    return;
  
  if (t->val == sub->val) {
    if (same (t, sub)) {
      *res = true;
      return;
    }
  }
  preorder (t->left, sub, res);
  preorder (t->right, sub, res);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
  bool res = false;
  
  preorder (root, subRoot, &res);
  return res;
}
