/*
https://leetcode.com/problems/n-ary-tree-preorder-traversal/

Recursive solution is trivial. Implement it using iterative manner
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> s;
        vector<int> res;
        Node *cur;
        
        if (!root)
            return res;
        
        s.push(root);
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            res.push_back(cur->val);
            int n = cur->children.size();
            for (int i = n - 1; i >= 0; i--) {
                s.push(cur->children[i]);
            }
        }
        return res;
    }
};
