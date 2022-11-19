/*
https://leetcode.com/problems/insertion-sort-list/
*/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *r1 = head, *r2 = head->next, *r, *to_insert;
        
        while (r2) {
            if (r2->val < head->val) {
                to_insert = r2;
                //delete the node
                r1->next = r2->next;
                r2 = r1->next;
                //insert the node
                to_insert->next = head;
                head = to_insert;
                continue;
            }
                
            r = head;
            bool found = false;
            while (r->next != r2) {
                if (r2->val < r->next->val) {
                    to_insert = r2;
                    //delete the node
                    r1->next = r2->next;
                    r2 = r1->next;
                    //insert the node
                    to_insert->next = r->next;
                    r->next = to_insert;
                    found = true;
                    break;
                }
                r = r->next;
            }
            if (!found) {
                r1 = r1->next;
                r2 = r2->next;
            }
        }
        return head;
    }
};
