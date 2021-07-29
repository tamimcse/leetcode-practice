/*
https://leetcode.com/problems/find-median-from-data-stream/
*/
#define HEAP_SIZE 50001

enum HeapType {MIN, MAX};

void push_up (int *arr, int len, int child_idx, enum HeapType t)
{
  if (!child_idx)
    return;
  int parent_idx = (child_idx - 1) >> 1;
  
  int left_idx = (parent_idx << 1) + 1, right_idx = (parent_idx << 1) + 2;
  int max_child_idx = -1;
  int tmp;
  
  if (left_idx < len)
    max_child_idx = left_idx;
  
  if (right_idx < len &&
      ((t == MAX && arr[right_idx] > arr[max_child_idx]) ||
       (t == MIN && arr[right_idx] < arr[max_child_idx]))) {
    max_child_idx = right_idx;
  }
  
  if (max_child_idx >=0 &&
      ((t == MAX && arr[max_child_idx] > arr[parent_idx]) ||
       (t == MIN && arr[max_child_idx] < arr[parent_idx]))) {
    tmp = arr[parent_idx];
    arr[parent_idx] = arr[max_child_idx];
    arr[max_child_idx] = tmp;
    push_up (arr, len, parent_idx, t);
  }
}


void push_down (int *arr, int len, int parent_idx, enum HeapType t)
{
  int left_idx = (parent_idx << 1) + 1, right_idx = (parent_idx << 1) + 2;
  int max_child_idx = -1;
  int tmp;
  
  if (left_idx < len) {
    max_child_idx = left_idx;
  }
    
  if (right_idx < len &&
      ((t == MAX && arr[right_idx] > arr[max_child_idx]) ||
       (t == MIN && arr[right_idx] < arr[max_child_idx]))) {
    max_child_idx = right_idx;
  }
  if (max_child_idx >=0 &&
      ((t == MAX && arr[max_child_idx] > arr[parent_idx]) ||
      (t == MIN && arr[max_child_idx] < arr[parent_idx]))) {
    tmp = arr[parent_idx];
    arr[parent_idx] = arr[max_child_idx];
    arr[max_child_idx] = tmp;
    push_down (arr, len, max_child_idx, t);
  }
}

void heap_add (int *arr, int to_add, int *len, enum HeapType t)
{
  if (*len == HEAP_SIZE)
    return;
  arr[*len] = to_add;
  (*len)++;
  push_up (arr, *len, *len - 1, t);
}

void heap_pop_root (int *arr, int *len, enum HeapType t)
{
  arr[0] = arr[*len - 1];
  (*len)--;
  push_down (arr, *len, 0, t);
}

typedef struct {
  int *max_heap;
  int *min_heap;
  int max_heap_cnt;
  int min_heap_cnt;
  int last_inserted;
} MedianFinder;

/** initialize your data structure here. */

MedianFinder* medianFinderCreate() {
  MedianFinder *obj = (MedianFinder *) calloc (1, sizeof (*obj));
  obj->max_heap = (int *) malloc (HEAP_SIZE * sizeof (int));
  obj->min_heap = (int *) malloc (HEAP_SIZE * sizeof (int));
  return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
  if (!(obj->max_heap_cnt) && !(obj->min_heap_cnt)) {
    obj->min_heap[0] = num;
    obj->min_heap_cnt++;
    return;
  }
  
  if (obj->max_heap_cnt == obj->min_heap_cnt) {
    if (num >= obj->min_heap[0]) {
      heap_add (obj->min_heap, num, &(obj->min_heap_cnt), MIN);
    } else {
      heap_add (obj->max_heap, num, &(obj->max_heap_cnt), MAX);
    }
  } else {
    if (obj->max_heap_cnt < obj->min_heap_cnt) {
      if (num < obj->min_heap[0]) {
        heap_add (obj->max_heap, num, &(obj->max_heap_cnt), MAX);
      } else {
        heap_add (obj->max_heap, obj->min_heap[0], &(obj->max_heap_cnt), MAX);
        heap_pop_root (obj->min_heap, &(obj->min_heap_cnt), MIN);
        heap_add (obj->min_heap, num, &(obj->min_heap_cnt), MIN);
      }
    } else {
      if (num > obj->max_heap[0]) {
        heap_add (obj->min_heap, num, &(obj->min_heap_cnt), MIN);
      } else {
        heap_add (obj->min_heap, obj->max_heap[0], &(obj->min_heap_cnt), MIN);
        heap_pop_root (obj->max_heap, &(obj->max_heap_cnt), MAX);
        heap_add (obj->max_heap, num, &(obj->max_heap_cnt), MAX);
      }
    }
  }
}

double medianFinderFindMedian(MedianFinder* obj) {
  if (!(obj->max_heap_cnt) && !(obj->min_heap_cnt))
    return 0;
  if (obj->max_heap_cnt == obj->min_heap_cnt) {
    return ((double)obj->max_heap[0] + (double)obj->min_heap[0])/2.0;
  } else {
    return obj->max_heap_cnt > obj->min_heap_cnt ?
      obj->max_heap[0] : obj->min_heap[0];
  }
}

void medianFinderFree(MedianFinder* obj) {
  free (obj->max_heap);
  free (obj->min_heap);
  free (obj);
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 
 * double param_2 = medianFinderFindMedian(obj);
 
 * medianFinderFree(obj);
*/
