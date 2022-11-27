/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
*/
class Solution {
public:
    Node* connect(Node* root) {
        queue<pair<Node*, int>> q;
        pair<Node*, int> cur;
        Node *prev = NULL;
        int level = -1;
        
        if (!root)
            return root;
        
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (cur.second != level) {
                level = cur.second;
                prev = cur.first;
            } else {
                prev->next = cur.first;
                prev = cur.first;
            }
            if (cur.first->left)
                q.push(make_pair(cur.first->left, cur.second + 1));
            if (cur.first->right)
                q.push(make_pair(cur.first->right, cur.second + 1));
        }
        return root;
    }
};
