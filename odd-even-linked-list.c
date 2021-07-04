/*
https://leetcode.com/problems/odd-even-linked-list/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
  if (!head || !(head->next))
    return head;
  
  struct ListNode *odd_head = head, *even_head = head->next;
  struct ListNode *odd_runner = odd_head, *even_runner = even_head;
  bool odd_turn = true;
  
  while (odd_runner->next && even_runner->next) {
    if (odd_turn) {
      odd_runner->next = even_runner->next;
      odd_runner = odd_runner->next;
    } else {
      even_runner->next = odd_runner->next;
      even_runner = even_runner->next; 
    }
    odd_turn = !odd_turn;
  }
  if (odd_runner->next) {
    odd_runner->next = even_head;
    return odd_head;
  } else {
    even_runner->next = NULL;
    odd_runner->next = even_head;
    return odd_head;
  }
}
