/*
https://leetcode.com/problems/add-two-numbers-ii/
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1, s2;
        ListNode *head = NULL;

        while (l1) {
            s1.push(l1);
            l1 = l1->next;
        }

        while (l2) {
            s2.push(l2);
            l2 = l2->next;
        }

        int sum = 0, carry = 0, num1, num2, digit;

        while (!s1.empty() || !s2.empty() || carry) {
            num1 = 0;
            num2 = 0;
            if (!s1.empty()) {
                num1 = s1.top()->val;
                s1.pop();
            }
            if (!s2.empty()) {
                num2 = s2.top()->val;
                s2.pop();
            }

            sum = num1 + num2 + carry;
            digit = sum % 10;
            carry = sum / 10;

            head = new ListNode(digit, head);
        }
        return head;
    }
};
