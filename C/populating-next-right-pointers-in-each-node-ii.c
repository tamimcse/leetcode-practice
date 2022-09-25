/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
*/
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
	struct Node *queue[12000];
  int level[12000];
  int q_start = 0, q_end = 0;
  int cur_level, last_level = 0;
  struct Node *cur_node, *prev;
  
  if (!root)
    return root;
  
  queue[q_end] = root;
  level[q_end] = 1;
  q_end++;
  while (q_end > q_start) {
    cur_node = queue[q_start];
    cur_level = level[q_start];
    q_start++;
    if (cur_level != last_level) {
      last_level = cur_level;
      prev = cur_node;
    } else {
      prev->next = cur_node;
      prev = cur_node;
    }
    if (cur_node->left) {
      queue[q_end] = cur_node->left;
      level[q_end] = cur_level + 1;
      q_end++;
    }
    if (cur_node->right) {
      queue[q_end] = cur_node->right;
      level[q_end] = cur_level + 1;
      q_end++;
    }
  }
  return root;
}
