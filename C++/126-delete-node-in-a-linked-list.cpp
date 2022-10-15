/*
https://leetcode.com/problems/delete-node-in-a-linked-list/
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        while (node->next) {
            node->val = node->next->val;
            if (node->next->next == nullptr)
                node->next = nullptr;
            else
                node = node->next;
        }
    }
};
