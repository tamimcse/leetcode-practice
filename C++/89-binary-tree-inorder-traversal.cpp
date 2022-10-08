/*
https://leetcode.com/problems/binary-tree-inorder-traversal/

Do it without recursion.
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *cur;
        
        if (!root)
            return res;
        
        TreeNode *r = root;
        while (r) {
            s.push(r);
            r = r->left;
        }
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            res.push_back(cur->val);
            r = cur->right;
            while (r) {
                s.push(r);
                r = r->left;
            }
        }
        return res;
    }
};
