/*
https://leetcode.com/problems/reverse-linked-list/

Solve both ways
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *r1 = head, *r2 = head->next, *tmp;
        
        while (r2) {
            tmp = r2->next;
            r2->next = r1;
            r1 = r2;
            r2 = tmp;
        }
        head->next = nullptr;
        return r1;   
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *last = head->next, *new_head;
        new_head = reverseList (last);
        last->next = head;
        head->next = NULL;
        return new_head;
    }
};
