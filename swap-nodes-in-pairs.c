/*
https://leetcode.com/problems/swap-nodes-in-pairs/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head){
  struct ListNode *r1, *r2, *r1_nxt, *r2_nxt, *prev = NULL, *new_head = NULL;
  
  if (!head || !(head->next))
    return head;
  r1 = head;
  r2 = head->next;
  while (r1 && r2) {
    r1_nxt = r2->next;
    r2_nxt = r1_nxt ? r1_nxt->next : NULL;
    r2->next = r1;
    if (!new_head)
      new_head = r2;
    if (prev)
      prev->next = r2;
    prev = r1;
    r1 = r1_nxt;
    r2 = r2_nxt;
  }
  if (prev && r1) {
    prev->next = r1;
    prev = r1;
  }
  if (prev)
    prev->next = NULL;
  return new_head;
}
