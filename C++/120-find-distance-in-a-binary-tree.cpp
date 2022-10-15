/*
https://leetcode.com/problems/find-distance-in-a-binary-tree/
*/
class Solution {
    TreeNode* LCA(TreeNode* root, int p, int q) {
        if (!root)
            return root;
        if (root->val == p || root->val == q)
            return root;
        TreeNode *left = LCA(root->left, p, q);
        TreeNode *right = LCA(root->right, p, q);
        if (left && right)
            return root;
        if (left)
            return left;
        return right;
    }
    
    int distance(TreeNode* root, int p, bool &found) {
        if (!root)
            return 0;
        if (root->val == p) {
            found = true;
            return 0;
        }
        
        int dis;
        
        dis = distance (root->left, p, found);
        if (found)
            return dis + 1;
        
        dis = distance (root->right, p, found);
        if (found)
            return dis + 1;
        else
            return 0;
    }
public:
    int findDistance(TreeNode* root, int p, int q) {
        TreeNode *lca = LCA (root, p, q);

        if (p == q)
            return 0;
        bool b1 = false, b2 = false;
        return distance (lca, p, b1) + distance (lca, q, b2);
    }
};
