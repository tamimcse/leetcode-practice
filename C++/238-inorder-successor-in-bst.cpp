/*
https://leetcode.com/problems/inorder-successor-in-bst/
*/
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *res, *r;
        
        if (root == p) {
            if (root->right == NULL)
                return NULL;
            res = p->right;
            while (res && res->left) {
                res = res->left;
            }
            return res;
        }
        
        r = root->left;
        while (r && r->right)
            r = r->right;
        if (r == p)
            return root;
        
        r = root->right;
        while (r && r->right)
            r = r->right;
        if (r == p)
            return NULL;
        
        if (root->left) {
            res = inorderSuccessor (root->left, p);
            if (res)
                return res;
        }
        if (root->right) {
            res = inorderSuccessor (root->right, p);
            if (res)
                return res;
        }
        return NULL;
    }
};
