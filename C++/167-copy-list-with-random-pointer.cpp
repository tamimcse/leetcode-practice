/*
https://leetcode.com/problems/copy-list-with-random-pointer/

Very similar to copy tree with random pointer. If you did that, you can skip this
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *new_head = NULL, *r1 = head, *new_node, *r2;
        unordered_map<Node*, Node*> hash;
        
        while (r1) {
            new_node = new Node(r1->val);
            hash[r1] = new_node;
            if (!new_head) {
                new_head = new_node;
                r2 = new_node;
            } else {
                r2->next = new_node;
                r2 = r2->next;
            }
            r1 = r1->next;
        }
        
        r1 = head;
        r2 = new_head;
        while (r1) {
            if (r1->random)
                r2->random = hash[r1->random];
            r1 = r1->next;
            r2 = r2->next;
        }
        return new_head;
    }
};
