/*
https://leetcode.com/problems/max-points-on-a-line/
*/
#define CAPACITY 100

struct elem {
  int dx;
  int dy;
  int count;
  struct elem *next;
};

int bucket_no (int dx, int dy)
{
  return (abs (dx) * abs (dy)) % CAPACITY;  
}

struct elem* find (struct elem **hash, int dx, int dy) 
{
  struct elem *runner;
  int bucket = bucket_no (dx, dy);
  
  bool sign = (dx > 0 && dy > 0) || (dx < 0 && dy < 0);
  bool runner_sign;
  
  runner = hash[bucket];
  while (runner) {
    runner_sign = (runner->dx > 0 && runner->dy > 0) ||
      (runner->dx < 0 && runner->dy < 0);
    if (!dy && !(runner->dy))
      return runner;
    if (!dx && !(runner->dx))
      return runner;
    if (abs (runner->dx) == abs (dx) && 
        abs (runner->dy) == abs (dy) &&
        sign == runner_sign)
      return runner;
    runner = runner->next;
  }
  return NULL;
}

void insert (struct elem **hash, int dx, int dy) 
{
  struct elem *new_node = (struct elem *) malloc (sizeof (*new_node));
  int bucket = bucket_no (dx, dy);
  
  new_node->dx = dx;
  new_node->dy = dy;
  new_node->count = 2;
  new_node->next = hash[bucket];
  hash[bucket] = new_node;
}

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

int maxPoints(int** points, int pointsSize, int* pointsColSize){
  struct elem* ret;
  int i, j, k, max = 0;
  int dx, dy, div;
  
  if (pointsSize <= 2)
    return pointsSize;
  
  for (i = 0; i < pointsSize; i++) {
    struct elem *hash[CAPACITY] = {NULL};
    for (j = i + 1; j < pointsSize; j++) {
      dx = points[j][0] - points[i][0];
      dy = points[j][1] - points[i][1];
      if (dx && dy) {
        div = gcd (abs (dx), abs (dy));
        dx = dx / div;
        dy = dy / div; 
      }
      ret = find (hash, dx, dy);
      if (ret) {
        ret->count++;
      if (ret->count > max)
        max = ret->count;
      } else {
        insert (hash, dx, dy);
        if (max < 2)
          max = 2;
      }
    }
  }
  return max;
}
