/*
https://leetcode.com/problems/binary-tree-level-order-traversal/
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> q;
        pair<TreeNode*, int> cur;
        vector<int> tmp;
        
        if (!root)
            return res;
        
        int last_level = 0;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (cur.second != last_level) {
                res.push_back(tmp);
                tmp.clear();
                last_level = cur.second;
            }
            tmp.push_back(cur.first->val);
            if (cur.first->left) {
                q.push(make_pair(cur.first->left, cur.second + 1));
            }
            if (cur.first->right) {
                q.push(make_pair(cur.first->right, cur.second + 1));
            }            
        }
        if (tmp.size())
            res.push_back(tmp);
        return res;
    }
};
