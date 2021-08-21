/*
https://leetcode.com/problems/moving-average-from-data-stream/
*/

typedef struct {
  int *arr;
  int size;
  int count;
  double sum;
  int idx;
} MovingAverage;

/** Initialize your data structure here. */

MovingAverage* movingAverageCreate(int size) {
  MovingAverage *m = (MovingAverage *) malloc (sizeof (*m));
  m->size = size;
  m->count = 0;
  m->sum = 0;
  m->idx = 0;
  m->arr = (int *) calloc (size, sizeof (int));
  return m;
}

double movingAverageNext(MovingAverage* obj, int val) {
  if (obj->count < obj->size) {
    obj->arr[obj->count++] = val;
    obj->sum += val;
  } else {
    obj->sum = obj->sum - obj->arr[obj->idx % obj->size] + val;
    obj->arr[obj->idx % obj->size] = val;
  }
  obj->idx++;
  return obj->sum / obj->count;
}

void movingAverageFree(MovingAverage* obj) {
  free (obj->arr);
  free (obj);
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);
 
 * movingAverageFree(obj);
*/
