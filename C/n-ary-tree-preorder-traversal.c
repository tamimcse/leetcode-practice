/*
https://leetcode.com/problems/n-ary-tree-preorder-traversal/

Note that you will be asked to give an iterative solution. Recursive solution is too easy.
*/
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorder(struct Node* root, int* returnSize) {
  struct Node **stack = (struct Node **) malloc (20000 * sizeof (stack));
  int s_idx = 0;
  int *res = (int *) malloc (10000 * sizeof (*res));
  int res_cnt = 0;
  struct Node *curr;
  int i, j;
  
  if (!root) {
    *returnSize = 0;
    return NULL;
  }
    
  stack[s_idx++] = root;
  while (s_idx) {
    curr = stack[--s_idx];
    res[res_cnt++] = curr->val;
    for (i = curr->numChildren - 1; i >= 0; i--) {
      stack[s_idx++] = curr->children[i];
    }
  }
  *returnSize = res_cnt;
  return res;
}
