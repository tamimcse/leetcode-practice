/*
https://leetcode.com/problems/linked-list-cycle/
*/
//Use hashtable instead of stack. Also note that it is not very easy to hash a pointer. So, use slow and fast pointer approach instead
bool hasCycle(struct ListNode *head) {
  struct ListNode *stack[10000] = {0};
  int idx = 0, i;
  
  while (head) {
    for (i = 0; i < idx; i++) {
      if (stack[i] == head)
        return true;
    }
    stack[idx++] = head;
    head = head->next;
  }
  return false;
}
