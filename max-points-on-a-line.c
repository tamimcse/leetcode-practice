/*
https://leetcode.com/problems/max-points-on-a-line/
*/
struct value {
  int val;
  struct value *next;
};

//check if val exist, if not insert it
struct value* insert_value (struct value *head, int val)
{
  struct value *new_val;
  struct value *runner;

  if (!head) {
    new_val = (struct value *) malloc (sizeof (*new_val));
    new_val->val = val;
    new_val->next = NULL;
    return new_val;
  }
  
  runner = head;
  while (runner) {
    //already exist
    if (runner->val == val)
      return head;
    if (runner->next) {
      runner = runner->next;
    } else {
      new_val = (struct value *) malloc (sizeof (*new_val));
      new_val->val = val;
      new_val->next = NULL;
      runner->next = new_val;
      return head;
    }
  }
  return head;
}

struct key_value {
  int x1;
  int x2;
  int y1;
  int y2;
  struct value *list_head;
};

int gcd (int a, int b)
{
  int tmp, devisor, devident;
  
  if (b < a) {
    tmp = a;
    a = b;
    b = tmp;
  }
  
  devident = b;
  devisor = a;
  while (devident % devisor) {
    tmp = devisor;
    devisor = devident % devisor;
    devident = tmp;
  }
  return devisor;
}

void inorder (struct key_value *root, int *max)
{
  int count = 0;
  struct value *runner;
  
  if (!root)
    return;
  runner = root->head;
  while (runner) {
    count++;
    runner = runner->next;
  }
  if (count > *max)
    *max = count;
  inorder (root->left, max);
  inorder (root->right, max);
}

int maxPoints(int** points, int pointsSize, int* pointsColSize){
  struct key_value *ret;
  int i, j, k, max = 0;
  int dx, dy, div;
  struct value *val;
  struct key_value vec[2000];
  int vec_cnt = 0;
  
  for (i = 0; i < pointsSize; i++) {
    for (j = i + 1; j < pointsSize; j++) {
      dx = points[j][0] - points[i][0];
      dy = points[j][1] - points[i][1];
      div = gcd (dx, dy);
      dx = dx / div;
      dy = dy / div;
      ret = find (root, dx, dy);
      if (ret) {
        ret->head = insert_value (ret->head, i);
        ret->head = insert_value (ret->head, j);
      } else {
        root = tree_insert (root, dx, dy, i, j);
      }
    }
  }
  
  inorder (root, &max);
  return max;
}
