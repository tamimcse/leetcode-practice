/*
https://leetcode.com/problems/binary-tree-maximum-path-sum/
*/
class Solution {
    int maxPathSum(TreeNode* root, int &res) {
        int left = INT_MIN, right = INT_MIN, ret;

        if (root->left == NULL && root->right == NULL) {
            res = max (res, root->val);
            return root->val;
        }

        if (root->left) {
            left = maxPathSum (root->left, res);
        }

        if (root->right) {
            right = maxPathSum (root->right, res);
        }

        res = max (res, root->val);
        res = max (res, root->val + (left == INT_MIN ? 0 : left));
        res = max (res, root->val + (right == INT_MIN ? 0 : right));
        res = max (res, root->val + (left == INT_MIN ? 0 : left) +
                                    (right == INT_MIN ? 0 : right));
        return max (root->val, max (left, right) + root->val);    
    }

public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;

        maxPathSum(root, res);
        return res;
    }
};
