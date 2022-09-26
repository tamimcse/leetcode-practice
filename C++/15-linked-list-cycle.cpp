/*
https://leetcode.com/problems/linked-list-cycle/
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *r1 = head, *r2 = head;
        if (head == nullptr)
            return false;
        do {
            r1 = r1->next;
            r2 = r2->next;
            if (r2)
                r2 = r2->next;
            else
                return false;
            if (r1 == r2)
                return true;
        } while (r1 && r2);
        return false;
    }
};
