/*
https://leetcode.com/problems/reverse-nodes-in-k-group/

Implemement using O(1) space, although think how would you implement if you can use extra space.
*/
class Solution {
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *r1 = head, *r2 = head->next, *new_head;
        new_head = reverse(r2);
        r2->next = r1;
        r1->next = NULL;
        return new_head;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *r = head, *end;

        for (int i = 0; i < k; i++) {
            if (!r)
                return head;
            if (i == k - 1)
                end = r;    
            r = r->next;
        }
        if (r == NULL) {
            return reverse (head);
        }
        ListNode *ret1 = reverseKGroup(r, k);
        end->next = NULL;
        ListNode *ret2 = reverse (head);
        head->next = ret1;
        return ret2;
    }
};
