/*
https://leetcode.com/problems/linked-list-cycle-ii/
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
  struct ListNode *fast = head, *slow = head, *intersec = NULL;
  
  while (fast && slow) {
    slow = slow->next;
    fast = fast->next;
    if (fast == NULL)
      break;
    fast = fast->next;
    if (slow == fast) {
      intersec = slow;
      break;
    }
  }
  if (!intersec)
    return NULL;
  fast = head;
  slow = intersec;
  while (1) {
    if (fast == slow)
      return fast;
    fast = fast->next;
    slow = slow->next;
  }
}
