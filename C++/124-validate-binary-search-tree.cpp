/*
https://leetcode.com/problems/validate-binary-search-tree/

Implement both ways (find both ways)
*/
class Solution {
    bool isValidBST_inner(TreeNode* root, long min, long max) {
        if (!root)
            return true;
        if (root->left && root->left->val >= root->val)
            return false;
        if (root->right && root->right->val <= root->val)
            return false;
        
        if (root->val >= max || root->val <= min)
            return false;
        
        return isValidBST_inner(root->left, min, root->val) && 
               isValidBST_inner(root->right, root->val, max);        
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST_inner(root, (long)INT_MIN * 2, (long)INT_MAX * 2);
    }
};

class Solution {
    
    bool isValidBST_inner(TreeNode* root, TreeNode* &prev) {
        bool ret;
        
        if (!root)
            return true;
        ret = isValidBST_inner(root->left, prev);
        if (!ret)
            return false;
        if (prev && root->val <= prev->val)
            return false;
        prev = root;
        ret = isValidBST_inner(root->right, prev);
        if (!ret)
            return false;
        return true;
    }

public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return isValidBST_inner(root, prev);
    }
};
