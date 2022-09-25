/*
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

Take a look at the notes for the details hints
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buildTree_inner(int* in, int in_start, int in_end, int* post, int post_start, int post_end)
{
  int i, j, to_left = 0;
  struct TreeNode *root = (struct TreeNode *) calloc (1, sizeof (*root));
  
  if (in_start > in_end || post_start > post_end)
    return NULL;
  
  root->val = post[post_end];
  if (in_start == in_end)
    return root;
  for (i = in_start; i <= in_end; i++) {
    if (in[i] == post[post_end]) {
      root->left = buildTree_inner (in, in_start, i-1, post, post_start, post_start + to_left - 1);
      root->right = buildTree_inner (in, i + 1, in_end, post, post_start + to_left, post_end-1);
      return root;
    } else {
      to_left++;
    }
  }
  return NULL;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
  return buildTree_inner (inorder, 0, inorderSize-1, postorder, 0,
                          postorderSize-1);
}
