/*
https://leetcode.com/problems/balanced-binary-tree/
*/
class Solution {
    int height(TreeNode* root, bool &res) {
        int left, right;
        if (root == nullptr)
            return 0;
        left = root->left ? height(root->left, res) + 1 : 0;
        right = root->right ? height(root->right, res) + 1 : 0;
        if (abs (left - right) > 1)
            res = false;
        return max (left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        bool res = true;
        height(root, res);
        return res;
    }
};
