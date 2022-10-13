/*
https://leetcode.com/problems/rotate-list/
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 0;
        ListNode *r = head;
        while (r) {
            count++;
            r = r->next;
        }
        if (!count)
            return head;
        
        k = k % count;
        
        if (!k)
            return head;
        
        r = head;
        for (int i = 0; i < count - k - 1; i++) {
            r = r->next;
        }
        
        ListNode *new_head = r->next;
        r->next = NULL;
        r = new_head;
        while (r->next) {
            r = r->next;
        }
        r->next = head;
        return new_head;
    }
};
