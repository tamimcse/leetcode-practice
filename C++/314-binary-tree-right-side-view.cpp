/*
https://leetcode.com/problems/binary-tree-right-side-view/
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        vector<int> res;
        int level;
        TreeNode* n;
        int prev_level = -1;
        
        if (!root)
            return res;
        
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            n = q.front().first;
            level = q.front().second;
            q.pop();
            if (level != prev_level) {
                res.push_back(n->val);
                prev_level = level;
            }
            if (n->right)
                q.push(make_pair(n->right, level + 1));
            if (n->left)
                q.push(make_pair(n->left, level + 1));
        }
        return res;
    }
};
