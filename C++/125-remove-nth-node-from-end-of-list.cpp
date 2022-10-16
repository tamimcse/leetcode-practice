/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Implement both in  one pass and two pass.
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode *r = head;
        
        while (r) {
            count++;
            r = r->next;
        }
        
        if (n > count)
            return head;
        
        if (n == count)
            return head->next;
        
        r = head;
        for (int i = 0; i < count - n - 1; i++) {
            r = r->next;
        }
        
        r->next = r->next->next;
        return head;
    }
};
