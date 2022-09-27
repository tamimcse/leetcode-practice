/*
https://leetcode.com/problems/symmetric-tree/

Implement both recursive and iterative ways
*/
class Solution {
    bool isSymmetric_inner(TreeNode* r1, TreeNode* r2) {
        if ((r1 && !r2) || (!r1 && r2))
            return false;
        if (!r1 && !r2)
            return true;
        if (r1->val != r2->val)
            return false;
        bool res1 = isSymmetric_inner(r1->left, r2->right);
        bool res2 = isSymmetric_inner(r1->right, r2->left);
        return res1 && res2;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return isSymmetric_inner (root->left, root->right);
    }
};
