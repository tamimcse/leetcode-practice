/*
https://leetcode.com/problems/partition-list/
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *r = head, *first, *r1;
        ListNode second;
        ListNode *second_runner = &second;
        while (head && head->val >= x) {
            second_runner->next = head;
            head = head->next;
            second_runner = second_runner->next;
            second_runner->next = NULL;
        }
        
        if (!head) {
            return second.next;
        }
        
        first = head;
        r = head;
        while (r->next) {
            if (r->next->val >= x) {
                second_runner->next = r->next;
                second_runner = second_runner->next;
                r->next = r->next->next;
                second_runner->next = NULL;
            } else {
                r = r->next;    
            }
        }
        r->next = second.next;
        return first;
    }
};
