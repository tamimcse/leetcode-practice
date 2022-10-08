/*
https://leetcode.com/problems/binary-tree-postorder-traversal/

Do it both with and without recursion. Do it with recursion just to practice how to implement tree travarsal using recursion.
*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<int> left, right;
        
        if (!root)
            return res;
        left = postorderTraversal(root->left);
        right = postorderTraversal(root->right);
        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        res.push_back(root->val);
        return res;
    }
};
