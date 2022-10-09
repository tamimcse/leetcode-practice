/*
https://leetcode.com/problems/cousins-in-binary-tree/
*/
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        stack<pair<TreeNode*, int>> s;
        int x_depth = -1, y_depth = -2, cur_depth = 0;
        TreeNode *cur;
        
        if (!root)
            return false;
        s.push(make_pair(root, cur_depth));
        while (!s.empty()) {
            cur = s.top().first;
            cur_depth = s.top().second;
            s.pop();
            if (cur->val == x)
                x_depth = cur_depth;
            if (cur->val == y)
                y_depth = cur_depth;
    
            if (cur->right) {
                s.push(make_pair(cur->right, cur_depth + 1));
            }
            if (cur->left) {
                s.push(make_pair(cur->left, cur_depth + 1));
            }
            
            if (cur->left && cur->right) {
                if ((cur->left->val == x || cur->left->val == y) && 
                    (cur->right->val == x || cur->right->val == y))
                    return false;
            }
        }
        
        
        return x_depth == y_depth;
    }
};
