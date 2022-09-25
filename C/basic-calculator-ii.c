/*
https://leetcode.com/problems/basic-calculator-ii/

It is tempting to solve this problem using recursion like reg-ex matching. But, if you look carefully, recursion will not work.
*/
int extract_num (char *s, int *idx)
{
  int num;
  
  while (!isdigit(s[*idx]))
    (*idx)++;
  num = 0;
  while (isdigit(s[*idx])) {
    num = num * 10 + (s[*idx] - '0');
    (*idx)++;
  }
  return num;
}

int calculate(char * s){
  int operand_stack [200000];
  char operator_stack [100000];
  int operand_stack_idx = 0, operator_stack_idx = 0, i, j, num;
  int op1, op2, res;
  char operator;
  
  i = 0;
  operand_stack[operand_stack_idx++] = extract_num (s, &i);
  while (s[i]) {
    if (s[i] == ' ') {
      i++;
      continue;
    }
    if (s[i] == '+' || s[i] == '-') {
      operator_stack[operator_stack_idx++] = s[i++];
      operand_stack[operand_stack_idx++] = extract_num (s, &i);
      continue;
    }
    if (s[i] == '*' || s[i] == '/') {
      operator = s[i];
      op1 = operand_stack[--operand_stack_idx];
      op2 = extract_num (s, &i);
      res = operator == '*' ? op1 * op2 : op1 / op2;
      operand_stack[operand_stack_idx++] = res;
    }
  }
  
  if (!operator_stack_idx)
    return operand_stack[--operand_stack_idx];

  //Now treat the stack like a queue
  int operator_queue_start = 0, operator_queue_end = operator_stack_idx;
  int operand_queue_start = 0, operand_queue_end = operand_stack_idx;
  while (operator_queue_end > operator_queue_start) {
    operator = operator_stack[operator_queue_start++];
    op1 = operand_stack[operand_queue_start++];
    op2 = operand_stack[operand_queue_start++];
    res = operator == '+' ? op1 + op2 : op1 - op2;
    operand_stack[--operand_queue_start] = res;
  }
  return operand_stack[operand_queue_start];
}
