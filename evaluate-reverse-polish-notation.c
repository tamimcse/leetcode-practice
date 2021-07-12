/*
https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/
int eval (int op1, int op2, char op)
{
  switch (op) {
    case '+':
      return op1 + op2;
    case '-':
      return op1 - op2;
    case '*':
      return op1 * op2;
    case '/':
      return op1 / op2;
  }
  return 0;
}

bool is_operator (char *s)
{
  return s[0] == '+' || (s[0] == '-' && !s[1]) || s[0] == '/' || s[0] == '*';
}

int evalRPN(char ** tokens, int tokensSize){
  int i, j, k;
  int stack[20000];
  int s_idx = 0;
  int op1, op2, res;
  
  for (i = 0; i < tokensSize; i++) {
    if (is_operator(tokens[i])) {
      op1 = stack[--s_idx];
      op2 = stack[--s_idx];
      res = eval (op2, op1, tokens[i][0]);
      stack[s_idx++] = res;
    } else {
      stack[s_idx++] = atoi (tokens[i]);
    }
  }
  return stack[0];
}
