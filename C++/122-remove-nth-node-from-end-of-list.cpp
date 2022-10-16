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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode *r1 = head, *r2 = head;
        
        for (int i = 0; i < n; i++) {
            if (r2)
                r2 = r2->next;
        }
        
        if (!r2)
            return head->next;
        while (r2->next) {
            r1 = r1->next;
            r2 = r2->next;
        }
        
        r1->next = r1->next->next;
        return head;
    }
};
