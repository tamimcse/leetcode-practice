/*
https://leetcode.com/problems/different-ways-to-add-parentheses/

Use recursion to find all possible cases.
*/
int expr (char op, int operand1, int operand2)
{
  switch (op) {
    case '+':
      return operand1 + operand2;
    case '*':
      return operand1 * operand2;
    case '-':
      return operand1 - operand2;
  }
  return 0;
}

int* diffWaysToCompute_inner(char * expression, int len, int* returnSize)
{
  int i, j, k;
  int *left, *right;
  int left_size, right_size;
  int *res = (int *) malloc (10000 * sizeof (*res));
  int res_cnt = 0;
  
  bool is_digit = true;
  for (int m = 0; m < len; m++) {
    if (!isdigit(expression[m])) {
      is_digit = false;
      break;
    }
  }
  if (is_digit) {
    res[0] = atoi (expression);
    *returnSize = 1;
    return res;    
  }
  
  for (i = 0; i < len; i++) {
    if (!isdigit(expression[i])) {
      left = diffWaysToCompute_inner (expression, i, &left_size);
      right = diffWaysToCompute_inner (expression + i + 1, len - i - 1, &right_size);
      for (j = 0; j < left_size; j++) {
        for (k = 0; k < right_size; k++) {
          res[res_cnt++] = expr (expression[i], left[j], right[k]);
        }
      }
    }    
  }
  *returnSize = res_cnt;
  return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diffWaysToCompute(char * expression, int* returnSize){
  int i, j, k;
  int *left, *right;
  int left_size, right_size;
  int len = strlen (expression);
  int *res = (int *) malloc (10000 * sizeof (*res));
  int res_cnt = 0;
  
  bool is_digit = true;
  for (int m = 0; expression[m]; m++) {
    if (!isdigit(expression[m])) {
      is_digit = false;
      break;
    }
  }
  if (is_digit) {
    res[0] = atoi (expression);
    *returnSize = 1;
    return res;    
  }
  
  for (i = 0; expression[i]; i++) {
    if (!isdigit(expression[i])) {
      left = diffWaysToCompute_inner (expression, i, &left_size);
      right = diffWaysToCompute_inner (expression + i + 1, len - i - 1, &right_size);
      for (j = 0; j < left_size; j++) {
        for (k = 0; k < right_size; k++) {
          res[res_cnt++] = expr (expression[i], left[j], right[k]);
        }
      }
    }
  }
  *returnSize = res_cnt;
  return res;
}
