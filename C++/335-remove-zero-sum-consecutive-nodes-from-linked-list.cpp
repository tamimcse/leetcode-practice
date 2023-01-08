/*
https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

Very interesting problem. The implementation has some complicacy. So, try to implemement again.
*/
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *r, *to_delete;

        while (head) {
            while (head && head->val == 0)
                head = head->next;
            r = head;
            int prefixSum = 0;
            unordered_map<int, ListNode*> hash;
            bool found = false;
            while (r) {
                prefixSum += r->val;
                if (hash.find(prefixSum) != hash.end() || prefixSum == 0) {
                    to_delete = hash[prefixSum];
                    if (prefixSum == 0) {
                        head = r->next;
                    } else if (to_delete == head) {
                        head->next = r->next;
                    } else {
                        to_delete->next = r->next;
                    }
                    found = true;
                    break;
                } else {
                    hash[prefixSum] = r;
                    r = r->next;
                }
            }
            if (!found)
                return head;
        }
        return head;
    }
};
