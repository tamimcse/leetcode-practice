/*
https://leetcode.com/problems/binary-tree-preorder-traversal/

Do it without recursion
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode *cur;
        
        if (!root)
            return res;
        s.push(root);
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            res.push_back(cur->val);
            if (cur->right)
                s.push(cur->right);
            if (cur->left)
                s.push(cur->left);
        }
        return res;
    }
};
