/*
https://leetcode.com/problems/merge-k-sorted-lists/

Use min-heap to achieve O (nlogk) solution
*/

#define INF 100000
//O (nk) solution
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
  struct ListNode **runners = (struct ListNode **) malloc (listsSize * sizeof (*runners));
  int i, j;
  struct ListNode *min;
  int min_idx;
  int min_val;
  struct ListNode *res_head = NULL, *res_tail;
  
  if (!listsSize)
    return NULL;
  
  memcpy (runners, lists, listsSize * sizeof (*runners));
  while (1) {
    min_val = INF; 
    for (i = 0; i < listsSize; i++) {
      if (runners[i] != NULL && runners[i]->val < min_val) {
        min_val = runners[i]->val;
        min_idx = i;
      }
    }
    if (min_val == INF)
      break;
    if (!res_head) {
      res_head = runners[min_idx];
      res_tail = runners[min_idx];
      runners[min_idx] = runners[min_idx]->next;
    } else {
      res_tail->next = runners[min_idx];
      res_tail = runners[min_idx];
      runners[min_idx] = runners[min_idx]->next;
    }
  }
  return res_head;
}


//following is heap based version

void bubble_down (struct ListNode **arr, int count, int idx)
{
  int left = (idx << 1) + 1, right = (idx << 1) + 2;
  int smallest_child_idx = -1;
  if (left < count)
    smallest_child_idx = left;
  if (right < count && arr[right]->val < arr[smallest_child_idx]->val)
    smallest_child_idx = right;
  if (smallest_child_idx >= 0 && arr[smallest_child_idx]->val < arr[idx]->val) {
    struct ListNode *tmp = arr[idx];
    arr[idx] = arr[smallest_child_idx];
    arr[smallest_child_idx] = tmp;
    bubble_down (arr, count, smallest_child_idx);
  }
} 

void bubble_up (struct ListNode **arr, int count, int idx)
{
  int parent = (idx - 1) >> 1;
  if (parent >= 0 && arr[parent]->val > arr[idx]->val) {
    struct ListNode *tmp = arr[idx];
    arr[idx] = arr[parent];
    arr[parent] = tmp;
    bubble_up (arr, count, parent);    
  }
}

struct ListNode* heap_get (struct ListNode **arr, int count)
{
  struct ListNode *res = arr[0];
  
  arr[0] = arr[count - 1];
  bubble_down (arr, count - 1, 0);
  return res;
}

void heap_insert (struct ListNode **arr, int count, struct ListNode *to_insert)
{
  arr[count] = to_insert;
  bubble_up (arr, count + 1, count);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){  
  int i, j;
  struct ListNode *min;
  int min_idx;
  int min_val;
  struct ListNode *res_head = NULL, *res_tail;
  struct ListNode **heap = (struct ListNode **) malloc (listsSize * sizeof (*heap));
  int heap_cnt;
  
  if (!listsSize)
    return NULL;
  
  heap_cnt = 0;
  for (i = 0; i < listsSize; i++) {
    if (lists[i]) {
      heap_insert (heap, heap_cnt++, lists[i]);
    }
  }
  while (heap_cnt) {
    struct ListNode * min = heap_get (heap, heap_cnt--);
    if (!res_head) {
      res_head = min;
      res_tail = min;
    } else {
      res_tail->next = min;
      res_tail = min;
    }
    if (min->next) {
      heap_insert (heap, heap_cnt++, min->next);
    }
  }
  return res_head;
}
