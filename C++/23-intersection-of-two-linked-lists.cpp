/*
https://leetcode.com/problems/intersection-of-two-linked-lists/
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
