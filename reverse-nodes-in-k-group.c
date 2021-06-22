/*
https://leetcode.com/problems/reverse-nodes-in-k-group/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k){
  struct ListNode *runner1 = head, *runner2, *new_head = NULL, *new_tail = NULL, *runner3, *prev = NULL;
  int i, j;
  bool end = false;
  bool head_set = false;
  
  while (1) {
    runner2 = runner1;
    for (i = 0; i < k; i++) {
      if (!runner2) {
        end = true;
        if (prev)
          prev->next = runner1;
        break;
      }
      runner2 = runner2->next;
    }
    if (end)
      break;
    //Reverse nodes from runner1 to runner2
    new_tail = runner1;
    runner2 = runner1->next;
    for (i = 0; i < k - 1; i++) {
      runner3 = runner2->next;
      runner2->next = runner1;
      runner1 = runner2;
      runner2 = runner3;
    }
    if (!head_set) {
      new_head = runner1; 
      head_set = true;
    }
    if (prev) {
      prev->next = runner1;
    }
    runner1 = runner2;
    prev = new_tail;
  }
  return new_head;
}
