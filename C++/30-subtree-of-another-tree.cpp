/*
https://leetcode.com/problems/subtree-of-another-tree/
*/
class Solution {
    bool is_equal(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr)
            return true;
        if (root == nullptr || subRoot == nullptr)
            return false;
        return root->val == subRoot->val && is_equal(root->left, subRoot->left) &&
                                            is_equal(root->right, subRoot->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool res;
        if (root == nullptr || subRoot == nullptr)
            return false;
            
        if (root->val == subRoot->val) {
            res = is_equal (root, subRoot);
            if (res)
                return res;
        }
            
        res = isSubtree (root->left, subRoot);
        if (res)    
            return res;
        return isSubtree (root->right, subRoot);
    }
};
