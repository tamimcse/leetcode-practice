/*
https://leetcode.com/problems/sort-list/

Very very interesting problem!!!!!
*/
class Solution {
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *head, *r;
        
        if (l1->val <= l2->val) {
            head = l1;
            r = head;
            l1 = l1->next;
        } else {
            head = l2;
            r = head;
            l2 = l2->next;
        }
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                r->next = l1;
                l1 = l1->next;
            } else {
                r->next = l2;
                l2 = l2->next;
            }
            r = r->next;
        }
        
        if (l1) {
            r->next = l1;
        }
        
        if (l2) {
            r->next = l2;
        }
        
        return head;
    }
public:
    ListNode* sortList(ListNode* head) {
        ListNode *fast = head, *slow = head;
        ListNode *l1, *l2;
        
        if (!head)
            return NULL;
        
        if (head->next == NULL)
            return head;
        
        if (head->next && head->next->next == NULL) {
            if (head->next->val < head->val) {
                head->next->next = head;
                head = head->next;
                head->next->next = NULL;
            }
            return head;
        }
        
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *tmp = slow->next;
        slow->next = NULL;
        l1 = sortList (tmp);
        l2 = sortList(head);
        return merge (l1, l2);
    }
};
