/*
https://leetcode.com/problems/find-mode-in-binary-search-tree/

Very very interesting problem!!!!!
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int prev, count, max;

void inorder (struct TreeNode *root, int *res, int *res_cnt)
{
  if (!root)
    return;
  inorder (root->left, res, res_cnt);
  if (root->val == prev) {
    count++;
  } else {
    prev = root->val;
    count = 1;
  }
  if (count > max) {
    max = count;
    res[0] = root->val;
    *res_cnt = 1;
  } else if (count == max) {
    res[*res_cnt] = root->val;
    *res_cnt += 1;
  }
  inorder (root->right, res, res_cnt);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMode(struct TreeNode* root, int* returnSize){
  int *res = (int *) malloc (10000 * sizeof (int));
  int res_cnt = 0;
  
  prev = 100001;
  count = 0; 
  max = 0;
  inorder (root, res, &res_cnt);
  *returnSize = res_cnt;
  return res;
}
