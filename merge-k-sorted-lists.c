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
