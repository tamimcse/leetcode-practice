/*
https://leetcode.com/problems/flip-equivalent-binary-trees/
*/
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2)
            return true;
        if ((!root1 && root2) || (root1 && !root2))
            return false;
        if (root1->val != root2->val)
            return false;
        
        int num_child1 = 0, num_child2 = 0;
        if (root1->left)
            num_child1++;
        if (root1->right)
            num_child1++;
        if (root2->left)
            num_child2++;
        if (root2->right)
            num_child2++;
        
        if (num_child1 != num_child2)
            return false;
        
        if (root1->left == NULL && root1->right == NULL &&
           root2->left == NULL && root2->right == NULL)
            return true;
        bool ret1 = flipEquiv(root1->left, root2->left);
        bool ret2 = flipEquiv(root1->right, root2->right);
        
        if (ret1 && ret2)
            return true;
        
        ret1 = flipEquiv(root1->left, root2->right);
        ret2 = flipEquiv(root1->right, root2->left);
        return ret1 && ret2;
    }
};
