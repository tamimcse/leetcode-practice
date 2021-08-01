/*
https://leetcode.com/problems/binary-tree-right-side-view/

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define CAPACITY 300

struct Queue {
  struct TreeNode* nodes[CAPACITY];
  int len[CAPACITY];
  int start;
  int end;
};

void queue_init (struct Queue *q)
{
  q->start = 0;
  q->end = 0;
}

void enqueue (struct Queue *q, struct TreeNode* n, int len)
{
  q->nodes[q->end] = n;
  q->len[q->end] = len;
  q->end++;
}

void dequeue (struct Queue *q, struct TreeNode** n, int *len)
{
  *n = q->nodes[q->start];
  *len = q->len[q->start];
  q->start++;
}

bool queue_empty (struct Queue *q)
{
  return q->end == q->start;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize){
  struct Queue q;
  int *res = (int *) malloc (100 * sizeof (int));
  int res_cnt = 0, cur_len, last_level = 0;
  struct TreeNode* cur_node;
  
  if (!root) {
    *returnSize = 0;
    return NULL;
  }
  
  queue_init (&q);
  enqueue (&q, root, 1);
  while (!queue_empty (&q)) {
    dequeue (&q, &cur_node, &cur_len);
    if (cur_len != last_level) {
      res[res_cnt++] = cur_node->val;
      last_level = cur_len;
    }
    if (cur_node->right) {
      enqueue (&q, cur_node->right, cur_len+1);
    }
    if (cur_node->left) {
      enqueue (&q, cur_node->left, cur_len+1);
    }
  }
  *returnSize = res_cnt;
  return res;
}
