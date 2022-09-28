/*
https://leetcode.com/problems/middle-of-the-linked-list/
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *r1 = head, *r2 = head;
        
        while (r2 != nullptr && r2->next) {
            r1 = r1->next;
            r2 = r2->next;
            if (r2)
                r2 = r2->next;
        }
        return r1;
    }
};
