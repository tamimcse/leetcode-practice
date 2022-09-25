/*
https://www.geeksforgeeks.org/expression-tree/
*/
#include <stdio.h>

struct node {
  int operand;
  char operator;
  struct node *left;
  struct node *right;
};

int expression (struct node *r)
{
  if (r->operator == '\0')
    return r->operand;
  int left = expression (r->left);
  int right = expression (r->right);
  switch (r->operator) {   
    case '+':
      return left + right;
    case '*':
      return left * right;
    default:
      return 0;
  }
}

void main ()
{
  struct node op1, op2, op3, n2, n3, n5, n9;
  op1 = (struct node) {0, '+', &n3, &op2};
  op2 = (struct node) {0, '*', &op3, &n2};
  op3 = (struct node) {0, '+', &n5, &n9};
  n2 = (struct node) {2, '\0', NULL, NULL};
  n3 = (struct node) {3, '\0', NULL, NULL};
  n5 = (struct node) {5, '\0', NULL, NULL};
  n9 = (struct node) {9, '\0', NULL, NULL};

  int res = expression (&op1);
  printf ("Result is %d \n", res);
}
