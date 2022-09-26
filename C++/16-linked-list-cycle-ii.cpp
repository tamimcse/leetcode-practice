/*
https://leetcode.com/problems/linked-list-cycle-ii/
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *r1 = head, *r2 = head;
        if (head == nullptr)
            return nullptr;
        do {
            r1 = r1->next;
            r2 = r2->next;
            if (r2)
                r2 = r2->next;
            else
                return nullptr;
            if (r1 == r2) {
                r1 = head;
                while (true) {
                    if (r1 == r2) {
                        return r1;
                    } else {
                        r1 = r1->next;
                        r2 = r2->next;
                    }
                }
            }
        } while (r1 && r2);
        return nullptr;
    }
};
