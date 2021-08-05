/*
https://leetcode.com/problems/sort-list/

Very very interesting problem!!!!!

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* get_mid (struct ListNode *head)
{
  struct ListNode *slow = head, *fast = head->next, *mid;
  
  while (fast->next) {
    slow = slow->next;
    fast = fast->next;
    if (fast->next != NULL)
      fast = fast->next;
  }
  mid = slow->next;
  slow->next = NULL;
  return mid;
}

struct ListNode* merge(struct ListNode *left, struct ListNode *right)
{
  struct ListNode *head, *runner;
  
  if (left->val <= right->val) {
    head = left;
    left = left->next;
  } else {
    head = right;
    right = right->next;
  }

  runner = head;
  while (left || right) {
    if (!left) {
      runner->next = right;
      return head;
    }
    if (!right) {
      runner->next = left;
      return head;
    }
    if (left->val <= right->val) {
      runner->next = left;
      left = left->next;
      runner = runner->next;
    } else {
      runner->next = right;
      right = right->next;
      runner = runner->next;
    }
  }
  return head;
}

struct ListNode* sortList(struct ListNode* head){
  if (!head || !(head->next))
    return head;
  struct ListNode *mid = get_mid (head), *left, *right;
  
  left = sortList (head); 
  right = sortList (mid);
  return merge (left, right);
}
