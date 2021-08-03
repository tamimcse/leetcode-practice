/*
https://leetcode.com/problems/task-scheduler/

Very interesting problem!!
*/

int hash[26] = {0};

void push_up (int *heap, int heap_len, int child_idx)
{
  if (!child_idx)
    return;
  int parent_idx = (child_idx - 1) >> 1;
  int left_idx = (parent_idx << 1) + 1, right_idx = (parent_idx << 1) + 2;
  int largest_child_idx = -1;
  int tmp;
  
  if (left_idx < heap_len)
    largest_child_idx = left_idx;
  
  if (right_idx < heap_len && hash[heap[left_idx]] < hash[heap[right_idx]])
    largest_child_idx = right_idx;
  
  if (largest_child_idx >= 0 &&
      hash[heap[parent_idx]] < hash[heap[largest_child_idx]]) {
    tmp = heap[parent_idx];
    heap[parent_idx] = heap[largest_child_idx];
    heap[largest_child_idx] = tmp;
    push_up (heap, heap_len, parent_idx);
  }
}

void push_down (int *heap, int heap_len, int parent_idx)
{
  int left_idx = (parent_idx << 1) + 1, right_idx = (parent_idx << 1) + 2;
  int largest_child_idx = -1;
  int tmp;
  
  if (left_idx < heap_len)
    largest_child_idx = left_idx;
  
  if (right_idx < heap_len && hash[heap[left_idx]] < hash[heap[right_idx]])
    largest_child_idx = right_idx;
  
  if (largest_child_idx >= 0 &&
      hash[heap[parent_idx]] < hash[heap[largest_child_idx]]) {
    tmp = heap[parent_idx];
    heap[parent_idx] = heap[largest_child_idx];
    heap[largest_child_idx] = tmp;
    push_down (heap, heap_len, largest_child_idx);
  }
}

void insert (int *heap, int *heap_len, int to_add)
{
  heap[*heap_len] = to_add;
  (*heap_len)++;
  push_up (heap, *heap_len, *heap_len - 1);
}

void delete (int *heap, int *heap_len)
{
  if (!(*heap_len))
    return;
  heap[0] = heap[*heap_len - 1];
  (*heap_len)--;
  push_down (heap, *heap_len, 0);
}

int leastInterval(char* tasks, int tasksSize, int n){
  if (!n)
    return tasksSize;  
  
  int indices[26];
  int indices_len = 0;
  int i, j, k;
  char *sched = (char *) calloc (100000, sizeof (*sched));
  int start_idx, cur_idx, count = 0, max_idx;
  
  memset (hash, 0, 26 * sizeof (int));
  
  for (i = 0; i < tasksSize; i++) {
    hash[tasks[i] - 'A']++;
  }
  
  for (i = 0; i < 26; i++) {
    insert (indices, &indices_len, i);
  }
  
  max_idx = 0;
  while (count < tasksSize) {
    cur_idx = indices[0];
    if (hash[cur_idx]) {
      hash[cur_idx]--;
      count++;
      sched[max_idx++] = cur_idx;
      delete (indices, &indices_len);
    } else {
      sched[max_idx++] = -1;
    }
    
    if (max_idx > n) {
      if (sched[max_idx - n - 1] != -1 && hash[sched[max_idx - n - 1]])
        insert (indices, &indices_len, sched[max_idx - n - 1]);
    }
  }
  return max_idx;
}
