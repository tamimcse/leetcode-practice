/*
Evaluate an infix expression: 

http://mathcenter.oxford.emory.edu/site/cs171/evaluatingFullyParenthesizedInfixExpressions/
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define STACK_SIZE 20

int operation (int op1, int op2, char operator)
{
  switch (operator) {
    case '+':
      return op1 + op2;
    case '-':
      return op1 - op2;
    case '*':
      return op1 * op2;
    case '/':
      return op1 / op2;
    default:
      return 0;
  }
}

int infix (char *expr, int len)
{
  int i;
  char op_stack[STACK_SIZE];
  int op_stack_idx = 0;
  int opnd_stack[STACK_SIZE];
  int opnd_stack_idx = 0;
  char ch;

  for (i = 0; i < len; i++) {
    ch = expr [i];
    if (isdigit(ch)) {
      opnd_stack[opnd_stack_idx++] = ch - '0';
      //printf ("%d\n", ch - '0');
    } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
      op_stack[op_stack_idx++] = ch;
    } else if (ch == ')') {

      char operator = op_stack[--op_stack_idx];
      int op1 = opnd_stack[--opnd_stack_idx];
      int op2 = opnd_stack[--opnd_stack_idx];
      int res = operation (op1, op2, operator);
      opnd_stack[opnd_stack_idx++] = res;
    }
  }

  while (op_stack_idx > 0) {
    char operator = op_stack[--op_stack_idx];
    int op1 = opnd_stack[--opnd_stack_idx];
    int op2 = opnd_stack[--opnd_stack_idx];
    int res = operation (op1, op2, operator);
    opnd_stack[opnd_stack_idx++] = res;
  }

  return opnd_stack[0];
}

void main ()
{
  char *expr = "(1+((2+3)*(4*5)))";
  int len = strlen (expr);
  int val = infix (expr, len);
  printf ("Output is %d \n", val);
}
