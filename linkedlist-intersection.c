/*
https://leetcode.com/problems/intersection-of-two-linked-lists/

May look trivial, but it is not. 

https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/

Folow method 3
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
  struct ListNode *r1, *r2;
  struct ListNode *bg_list, *sm_list;
  int count1 = 0, count2 = 0, diff;
  
  r1 = headA;
  while (r1) {
    count1++;
    r1 = r1->next;
  }
  
  r2 = headB;
  while (r2) {
    count2++;
    r2 = r2->next;
  }
  
  if (count1 >= count2) {
    diff = count1 - count2;
    bg_list = headA;
    sm_list = headB;
  } else {
    bg_list = headB;
    sm_list = headA;
    diff = count2 - count1;
  }
  
  while (diff) {
    diff--;
    bg_list = bg_list->next;
  }
  
  while (bg_list) {
    if (bg_list == sm_list)
      return bg_list;
    bg_list = bg_list->next;
    sm_list = sm_list->next;
  }
  return NULL;
}
