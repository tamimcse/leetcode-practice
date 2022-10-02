/*
https://leetcode.com/problems/merge-two-binary-trees/
*/
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr)
            return root2;
        if (root2 == nullptr)
            return root1;
        root1->val += root2->val;
        
        if (root1->left && root2->left) {
            mergeTrees (root1->left, root2->left);
        } else {
            if (root2->left) {
                root1->left = root2->left;    
            }
        }
        
        if (root1->right != nullptr && root2->right != nullptr) {
            mergeTrees (root1->right, root2->right);
        } else {
            if (root2->right) {
                root1->right = root2->right;
            }
        }
        
        return root1;
    }
};
