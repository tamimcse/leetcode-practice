/*
https://leetcode.com/problems/add-two-numbers/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *r1 = l1, *r2 = l2, *res = NULL, *new_node, *tail;
        int num1, num2, sum, carry = 0;
        
        for (; r1 || r2 || carry;) {
            num1 = r1 ? r1->val : 0;
            num2 = r2 ? r2->val : 0;
            sum = (num1 + num2 + carry) % 10;
            carry = (num1 + num2 + carry) / 10;
            new_node = new ListNode(sum);
            if (!res) {
                res = new_node;
                tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
            
            if (r1)
                r1 = r1->next;
            if (r2)
                r2= r2->next;
        }
        return res;
    }
};
