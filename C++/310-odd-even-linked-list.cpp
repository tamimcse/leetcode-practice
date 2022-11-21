/*
https://leetcode.com/problems/odd-even-linked-list/
*/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head)
            return head;
        ListNode *r1 = head, *even_head = head->next, *r2 = even_head;
        
        while (r1) {
            if (r2 == NULL || r2->next == NULL) {
                if (r2)
                    r2->next = NULL;
                r1->next = even_head;
                break;                
            }
            r1->next = r2->next;
            r1 = r1->next;
            r2->next = r1->next;
            r2 = r2->next;
        }
        return head;
    }
};
