/*
https://leetcode.com/problems/top-k-frequent-elements/
*/
#define CAPACITY 1000

struct elem {
  int key;
  int val;
  struct elem *next;
};

struct elem* find (struct elem **hash, int key)
{
  struct elem *runner;
  int bucket = abs (key) % CAPACITY;
  
  runner = hash[bucket];
  while (runner) {
    if (runner->key == key)
      return runner;
    runner = runner->next;
  }
  return NULL;
}

void insert (struct elem **hash, int key, int val)
{
  struct elem *new_elem;
  int bucket = abs (key) % CAPACITY;
  
  new_elem = (struct elem *) malloc (sizeof (*new_elem));
  new_elem->key = key;
  new_elem->val = val;
  new_elem->next = hash[bucket];
  hash[bucket] = new_elem;
}

void push_down (struct elem **heap, int len, int parent_idx)
{
  int left_idx = (parent_idx << 1) + 1, right_idx = (parent_idx << 1) + 2;
  int largest_child_idx = -1;
  struct elem *tmp;
  
  if (left_idx < len)
    largest_child_idx = left_idx;
  if (right_idx < len && heap[right_idx]->val > heap[left_idx]->val)
    largest_child_idx = right_idx;
  if (largest_child_idx >= 0 &&
      heap[largest_child_idx]->val > heap[parent_idx]->val) {
    tmp = heap[parent_idx];
    heap[parent_idx] = heap[largest_child_idx];
    heap[largest_child_idx] = tmp;
    push_down (heap, len, largest_child_idx);
  }
}

void construct_heap (struct elem **heap, int len)
{
  int i, j;
  
  int parent_idx = (len - 2) >> 1;
  
  for (i = parent_idx; i >= 0; i--) {
    push_down (heap, len, i);
  }
}

struct elem* heap_pop_root (struct elem **heap, int *len)
{
  struct elem *ret = heap[0];
  
  heap[0] = heap[*len - 1];
  (*len)--;
  push_down (heap, *len, 0);
  return ret;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
  struct elem *hash[CAPACITY] = {NULL};
  int i, heap_len;
  struct elem *ret;
  struct elem *heap[100000] = {NULL};
  struct elem *runner;
  int *res = (int *) malloc (k * sizeof (int));
  int res_cnt = 0;
  
  for (i = 0; i < numsSize; i++) {
    ret = find (hash, nums[i]);
    if (!ret)
      insert (hash, nums[i], 1);
    else
      ret->val++;
  }

  for (i = 0, heap_len = 0; i < CAPACITY; i++) {
    runner = hash[i];
    while (runner) {
      heap[heap_len++] = runner;
      runner = runner->next;
    }
  }

  construct_heap (heap, heap_len);

  for (i = 0; i < k; i++) {
    res[res_cnt++] = heap_pop_root (heap, &heap_len)->key;
  }
  
  *returnSize = k;
  return res;
}
