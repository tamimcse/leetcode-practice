/*
Level order traversal of tree is same as BFS in graph. Implement level order travarsal.
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left, *right;
};

void insert_binary_search_tree (struct node **root, int val)
{
  struct node *runner;
  struct node *new_node = (struct node *) malloc (sizeof (*new_node));
  new_node->data = val;
  new_node->left = NULL;
  new_node->right = NULL;

  //The tree is empty
  if (!*root) {
    *root = new_node;
    return;
  }

  runner = *root;
  while (runner) {
    if (val >= runner->data) {
      if (runner->right) {
        runner = runner->right;
      } else {
        runner->right = new_node;
        break;
      }
    } else {
      if (runner->left) {
        runner = runner->left;
      } else {
        runner->left = new_node;
        break;
      }
    }
  }
}

#define QUEUE_SIZE 100

int level_order (struct node *root)
{
  struct node *runner;
  struct node *queue[QUEUE_SIZE] = {0};
  int start_ix = 0, end_ix = 0;

  if (!root)
    return 0;

  //insert root to queue
  queue[end_ix++] = root;

  //queue is not empty
  while (end_ix > start_ix) {
    //dequeue
    runner = queue[start_ix++];
    printf ("%d ", runner->data);
    //insert chieldren to queue
    if (end_ix >= QUEUE_SIZE) {
      printf ("Queue is full. Please increase the queue size\n");
      return 1;
    }
    if (runner->left)
      queue[end_ix++] = runner->left;
    if (runner->right)
      queue[end_ix++] = runner->right;
  }
  return 0;
}


//check underneath main
void main ()
{
  struct node *root = NULL;

  insert_binary_search_tree (&root, 15);
  insert_binary_search_tree (&root, 25);
  insert_binary_search_tree (&root, 30);
  insert_binary_search_tree (&root, 20);
  insert_binary_search_tree (&root, 35);
  insert_binary_search_tree (&root, 40);
  insert_binary_search_tree (&root, 1);
  insert_binary_search_tree (&root, 0);
  insert_binary_search_tree (&root, 10);
  insert_binary_search_tree (&root, 12);
  insert_binary_search_tree (&root, 14);
  insert_binary_search_tree (&root, 11);


  level_order (root);
  printf ("\n");
}


/*

https://leetcode.com/problems/binary-tree-level-order-traversal/

This requires keeping track of level along with DFS.


int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
  struct TreeNode* queue[2500];
  int level_queue[2500] = {0};
  int q_start = 0, q_end = 0;
  int num_levels = 0;
  int **res = (int **) malloc (2000 * sizeof (*res));
  struct TreeNode* curr;
  int curr_level;
  int *tmp_arr = (int *) malloc (1000 * sizeof (*tmp_arr));
  int *col_len = (int *) malloc (1000 * sizeof (*col_len));
  int tmp_arr_len = 0;
  int prev_level;
  
  if (!root) {
    *returnSize = 0;
    return res;
  }
  
  queue[q_end] = root;
  level_queue[q_end] = 1;
  q_end++;
  prev_level = 1;
  while (q_end > q_start) {
    curr = queue[q_start];
    curr_level = level_queue[q_start];
    q_start++;
    if (curr_level != prev_level) {
      res[prev_level - 1] = (int *) malloc (tmp_arr_len * sizeof (int));
      memcpy (res[prev_level - 1], tmp_arr, tmp_arr_len * sizeof (int));
      col_len[prev_level - 1] = tmp_arr_len;
      prev_level = curr_level;
      tmp_arr_len = 0;
    }
    tmp_arr[tmp_arr_len++] = curr->val;
    
    if (curr->left) {
      queue[q_end] = curr->left;
      level_queue[q_end] = curr_level + 1;
      q_end++;
    }
    if (curr->right) {
      queue[q_end] = curr->right;
      level_queue[q_end] = curr_level + 1;
      q_end++;
    }
  }
  
  if (tmp_arr_len > 0) {
    res[curr_level - 1] = (int *) malloc (tmp_arr_len * sizeof (int));
    memcpy (res[curr_level - 1], tmp_arr, tmp_arr_len * sizeof (int));
    col_len[curr_level - 1] = tmp_arr_len;    
  }
  
  *returnSize = curr_level;
  *returnColumnSizes = (int *) malloc (curr_level * sizeof (int));
  for (int i = 0; i < curr_level; i++) {
    (*returnColumnSizes)[i] = col_len[i];
  }
  return res;
}

*/

