/*
https://leetcode.com/problems/binary-tree-postorder-traversal/

Do it both with and without recursion. Do it with recursion just to practice how to implement tree travarsal using recursion.
*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<int> left, right;
        
        if (!root)
            return res;
        left = postorderTraversal(root->left);
        right = postorderTraversal(root->right);
        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        res.push_back(root->val);
        return res;
    }
};

class Solution {
public:
    //Note that postorder is same as DFS
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        unordered_map<TreeNode*, bool> visit;
        stack<TreeNode*> s;
        TreeNode *cur;
        
        if (!root)
            return res;
        
        s.push(root);
        while (!s.empty()) {
            cur = s.top();
            if (visit.find(cur) == visit.end()) {
                visit[cur] = true;
                if (cur->right)
                    s.push (cur->right);
                if (cur->left)
                    s.push (cur->left);
            } else {
                res.push_back(cur->val);
                s.pop();
            }
        }
        return res;
    }
};
