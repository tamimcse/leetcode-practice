/*
https://leetcode.com/problems/kth-smallest-element-in-a-bst/
*/
class Solution {
    void kthSmallest_inner(TreeNode* root, int k, int &count, TreeNode* &res) {
        if (res)
            return;
        
        if (root->left)
            kthSmallest_inner(root->left, k, count, res);
        
        count++;
        if (count == k) {
            res = root;
            return;
        }
        
        if (root->right)
            kthSmallest_inner(root->right, k, count, res);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        TreeNode *res = nullptr;
        
        kthSmallest_inner(root, k, count, res);
        return  res->val;
    }
};
