/*
https://leetcode.com/problems/path-sum/
*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr)
            return root->val == targetSum;
        if (root->left) {
            bool res = hasPathSum (root->left, targetSum - root->val);
            if (res)
                return true;
        }
        
        return  hasPathSum (root->right, targetSum - root->val);
            
    }
};
