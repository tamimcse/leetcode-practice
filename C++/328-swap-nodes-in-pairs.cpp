/*
https://leetcode.com/problems/swap-nodes-in-pairs/
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *r1 = head, *r2 = head->next;

        ListNode *r3 = swapPairs (r2->next);
        r2->next = r1;
        r1->next = r3;
        return r2;
    }
};
