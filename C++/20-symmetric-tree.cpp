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

class Solution {

public:
    bool isSymmetric(TreeNode* root) {
        TreeNode *tmp1, *tmp2;
        if (root == nullptr)
            return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            tmp1 = q.front();
            q.pop();
            tmp2 = q.front();
            q.pop();
            if ((tmp1 && !tmp2) || (!tmp1 && tmp2))
                return false;
            if (!tmp1 && !tmp2)
                continue;
            if (tmp1->val != tmp2->val)
                return false;
            q.push(tmp1->left);
            q.push(tmp2->right);
            q.push(tmp1->right);
            q.push(tmp2->left);
        }
        return true;
    }
};
