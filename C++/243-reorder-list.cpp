/*
https://leetcode.com/problems/reorder-list/
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *r = head, *r1, *tmp;
        
        while (r) {
            //find tail and add it to current node
            r1 = r;
            while (r1->next && r1->next->next != NULL) {
                r1 = r1->next;
            }
            
            if (r == r1 && r1->next != NULL)
                return;
            if (r1->next) {
                tmp = r->next;
                r->next = r1->next;
                r = tmp;
                r1->next->next = r;
                r1->next = NULL;
            } else {
                r = r->next;
            }
        }
    }
};
