/*
https://leetcode.com/problems/palindrome-linked-list/

Solve it at O(1) space and without recursion (recursion is not O(1) anyway)
*/
class Solution {
    ListNode* reverse(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode *prev = head, *r1 = head->next, *tmp;
        head->next = nullptr;
        while (r1) {
            tmp = r1->next;
            r1->next = prev;
            prev = r1;
            r1 = tmp;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head;
        
        if (head == nullptr)
            return false;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }
        
        fast = head;
        slow = reverse(slow);
        while (slow) {
            if (fast->val != slow->val)
                return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};
