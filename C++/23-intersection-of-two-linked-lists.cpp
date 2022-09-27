/*
https://leetcode.com/problems/intersection-of-two-linked-lists/

Solve it with and without extra space. 
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode *, bool> node_list;
        ListNode *r = headA;
        while (r) {
            node_list[r] = true;
            r = r->next;
        }
        
        r = headB;
        while (r) {
            auto it = node_list.find (r);
            if (it != node_list.end())
                return r;
            r = r->next;
        }
        return nullptr;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a_len = 0, b_len = 0;
        ListNode *r = headA;
        while (r) {
            a_len++;
            r = r->next;
        }
        
        r = headB;
        while (r) {
            b_len++;
            r = r->next;
        }
        
        ListNode *r1 = headA, *r2 = headB;
        if (a_len >= b_len) {
            while (a_len > b_len) {
                r1 = r1->next;
                a_len--;
            }
        } else {
            while (b_len > a_len) {
                r2 = r2->next;
                b_len--;
            }
        }
        while (r1) {
            if (r1 == r2)
                return r1;
            r1 = r1->next;
            r2 = r2->next;
        }
        return nullptr;
    }
};
