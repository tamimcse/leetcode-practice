/*
https://leetcode.com/problems/merge-two-sorted-lists/
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *r1 = list1, *r2 = list2, *head = list1, *tmp = nullptr;
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        head = list2->val <= list1->val ? list2 : list1;
        while (r2 && r2->val <= r1->val) {
            tmp =r2;
            r2 = r2->next;
        }
        if (tmp)
            tmp->next = r1;
        while (r1 && r2) {
            if (r1->next == nullptr) {
                r1->next = r2;
                return head;
            } else if (r1->next->val >= r2->val) {
                tmp = r2->next;
                r2->next = r1->next;
                r1->next = r2;
                r1 = r2;
                r2 = tmp;
            } else {
                r1 = r1->next;
            }
        }

        return head;
    }
};
