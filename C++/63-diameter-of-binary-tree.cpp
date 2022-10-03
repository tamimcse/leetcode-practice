/*
https://leetcode.com/problems/diameter-of-binary-tree/
*/
class Solution {
    int diameter_inner (TreeNode* root, int &diameter) {
        int left = 0, right = 0;
        
        if (root->left) {
            left = diameter_inner (root->left, diameter) + 1;    
        }
        
        if (root->right) {
            right = diameter_inner (root->right, diameter) + 1;    
        }
        
        diameter = max (left + right, diameter);
        return max (left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int diameter = 0;
        diameter_inner (root, diameter);
        return diameter;
    }
};
