/*
https://leetcode.com/problems/remove-linked-list-elements/
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val)
            head = head->next;
        
        ListNode *r = head;
        while (r && r->next) {
            if (r->next->val == val)
                r->next = r->next->next;
            else
                r = r->next;
        }
        return head;
    }
};
