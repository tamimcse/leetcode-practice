/*
https://www.geeksforgeeks.org/minimum-maximum-values-expression/
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int eval (int op1, int op2, char op)
{
  switch (op) {
    case '+':
      return op1 + op2;
    case '*':
      return op1 * op2;
  }
}

int max_expression_value (char str[])
{
  int i, j = 0, k, num_operands, res1, res2, row, col, max_res, res, m;
  int len = strlen (str);
  num_operands = (len >> 1) + 1;
  int *nums = (int *)malloc (num_operands * sizeof (*nums));
  char *ops = (char *)malloc ((num_operands - 1) * sizeof (*ops));

  for (i = 0, j = 0; str[i]; i++) {
    if (i & 1)
      ops[j++] = str[i];
    else
      nums[j] = str[i] - '0';
  }

  int *dp_arr = (int *) calloc (num_operands * num_operands, sizeof (*dp_arr));

  for (i = 0; i < num_operands; i++)
    dp_arr[i * num_operands + i] = nums[i];

  for (i = 1; i < num_operands; i++) {
    for (col = i, row = 0; col < num_operands; col++, row++) {
      max_res = 0;
      for (k = row, m = 1; k < col; k++, m++) {
        res = eval (dp_arr[row * num_operands + k], dp_arr[(row + m) * num_operands + col], ops[k]);
        if (res > max_res)
          max_res = res;
      }
      dp_arr[row * num_operands + col] = max_res;
      printf ("(%d, %d) = %d ", row, col, dp_arr[row * num_operands + col]);
    }
    printf ("\n");
  }
  return dp_arr[num_operands - 1];
}

void main ()
{
  char str[] = "2*4+4+5+5*4"; 
//  char str[] = "1+2*3+4*5";
  int res = max_expression_value (str);
  printf ("Maximum value of the expression is %d \n", res);
}
