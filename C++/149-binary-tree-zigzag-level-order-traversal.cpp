/*
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int turn = 0;
        stack<TreeNode*> s1, s2;
        TreeNode *cur;
        
        if (!root)
            return res;
        
        s1.push(root);
        while (!s1.empty() || !s2.empty()) {
            vector<int> tmp;
            if (!turn) {
                while (!s1.empty()) {
                    cur = s1.top();
                    s1.pop();
                    tmp.push_back(cur->val);
                    if (cur->left)
                        s2.push(cur->left);
                    if (cur->right)
                        s2.push(cur->right);                    
                }
            } else {
                while (!s2.empty()) {
                    cur = s2.top();
                    s2.pop();
                    tmp.push_back(cur->val);
                    if (cur->right)
                        s1.push(cur->right);
                    if (cur->left)
                        s1.push(cur->left);                    
                }
            }
            turn = turn ^ 1;
            res.push_back(tmp);
        }
        return res;
    }
};
