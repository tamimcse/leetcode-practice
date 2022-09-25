/*
https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

Input:
        3
      /   \
     2     1
Output:
3 1 2

Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10 
*/
#include <stdio.h>
#include <stdlib.h>

enum direction {ZIG, ZAG};

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

#define STACK_SIZE 100

int level_order (struct node *root)
{
  struct node *runner;
  struct node *stack1[STACK_SIZE] = {0};
  struct node *stack2[STACK_SIZE] = {0};
  int count1 = 0;//index to stack1
  int count2 = 0;//index to stack2

  if (!root)
    return 0;

  //push root to stack
  stack1[count1++] = root;

  //both stack is not empty
  while (count1 > 0 || count2 > 0) {
    while (count1 > 0) {
      //pop
      runner = stack1[--count1];
      printf ("%d ", runner->data);
      //Stack is full
      if (count1 >= STACK_SIZE) {
        printf ("Stack1 is full. Please increase the stack size\n");
        return 1;
      }
      if (runner->left) {
        stack2[count2++] = runner->left;
      }
      if (runner->right) {
        stack2[count2++] = runner->right;
      }
    }
    while (count2 > 0) {
      //pop
      runner = stack2[--count2];
      printf ("%d ", runner->data);
      //Stack is full
      if (count2 >= STACK_SIZE) {
        printf ("Stack2 is full. Please increase the stack size\n");
        return 1;
      }
      if (runner->right) {
        stack1[count1++] = runner->right;
      }
      if (runner->left) {
        stack1[count1++] = runner->left;
      }
    }
  }
  return 0;
}

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
