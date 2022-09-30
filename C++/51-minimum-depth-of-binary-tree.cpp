/*
https://leetcode.com/problems/minimum-depth-of-binary-tree/
*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        
        int left = -1, right = -1, child_depth = -1;
        if (root->left)
            left = minDepth(root->left);
        
        if (root->right)
            right = minDepth(root->right);
        
        if (left > 0)
            child_depth = left;
        
        if (child_depth < 0)
            child_depth = right;
        else if (right > 0)
            child_depth = min (child_depth, right);

        return child_depth + 1;
    }
};
