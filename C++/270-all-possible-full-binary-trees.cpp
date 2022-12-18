/*
https://leetcode.com/problems/all-possible-full-binary-trees/
*/
class Solution {

public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> res;

        if (n % 2 == 0)
            return res;

        if (n == 1) {
            TreeNode *root = new TreeNode();
            res.push_back(root);
            return res;    
        }

        for (int i = 1; i < n - 1; i += 2) {
            vector<TreeNode*> leftSubtrees = allPossibleFBT(i);
            vector<TreeNode*> rightSubtrees = allPossibleFBT(n - 1 - i);
            for (auto t1 : leftSubtrees) {
                for (auto t2 : rightSubtrees) {
                    TreeNode *root = new TreeNode();
                    root->left = t1;
                    root->right = t2;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
