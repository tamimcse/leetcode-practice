/*
https://leetcode.com/problems/merge-k-sorted-lists/
*/
struct Cmp {
    bool operator()(ListNode *n1, ListNode *n2) {
        return n1->val > n2->val;
    }    
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
        ListNode *head = NULL, *n, *r;
        
        for (auto &e : lists) {
            if (e)
                pq.push(e);
         }
        
        while (!pq.empty()) {
            n = pq.top();
            pq.pop();
            if(n->next)
                pq.push(n->next);
            if (!head) {
                head = n;
                r = n;
            } else {
                r->next = n;
                r = r->next;
            }
        }
        return head;
    }
};
