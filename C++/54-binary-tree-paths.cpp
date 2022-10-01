/*
https://leetcode.com/problems/binary-tree-paths/
*/
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        
        if (root == nullptr)
            return res;    
        
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(to_string (root->val));
            return res;
        }
        
        if (root->left) {
            vector<string> left = binaryTreePaths (root->left);
            for (auto &e : left ) {
                res.push_back(to_string (root->val) + "->" + e);
            }
        }
        
        if (root->right) {
            vector<string> right = binaryTreePaths (root->right);
            for (auto &e : right ) {
                res.push_back(to_string (root->val) + "->" + e);
            }
        }
        
        return res;
    }
};
